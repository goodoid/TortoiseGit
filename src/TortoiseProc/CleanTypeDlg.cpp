// CleanTypeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TortoiseProc.h"
#include "CleanTypeDlg.h"
#include "git.h"

// CCleanTypeDlg dialog

IMPLEMENT_DYNAMIC(CCleanTypeDlg, CResizableStandAloneDialog)

CCleanTypeDlg::CCleanTypeDlg(CWnd* pParent /*=NULL*/)
	: CResizableStandAloneDialog(CCleanTypeDlg::IDD, pParent)
	
{
	CString WorkingDir=g_Git.m_CurrentDir;
	WorkingDir.Replace(_T(':'),_T('_'));
	this->m_regDir  = CRegDWORD( CString(_T("Software\\TortoiseGit\\History\\CleanDir\\"))+WorkingDir, 1);
	this->m_regType = CRegDWORD( CString(_T("Software\\TortoiseGit\\History\\CleanType\\"))+WorkingDir, 0);

	this->m_bDir = this->m_regDir;
	this->m_CleanType = this->m_regType;
}

CCleanTypeDlg::~CCleanTypeDlg()
{
}

void CCleanTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_DIR, m_bDir);
	DDX_Radio(pDX, IDC_RADIO_CLEAN_ALL,m_CleanType);
}


BEGIN_MESSAGE_MAP(CCleanTypeDlg, CResizableStandAloneDialog)
END_MESSAGE_MAP()


// CCleanTypeDlg message handlers

BOOL CCleanTypeDlg::OnInitDialog()
{
	CResizableStandAloneDialog::OnInitDialog();

	this->AddAnchor(IDOK,BOTTOM_RIGHT);
	this->AddAnchor(IDCANCEL,BOTTOM_RIGHT);
	this->AddAnchor(IDHELP,BOTTOM_RIGHT);

	this->AddAnchor(IDC_GROUP_CLEAN_TYPE,TOP_LEFT,TOP_RIGHT);

	this->AddOthersToAnchor();
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CCleanTypeDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	this->UpdateData();
	
	this->m_regDir = this->m_bDir;
	this->m_regType = this->m_CleanType ;

	CResizableStandAloneDialog::OnOK();
}