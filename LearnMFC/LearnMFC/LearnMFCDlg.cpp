
// LearnMFCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "LearnMFC.h"
#include "LearnMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLearnMFCDlg dialog



CLearnMFCDlg::CLearnMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LEARNMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLearnMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLearnMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DRAW, &CLearnMFCDlg::OnBnClickedButtonDraw)
END_MESSAGE_MAP()


// CLearnMFCDlg message handlers

BOOL CLearnMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLearnMFCDlg::DrawRect()
{
	CClientDC MyDC(this);	//Access the currect device context
	MyDC.Rectangle(0, 0, 100, 100);	//Draw a rectangle - bordered black, filled white
	MyDC.MoveTo(0, 0);	//Moves to start position of drawing the line
	MyDC.LineTo(100, 100);	//Draws a line from the current position to the start position
	return;
}

void CLearnMFCDlg::CustomizeDrawRect()
{
	CClientDC MyDC(this);	//Accessing the current device context
	CPen* redPen, * OldPen;	//Pointer to CPen as custompen and oldpen
	redPen = new CPen;	//Instatiate the pen
	redPen->CreatePen(PS_SOLID, 3, RGB(255, 0, 0));	//Create a solid pen of width 1 and red in color

	CBrush* blueBrush, * OldBrush;	//Pointer to CBrush as custombrush and oldbrush
	blueBrush = new CBrush;	//Instatiate the brush
	blueBrush->CreateSolidBrush(RGB(0, 0, 255));	//Create a solid brush 

	OldPen = MyDC.SelectObject(redPen);	//Select the red pen
	OldBrush = MyDC.SelectObject(blueBrush);	//Select the blue brush

	MyDC.Rectangle(100, 100, 200, 200);	//Draw a rectangle
	redPen = MyDC.SelectObject(OldPen);	//Optionally restore the old pen
	blueBrush = MyDC.SelectObject(OldBrush);	//Optionally restore the old brush
}

void CLearnMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLearnMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLearnMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLearnMFCDlg::OnBnClickedButtonDraw()
{
	// TODO: Add your control notification handler code here
	//DrawRect();	//Draw rectangle using build in properties
	//CustomizeDrawRect();	//Draw rectangle using customize properties
	OnBitmap();	//Draw Bitmap
}

void CLearnMFCDlg::OnBitmap()
{
	CBitmap bmp;
	BITMAP bm;
	CClientDC d(this);
	CDC memdc;

	bmp.LoadBitmap(IDB_BITMAP1);
	bmp.GetObject(sizeof(BITMAP), &bm);
	memdc.CreateCompatibleDC(&d);
	memdc.SelectObject(&bmp);
	TRACE("%d %d\n", bm.bmWidth, bm.bmHeight);
	d.BitBlt(0, 0,100, 100, &memdc, 0, 0, SRCCOPY);
}
