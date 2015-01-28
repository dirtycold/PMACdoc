// CSimpleApp.h : main header file for the CSIMPLEAPP application
//

#if !defined(AFX_CSIMPLEAPP_H__44B06713_D434_4E73_B0F0_CAA24C0FAA1E__INCLUDED_)
#define AFX_CSIMPLEAPP_H__44B06713_D434_4E73_B0F0_CAA24C0FAA1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCSimpleAppApp:
// See CSimpleApp.cpp for the implementation of this class
//

class CCSimpleAppApp : public CWinApp
{
public:
	CCSimpleAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSimpleAppApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCSimpleAppApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSIMPLEAPP_H__44B06713_D434_4E73_B0F0_CAA24C0FAA1E__INCLUDED_)
