// tcDlg.h : header file
//

#if !defined(AFX_TCDLG_H__E2C4D326_FDB8_11D9_BC43_000795DF7F99__INCLUDED_)
#define AFX_TCDLG_H__E2C4D326_FDB8_11D9_BC43_000795DF7F99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTcDlg dialog

#include  "CSocket.h"

class CTcDlg : public CDialog
{
// Construction
public:

	CTcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTcDlg)
	enum { IDD = IDD_TC_DIALOG };
	CButton	m_Send;
	CButton	m_btnConn;
	CButton	m_btnClose;
	CListBox	m_listMsg;
	CString	m_strCName;
	CString	m_strMsg;
	CString	m_strSName;
	UINT	m_nPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

//Attribuie
	CCSocket*  m_pSocket;    //套接字对象指针
	CSocketFile* m_pFile;    //CSocketFile对象指针
	CArchive* m_pArchiveIn;  //用于输入的CArchive对象指针
	CArchive* m_pArchiveOut; //用于输出的CArchive对象指针

//Operations
public:
	void OnReceive();               //接收信息
	void ReceiveMsg();              //接收服务器发来的信息
	void SendMsg(CString& strText,bool st); //向服务器发送信息
	afx_msg void OnBnClickedButtonClose();
	afx_msg void OnBnClickedButtonConn();
	afx_msg void OnBnClickedButtonSend();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCDLG_H__E2C4D326_FDB8_11D9_BC43_000795DF7F99__INCLUDED_)
