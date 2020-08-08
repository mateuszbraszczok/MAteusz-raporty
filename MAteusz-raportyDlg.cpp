
// MAteusz-raportyDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MAteusz-raporty.h"
#include "MAteusz-raportyDlg.h"
#include "afxdialogex.h"
#include <string>

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


// CMAteuszraportyDlg dialog



CMAteuszraportyDlg::CMAteuszraportyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MATEUSZRAPORTY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMAteuszraportyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMAteuszraportyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMAteuszraportyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMAteuszraportyDlg message handlers

BOOL CMAteuszraportyDlg::OnInitDialog()
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
	

	// TODO: Dodaj tutaj dodatkowe inicjowanie

	WritePrivateProfileString(_T("Section 2"), _T("Key 2"), _T("ala"), _T(".\\test.ini"));
	WritePrivateProfileString(_T("Section 2"), _T("Key 23"), _T("ma"), _T(".\\test.ini"));
	//LPCTSTR path = _T(".\\test.ini");
	//TCHAR protocolChar[32];
	//int a = GetPrivateProfileString(_T("Connection"), _T("Protocol"), _T(""), protocolChar, 32, path);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMAteuszraportyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMAteuszraportyDlg::OnPaint()
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
HCURSOR CMAteuszraportyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMAteuszraportyDlg::OnBnClickedButton1()
{
	CString cs("Hello");
	// Convert a TCHAR string to a LPCSTR
	CT2CA pszConvertedAnsiString(cs);
	// construct a std::string using the LPCSTR input
	std::string strStd(pszConvertedAnsiString);
	CString ws(strStd.c_str());
	CString buf;
	GetDlgItemText(kkbut,buf);
	
	double xd = _wtof(buf);
	//IDC_STATIC2.clear();
	CString buf2( "hello");
	SetDlgItemText(kkbut, ws);
	//SetDlgItemText(kk2but, ws);



	LPCTSTR path = _T(".\\test.ini");
	TCHAR protocolChar[32];
	DWORD a = GetPrivateProfileString(_T("Section 2"), _T("Key 2"), _T(""), protocolChar, 32, path);
	SetDlgItemText(kk2but, protocolChar);

	
}
