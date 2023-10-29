// talks.h : main header file for the TALKS application
//

#if !defined(AFX_TALKS_H__A2EF205B_CB6F_438F_BB7B_23168390D760__INCLUDED_)
#define AFX_TALKS_H__A2EF205B_CB6F_438F_BB7B_23168390D760__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTalksApp:
// See talks.cpp for the implementation of this class
//

class CTalksApp : public CWinApp
{
public:
	CTalksApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTalksApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTalksApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TALKS_H__A2EF205B_CB6F_438F_BB7B_23168390D760__INCLUDED_)
