//------------------------------------------------------------------------------------------
#include <afxwin.h>			//MFC core and standard components
#include "resource.h"		//main symbols
//------------------------------------------------------------------------------------------
//Globals
CEdit * pINPUT;
CEdit * pOUTPUT;
CButton * pSTART;
CButton * pQUIT;

class GAME_FORM : public CDialog
{
public:
	GAME_FORM(CWnd* pParent = NULL) : CDialog(GAME_FORM::IDD, pParent)
	{

	}
	enum {IDD = IDD_INTERFACE1};
protected:
	virtual void DoDataExchange(CDataExchange* pDX) 
	{
		CDialog::DoDataExchange(pDX);
	}
	virtual BOOL OnInitDialog()
	{
		CDialog::OnInitDialog();
		pINPUT = (CEdit*)GetDlgItem(IDC_INPUT);
		pOUTPUT = (CEdit*)GetDlgItem(IDC_Output);
		pSTART = (CButton*)GetDlgItem(IDC_START);
		
		pINPUT->SetWindowText("Type Here!");
		pOUTPUT->SetWindowText("Click \"Start\" to begin!");
		return true;
	}
public:
//--------------------------------------------------------------------------------------------
	afx_msg void OnBNClickedStart()
	{
		STARTBUTTON();
	}
//-------------------------------------------------------------------------------------------

	void STARTBUTTON()
	{
		MessageBox("BYE!");
		pSTART->EnableWindow(false);
	}
	DECLARE_MESSAGE_MAP()
};
//-------------------------------------------------------------------------------------------
class TheGame : public CWinApp
{
public:
	TheGame() {}
	virtual BOOL InitInstance()
	{
		CWinApp::InitInstance();
		SetRegistryKey(_T("Hills of Darkness"));
		GAME_FORM dlg;
		m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		return FALSE;
	}	//close function
};
//-------------------------------------------------------------------------------------------
//Need a Message Map Macro for both CDialog and CWinApp
BEGIN_MESSAGE_MAP(GAME_FORM, CDialog)
	ON_COMMAND(IDC_START, OnBNClickedStart)
END_MESSAGE_MAP()
//-------------------------------------------------------------------------------------------
TheGame theApp;	//Start the Application