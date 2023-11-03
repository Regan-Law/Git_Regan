// tcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "tc.h"
#include "tcDlg.h"
#include "CSocket.h"
#include "Msg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CTcDlg dialog

CTcDlg::CTcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTcDlg)
	m_strCName = _T("");
	m_strMsg = _T("");
	m_strSName = _T("");
	m_nPort = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pSocket=NULL;
	m_pFile=NULL;
	m_pArchiveIn=NULL;
	m_pArchiveOut=NULL;
}

void CTcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTcDlg)
	DDX_Control(pDX, IDC_BUTTON_SEND, m_Send);
	DDX_Control(pDX, IDC_BUTTON_CONN, m_btnConn);
	DDX_Control(pDX, IDC_BUTTON_CLOSE, m_btnClose);
	DDX_Control(pDX, IDC_LIST_MSG, m_listMsg);
	DDX_Text(pDX, IDC_EDIT_CNAME, m_strCName);
	DDX_Text(pDX, IDC_EDIT_MSG, m_strMsg);
	DDX_Text(pDX, IDC_EDIT_SNAME, m_strSName);
	DDX_Text(pDX, IDC_EDIT_PORT, m_nPort);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTcDlg, CDialog)
	//{{AFX_MSG_MAP(CTcDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CTcDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_CONN, &CTcDlg::OnBnClickedButtonConn)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CTcDlg::OnBnClickedButtonSend)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTcDlg message handlers

BOOL CTcDlg::OnInitDialog()
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
	m_strCName = "客户 1";
	m_nPort = 8000;
	m_strSName = _T("localhost");
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CLOSE)->EnableWindow(FALSE);
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTcDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
HCURSOR CTcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


//当单击“连接“按钮时，向服务器请求连接
void CTcDlg::OnBnClickedButtonConn()
{
	m_pSocket = new CCSocket(this); //创建套接字对象
	if (!m_pSocket->Create())       //创建套接字对象的底层套接字
	{
		delete m_pSocket;    //错误处理
		m_pSocket = NULL;
		AfxMessageBox("套接字创建错误！");
		return;
	}
	UpdateData(TRUE);
	if (!m_pSocket->Connect(m_strSName, m_nPort))
	{
		delete m_pSocket;    //错误处理
		m_pSocket = NULL;
		AfxMessageBox("无法连接服务器错误！");
		return;
	}
	//创建CSocketFile类对象
	m_pFile = new CSocketFile(m_pSocket);
	//分别创建用于输入和用于输出的CArchive类对象
	m_pArchiveIn = new CArchive(m_pFile, CArchive::load);
	m_pArchiveOut = new CArchive(m_pFile, CArchive::store);
	//调用SendMsg函数，向服务器发送消息，表明该客户进入聊天室
	UpdateData(TRUE);
	CString  strTemp;
	strTemp = m_strCName + ":进入聊天室";
	SendMsg(strTemp, FALSE);
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_LIST_MSG)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_CLOSE)->EnableWindow(TRUE);

	GetDlgItem(IDC_EDIT_CNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_SNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_PORT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CONN)->EnableWindow(FALSE);
}


//当单击“发送“按钮时，向服务器发送信息
//并将发送的消息显示于列表框，注意，实际的发送是由SendMsg函数完成的
void CTcDlg::OnBnClickedButtonSend()
{
	UpdateData(TRUE);       //取回用户输入的信息
	if (!m_strMsg.IsEmpty())
	{
		this->SendMsg(m_strCName + ":" + m_strMsg, FALSE);
		//m_listMsg.AddString(m_strMsg);
		m_strMsg = _T("");
		UpdateData(FALSE);  //更新用户界面，将用户输入的消息删除。
	}
}

