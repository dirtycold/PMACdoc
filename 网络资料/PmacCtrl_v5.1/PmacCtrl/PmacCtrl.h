// PmacCtrl.h : main header file for the PMACCTRL application
//

#if !defined(AFX_PMACCTRL_H__669F07DD_A8F9_42BC_AE5C_5B02283EED51__INCLUDED_)
#define AFX_PMACCTRL_H__669F07DD_A8F9_42BC_AE5C_5B02283EED51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPmacCtrlApp:
// See PmacCtrl.cpp for the implementation of this class
//

class CPmacCtrlApp : public CWinApp
{
public:
	CPmacCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPmacCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPmacCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PMACCTRL_H__669F07DD_A8F9_42BC_AE5C_5B02283EED51__INCLUDED_)
