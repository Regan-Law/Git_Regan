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
	m_strCName = "�ͻ� 1";
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


//�����������ӡ���ťʱ�����������������
void CTcDlg::OnBnClickedButtonConn()
{
	m_pSocket = new CCSocket(this); //�����׽��ֶ���
	if (!m_pSocket->Create())       //�����׽��ֶ���ĵײ��׽���
	{
		delete m_pSocket;    //������
		m_pSocket = NULL;
		AfxMessageBox("�׽��ִ�������");
		return;
	}
	UpdateData(TRUE);
	if (!m_pSocket->Connect(m_strSName, m_nPort))
	{
		delete m_pSocket;    //������
		m_pSocket = NULL;
		AfxMessageBox("�޷����ӷ���������");
		return;
	}
	//����CSocketFile�����
	m_pFile = new CSocketFile(m_pSocket);
	//�ֱ𴴽�������������������CArchive�����
	m_pArchiveIn = new CArchive(m_pFile, CArchive::load);
	m_pArchiveOut = new CArchive(m_pFile, CArchive::store);
	//����SendMsg�������������������Ϣ�������ÿͻ�����������
	UpdateData(TRUE);
	CString  strTemp;
	strTemp = m_strCName + ":����������";
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


//�����������͡���ťʱ���������������Ϣ
//�������͵���Ϣ��ʾ���б��ע�⣬ʵ�ʵķ�������SendMsg������ɵ�
void CTcDlg::OnBnClickedButtonSend()
{
	UpdateData(TRUE);       //ȡ���û��������Ϣ
	if (!m_strMsg.IsEmpty())
	{
		this->SendMsg(m_strCName + ":" + m_strMsg, FALSE);
		//m_listMsg.AddString(m_strMsg);
		m_strMsg = _T("");
		UpdateData(FALSE);  //�����û����棬���û��������Ϣɾ����
	}
}

//���������Ͽ�����ťʱ�����ͻ��˳������ҵ���ش���
void CTcDlg::OnBnClickedButtonClose()
{
	CString strTemp;
	strTemp = m_strCName + ":�뿪�����ң�";
	SendMsg(strTemp, TRUE);

	delete m_pArchiveOut;  //ɾ�����������CArchive����
	m_pArchiveOut = NULL;
	delete m_pArchiveIn;   //ɾ�����������CArchive����
	m_pArchiveIn = NULL;
	delete m_pFile;	       //ɾ��CSOcketFile����
	m_pFile = NULL;
	m_pSocket->Close();    //�ر��׽��ֶ��� 
	delete m_pSocket;	   //ɾ��CCSOcket����  
	m_pSocket = NULL;

	//����б��
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

//ʵ��ִ�з��͵ĺ���
void CTcDlg::SendMsg(CString &strText,bool st)
{
	if (m_pArchiveOut!=NULL)
	{
		CMsg msg;  //����һ����Ϣ����
		//��Ҫ���͵���Ϣ�ı�������Ϣ����ĳ�Ա����
		msg.m_strBuf = strText;
		msg.m_bClose = st;

		//������Ϣ�����ϵ�л�������������Ϣ
		msg.Serialize(*m_pArchiveOut);
		//��CArchive����������ǿ�ƴ洢��CSocketFile������
		m_pArchiveOut->Flush();
	}
}




//���׽����յ�FD_READ��Ϣʱ������OnReceive�������ô˺���
void CTcDlg::OnReceive()
{
	do
	{
		ReceiveMsg();    //����ReceiveMsg����ʵ�ʽ�����Ϣ
		if (m_pSocket==NULL)  return;
	}  while (!m_pArchiveIn->IsBufferEmpty());
}

//ʵ�ʽ�����Ϣ�ĺ���
void CTcDlg::ReceiveMsg()
{
	CMsg msg;   //������Ϣ����
	TRY
	{
		//������Ϣ��������л�������������Ϣ
		msg.Serialize(*m_pArchiveIn);
		m_listMsg.AddString(msg.m_strBuf);  //����Ϣ��ʾ���б��
	}
	CATCH(CFileException,e)    //������
	{
		//��ʾ����������رյ���Ϣ
		CString strTemp;
		strTemp="�������������ӣ����ӹرգ�";
		m_listMsg.AddString(strTemp);
		msg.m_bClose=TRUE;
		m_pArchiveOut->Abort();
		//ɾ����Ӧ�Ķ���
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

//��CTcDlg����ֹ����ʱ���еĺ�������
void CTcDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	//m_bAutoChat=FALSE;
	if ((m_pSocket!=NULL)&&(m_pFile!=NULL)&&(m_pArchiveOut!=NULL))
	{
		//���Ϳͻ��뿪�����ҵ���Ϣ
		CMsg msg;
		CString strTemp;
		strTemp="DDDD:�뿪�����ң�";
		msg.m_bClose=TRUE;
		msg.m_strBuf=m_strCName+strTemp;
		msg.Serialize(*m_pArchiveOut);
		m_pArchiveOut->Flush();
	}
	delete m_pArchiveOut;    //ɾ��CArchive����
	m_pArchiveOut=NULL;
	delete m_pArchiveIn;	//ɾ��CArchive����
	m_pArchiveIn=NULL;
	delete m_pFile;	        //ɾ��CSOcketFile����
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