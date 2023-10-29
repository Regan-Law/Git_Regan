// talkcDlg.h : header file
//

#if !defined(AFX_TALKCDLG_H__AC4F7955_1012_4B99_946D_E63FFC0AD185__INCLUDED_)
#define AFX_TALKCDLG_H__AC4F7955_1012_4B99_946D_E63FFC0AD185__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MySocket.h" 
/////////////////////////////////////////////////////////////////////////////
// CTalkcDlg dialog

class CTalkcDlg : public CDialog
{
// Construction
public:
	void OnClose();
	void OnConnect();
	CMySocket m_sConnectSocket;
	void OnReceive();
	CTalkcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTalkcDlg)
	enum { IDD = IDD_TALKC_DIALOG };
	CListBox	m_listSent;
	CListBox	m_listReceived;
	CButton		m_btnConnect;
	CString		m_strMsg;
	CString		m_strServName;
	int			m_nServPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTalkcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTalkcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonConnect();
	afx_msg void OnSendMsg();
	afx_msg void OnButtonClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TALKCDLG_H__AC4F7955_1012_4B99_946D_E63FFC0AD185__INCLUDED_)