//当单击“断开“按钮时，作客户退出聊天室的相关处理
void CTcDlg::OnBnClickedButtonClose()
{
	CString strTemp;
	strTemp = m_strCName + ":离开聊天室！";
	SendMsg(strTemp, TRUE);

	delete m_pArchiveOut;  //删除用于输出的CArchive对象
	m_pArchiveOut = NULL;
	delete m_pArchiveIn;   //删除用于输入的CArchive对象
	m_pArchiveIn = NULL;
	delete m_pFile;	       //删除CSOcketFile对象
	m_pFile = NULL;
	m_pSocket->Close();    //关闭套接字对象 
	delete m_pSocket;	   //删除CCSOcket对象  
	m_pSocket = NULL;

	//清除列表框
	while (m_listMsg.GetCount() != 0)
		m_listMsg.DeleteString(0);
	GetDlgItem(IDC_EDIT_MSG)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CLOSE)->EnableWindow(FALSE);

	GetDlgItem(IDC_EDIT_CNAME)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_SNAME)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_PORT)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_CONN)->EnableWindow(TRUE);
}

//实际执行发送的函数
void CTcDlg::SendMsg(CString &strText,bool st)
{
	if (m_pArchiveOut!=NULL)
	{
		CMsg msg;  //创建一个消息对象
		//将要发送的信息文本赋给消息对象的成员变量
		msg.m_strBuf = strText;
		msg.m_bClose = st;

		//调用消息对象的系列化函数，发送消息
		msg.Serialize(*m_pArchiveOut);
		//将CArchive对象中数据强制存储到CSocketFile对象中
		m_pArchiveOut->Flush();
	}
}




//当套接字收到FD_READ消息时，它的OnReceive函数调用此函数
void CTcDlg::OnReceive()
{
	do
	{
		ReceiveMsg();    //调用ReceiveMsg函数实际接收消息
		if (m_pSocket==NULL)  return;
	}  while (!m_pArchiveIn->IsBufferEmpty());
}

//实际接收消息的函数
void CTcDlg::ReceiveMsg()
{
	CMsg msg;   //创建消息对象
	TRY
	{
		//调用消息对象的序列化函数，接收消息
		msg.Serialize(*m_pArchiveIn);
		m_listMsg.AddString(msg.m_strBuf);  //将消息显示与列表框
	}
	CATCH(CFileException,e)    //错误处理
	{
		//显示处理服务器关闭的消息
		CString strTemp;
		strTemp="服务器重置连接！连接关闭！";
		m_listMsg.AddString(strTemp);
		msg.m_bClose=TRUE;
		m_pArchiveOut->Abort();
		//删除相应的对象
		delete m_pArchiveIn;
		m_pArchiveIn=NULL;
		delete m_pArchiveOut;
		m_pArchiveOut=NULL;
		delete m_pFile;
		m_pFile=NULL;
		delete m_pSocket;
		m_pSocket=NULL;	
	}
	END_CATCH
}

//在CTcDlg类终止运行时进行的后续处理
void CTcDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	//m_bAutoChat=FALSE;
	if ((m_pSocket!=NULL)&&(m_pFile!=NULL)&&(m_pArchiveOut!=NULL))
	{
		//发送客户离开聊天室的消息
		CMsg msg;
		CString strTemp;
		strTemp="DDDD:离开聊天室！";
		msg.m_bClose=TRUE;
		msg.m_strBuf=m_strCName+strTemp;
		msg.Serialize(*m_pArchiveOut);
		m_pArchiveOut->Flush();
	}
	delete m_pArchiveOut;    //删除CArchive对象
	m_pArchiveOut=NULL;
	delete m_pArchiveIn;	//删除CArchive对象
	m_pArchiveIn=NULL;
	delete m_pFile;	        //删除CSOcketFile对象
	m_pFile=NULL;
	if (m_pSocket!=NULL)
	{
		BYTE Buffer[50];
		m_pSocket->ShutDown();
		while (m_pSocket->Receive(Buffer,50)>0);
	}
	delete m_pSocket;
	m_pSocket=NULL;
}