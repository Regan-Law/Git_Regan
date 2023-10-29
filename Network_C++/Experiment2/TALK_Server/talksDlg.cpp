// talksDlg.cpp : implementation file
//

#include "stdafx.h"
#include "talks.h"
#include "talksDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define SERV_PORT 10001
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// Dialog Data
		//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTalksDlg dialog

CTalksDlg::CTalksDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTalksDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTalksDlg)
	m_strServName = _T("");
	m_strMsg = _T("");
	m_nServPort = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTalksDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTalksDlg)
	DDX_Control(pDX, IDC_BUTTON_LISTEN, m_btnListen);
	DDX_Control(pDX, IDC_LIST_RECEIVED, m_listReceived);
	DDX_Control(pDX, IDC_LIST_SENT, m_listSent);
	DDX_Text(pDX, IDC_EDIT_SERVNAME, m_strServName);
	DDX_Text(pDX, IDC_EDIT_MSG, m_strMsg);
	DDX_Text(pDX, IDC_EDIT_SERVPORT, m_nServPort);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTalksDlg, CDialog)
	//{{AFX_MSG_MAP(CTalksDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LISTEN, OnButtonListen)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, OnButtonClose)
	ON_BN_CLICKED(IDOK, OnSendMsg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTalksDlg message handlers

BOOL CTalksDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	//initialize the control variables
	m_strServName = "127.0.0.1";//server name=localhost
	m_nServPort = SERV_PORT;
	UpdateData(FALSE);
	//set socket dialog pointers，
	m_sListenSocket.SetParent(this);
	m_sConnectSocket.SetParent(this);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTalksDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTalksDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTalksDlg::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}

void CTalksDlg::OnButtonListen()
{
	//retrive data from dialog
	UpdateData(TRUE);
	//disable the connection and type controls
	GetDlgItem(IDC_BUTTON_LISTEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SERVNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SERVPORT)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_SERVNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATIC_SERVPORT)->EnableWindow(FALSE);
	//server,create a socket bound to the port specified
	m_sListenSocket.Create(m_nServPort);
	//listen for connection request
	m_sListenSocket.Listen();
	GetDlgItem(IDC_BUTTON_CLOSE)->EnableWindow(TRUE);
}

void CTalksDlg::OnButtonClose()
{
	//call the OnClose function
	OnClose();
}

void CTalksDlg::OnSendMsg()
{
	int nLen;//length of message
	int nSent;//length of message been sent

	//retrieve data from dialog
	UpdateData(TRUE);
	//any message to be sent?
	if (!m_strMsg.IsEmpty())
	{
		//get length of the message
		nLen = m_strMsg.GetLength();
		//send the message
		nSent = m_sConnectSocket.Send(LPCTSTR(m_strMsg), nLen);
		//send successfully?
		if (nSent != SOCKET_ERROR)
		{
			//add the message to the sent list box
			m_listSent.AddString(m_strMsg);
			//update the dialog
			UpdateData(FALSE);
		}
		else
		{
			AfxMessageBox("信息发送错误！", MB_OK | MB_ICONSTOP);
		}
		//clear the current message
		m_strMsg.Empty();
		//update the dialog
		UpdateData(FALSE);
	}
}

void CTalksDlg::OnAccept()
{
	m_listReceived.AddString("服务器收到了OnAccept消息");
	//to server
	//accept the connection request
	m_sListenSocket.Accept(m_sConnectSocket);
	//enable the text and message controls
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDOK)->EnableWindow(TRUE);//botton send
	GetDlgItem(IDC_STATIC_MSG)->EnableWindow(TRUE);
}

void CTalksDlg::OnReceive()
{
	char* pBuf = new char[1025];
	int nBufSize = 1024;
	int nReceived;
	CString strReceived;
	m_listReceived.AddString("服务器收到了OnReceive消息");
	//receive the message
	nReceived = m_sConnectSocket.Receive(pBuf, nBufSize);
	//receive successfully?
	if (nReceived != SOCKET_ERROR)
	{
		//truncate the end of the message
		pBuf[nReceived] = NULL;
		//copy the message to a CString
		strReceived = pBuf;
		//add the message to the received list box
		m_listReceived.AddString(strReceived);
		//Update the dialog
		UpdateData(FALSE);
	}
	else
	{
		AfxMessageBox("信息接收错误！", MB_OK | MB_ICONSTOP);
	}
}

void CTalksDlg::OnConnect()
{
	//to client
	//enable the text and message controls
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDOK)->EnableWindow(TRUE);//botton send
	GetDlgItem(IDC_STATIC_MSG)->EnableWindow(TRUE);
	//close button ready,only to client
	GetDlgItem(IDC_BUTTON_CLOSE)->EnableWindow(TRUE);
	m_listReceived.AddString("服务器收到了onconnect消息");
}

void CTalksDlg::OnClose()
{
	m_listReceived.AddString("服务器收到了OnClose消息");
	//close the connected socket
	m_sConnectSocket.Close();
	//disable the message sending controls
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(FALSE);
	GetDlgItem(IDOK)->EnableWindow(FALSE);//botton send
	GetDlgItem(IDC_STATIC_MSG)->EnableWindow(FALSE);
	//begin YFQ add: to enable listen again
	m_sListenSocket.Close();
	GetDlgItem(IDC_BUTTON_LISTEN)->EnableWindow(TRUE);
	//end YFQ added
	GetDlgItem(IDC_BUTTON_CLOSE)->EnableWindow(FALSE);
	//clear the list boxes
	while (m_listSent.GetCount() != 0)
		m_listSent.DeleteString(0);
	while (m_listReceived.GetCount() != 0)
		m_listReceived.DeleteString(0);
}
