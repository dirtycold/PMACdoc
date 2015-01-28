// CSimpleAppDlg.h : header file
//

#if !defined(AFX_CSIMPLEAPPDLG_H__3C11DEB2_DD4F_46D7_A052_560F78C1AA94__INCLUDED_)
#define AFX_CSIMPLEAPPDLG_H__3C11DEB2_DD4F_46D7_A052_560F78C1AA94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCSimpleAppDlg dialog

class CCSimpleAppDlg : public CDialog
{
// Construction
public:
	CCSimpleAppDlg(CWnd* pParent = NULL);	// standard constructor
	/*-----------------Modified: Control data---------------------------*/
	 
	int  GetIndexFromSpeed(long speed);
	VARIANT m_VarToggle;
	int m_Toggle;
	long m_nSpeed,m_nSpindleToggle;
	bool m_bFirstClicked;
	void SendLine(const CString &s);
	BOOL m_bDriverOpen;
	UINT m_dwDevice;
	HINSTANCE   m_hPmacLib;              //库文件是否打开标志

	BOOL      PmacInitialize();							 //卡的初始化   
	void      PmacConfigureComm(HWND Wnd);  
	/*------------------------------------------------------------------*/
// Dialog Data
	//{{AFX_DATA(CCSimpleAppDlg)
	enum { IDD = IDD_CSIMPLEAPP_DIALOG };
	CStatic	m_ZValue;
	CStatic	m_YValue;
	CStatic	m_XValue;
	CComboBox	m_ComboBoxSpeed;
	CEdit	m_incrementEditCtrl;
	CButton	m_incrementCheckCtrl;
	CEdit	m_jogToEditCtrl;
	CStatic	m_selMotorStaticCtrl;
	CSpinButtonCtrl	m_selMotorSpinCtrl;
	CButton	m_heatBtnCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSimpleAppDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCSimpleAppDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnJogtoBtn();
	afx_msg void OnDeltaposSelmotorSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseDownJogminuBtn(short Button, short Shift, float X, float Y);
	afx_msg void OnMouseUpJogminuBtn(short Button, short Shift, float X, float Y);
	afx_msg void OnMouseDownJogplusBtn(short Button, short Shift, float X, float Y);
	afx_msg void OnMouseUpJogplusBtn(short Button, short Shift, float X, float Y);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSIMPLEAPPDLG_H__3C11DEB2_DD4F_46D7_A052_560F78C1AA94__INCLUDED_)
