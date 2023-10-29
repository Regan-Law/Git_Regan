#if !defined(AFX_MYSOCKET_H__9741667D_315B_4915_BCDE_9F2125BA065C__INCLUDED_)
#define AFX_MYSOCKET_H__9741667D_315B_4915_BCDE_9F2125BA065C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MySocket.h : header file
//


class CTalkcDlg;
/////////////////////////////////////////////////////////////////////////////
// CMySocket command target

class CMySocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CMySocket();
	virtual ~CMySocket();

// Overrides
public:
	void SetParent(CTalkcDlg* pDlg);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySocket)
	public:
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMySocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation

private:
	CTalkcDlg* m_pDlg;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOCKET_H__9741667D_315B_4915_BCDE_9F2125BA065C__INCLUDED_)
