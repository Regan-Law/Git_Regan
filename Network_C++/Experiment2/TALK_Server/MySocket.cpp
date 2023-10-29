// MySocket.cpp : implementation file
//

#include "stdafx.h"
#include "talks.h"
#include "MySocket.h"
#include "TalksDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySocket

CMySocket::CMySocket()
{
	//put the member pointer to NULL
	m_pDlg=NULL;
}

CMySocket::~CMySocket()
{
	//put the member pointer to NULL
	m_pDlg=NULL;
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CMySocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CMySocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CMySocket member functions

void CMySocket::OnAccept(int nErrorCode) 
{
	if (nErrorCode==0)
		//call the dialog's OnAccept function
		m_pDlg->OnAccept();
}

void CMySocket::OnClose(int nErrorCode) 
{
	if (nErrorCode==0)
		//call the dialog's OnClose function
		m_pDlg->OnClose();
}

void CMySocket::OnConnect(int nErrorCode) 
{
	if (nErrorCode==0)
		//call the dialog's OnConnect function
		m_pDlg->OnConnect();
}

void CMySocket::OnReceive(int nErrorCode) 
{
	if (nErrorCode==0)
		//call the dialog's OnReceive function
		m_pDlg->OnReceive();
}

void CMySocket::SetParent(CTalksDlg *pDlg)
{
	//set the member pointer
	m_pDlg=pDlg;
}
