// talksDlg.h : header file
//

#if !defined(AFX_TALKSDLG_H__A13FF4B7_2D85_4211_81BC_2B11109251C0__INCLUDED_)
#define AFX_TALKSDLG_H__A13FF4B7_2D85_4211_81BC_2B11109251C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MySocket.h" 
/////////////////////////////////////////////////////////////////////////////
// CTalksDlg dialog

class CTalksDlg : public CDialog
{
// Construction
public:	
	CMySocket m_sListenSocket;
	CMySocket m_sConnectSocket;
	void OnConnect();
	void OnAccept();
	void OnReceive();
	void OnClose();
	CTalksDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTalksDlg)
	enum { IDD = IDD_TALKS_DIALOG };
	CButton		m_btnListen;
	CListBox	m_listSent;
	CListBox	m_listReceived;
	CString		m_strServName;
	CString		m_strMsg;
	int			m_nServPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTalksDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTalksDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonListen();
	afx_msg void OnButtonClose();
	afx_msg void OnSendMsg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TALKSDLG_H__A13FF4B7_2D85_4211_81BC_2B11109251C0__INCLUDED_)
