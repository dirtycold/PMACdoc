// PmacCtrlDlg.h : header file
//

#if !defined(AFX_PMACCTRLDLG_H__6A4C594D_3EFB_4F13_894A_248ABF536E43__INCLUDED_)
#define AFX_PMACCTRLDLG_H__6A4C594D_3EFB_4F13_894A_248ABF536E43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//					＝＝＝＝＝＝＝＝＝＝Types defines＝＝＝＝＝＝＝＝＝＝
// ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝  ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝ ＝

typedef long (FAR WINAPI *DOWNLOADGETPROC)(long nIndex,LPTSTR lpszBuffer,long nMaxLength);
typedef void (FAR WINAPI *DOWNLOADPROGRESS)(long nPercent);
typedef void (FAR WINAPI *DOWNLOADMSGPROC)(LPTSTR str,BOOL newline);

typedef bool    (CALLBACK *OPENPMACDEVICE)(DWORD dwDevice);
typedef bool    (CALLBACK *CLOSEPMACDEVICE)(DWORD dwDevice);
typedef int     (CALLBACK *PMACDOWNLOADA)(DWORD dwDevice, DOWNLOADMSGPROC msgp,
                                DOWNLOADGETPROC getp, DOWNLOADPROGRESS ppgr,
                                LPCTSTR filename, BOOL macro, BOOL map, BOOL log,
                                BOOL dnld );
typedef void	(CALLBACK *PMACFLUSH)(DWORD	dwDevice);
typedef long	(CALLBACK *PMACGETRESPONSEA)(DWORD dwDevice, LPTSTR response,
											 UINT maxchar, LPCTSTR command);

const CString	FILESAVEL = "\\Data\\Lpmac.txt";
const CString	FILESAVEC = "\\Data\\Cpmac.txt";
const CString	FILESAVEH = "\\Data\\Hpmac.txt";
const CString	FILEINTPL = "\\Data\\LIntpdata.txt";
const CString	FILEINTPC = "\\Data\\CIntpdata.txt";
const CString	FILEINTPH = "\\Data\\HIntpdata.txt";
const CString	FILEINVKL = "\\Data\\LInvkdata.txt";
const CString	FILEINVKC = "\\Data\\CInvkdata.txt";
const CString	FILEINVKH = "\\Data\\HInvkdata.txt";
const CString	FILEPMACL = "\\Data\\Ltest.pmc";
const CString	FILEPMACC = "\\Data\\Ctest.pmc";
const CString	FILEPMACH = "\\Data\\Htest.pmc";
const CString	FILEPARA  = "\\Data\\SPara.txt";

const CString	MSGSAVE = "参数保存在默认文件中！\n当您再次选择保存时，当前参数将被覆盖。\n可选择【另存为】将参数保存在其他文件中。";
const CString	MSGSAVEAS = "参数保存在指定文件中！";
const CString	MSGPARA	= "构型参数已保存在\n程序安装目录\\Data\\Spara.txt";

const double	pi = 3.14159265359;

/////////////////////////////////////////////////////////////////////////////
// CPmacCtrlDlg dialog

class CPmacCtrlDlg : public CDialog
{
// Construction
public:
	CPmacCtrlDlg(CWnd* pParent = NULL);	// standard constructor

	//		＝＝＝＝＝＝＝＝＝＝Function instants for linking＝＝＝＝＝＝＝＝＝＝
	OPENPMACDEVICE		OpenPmacDevice;
	CLOSEPMACDEVICE		ClosePmacDevice;
	PMACDOWNLOADA		PmacDownload;
	PMACFLUSH			PmacFlush;
	PMACGETRESPONSEA	PmacGetResponse;

	HINSTANCE hlib;
	double	dl1, dl2, dl3, dl4, dl5, dl6;
	CString	BASEDIR;

// Dialog Data
	//{{AFX_DATA(CPmacCtrlDlg)
	enum { IDD = IDD_PMACCTRL_DIALOG };
	CEdit	m_TimeEdit;
	CEdit	m_StructureParaEdit;
	CComboBox	m_cb;
	BOOL	m_TimeCheck;
	int		m_Structure;
	CString	m_Info;
	double	m_SzEdit;
	double	m_SyEdit;
	double	m_SxEdit;
	double	m_ExEdit;
	double	m_EyEdit;
	double	m_EzEdit;
	double	m_EaEdit;
	double	m_EbEdit;
	double	m_SaEdit;
	double	m_SbEdit;
	double	m_EangEdit;
	double	m_EcpxEdit;
	double	m_EcpyEdit;
	double	m_EcpzEdit;
	double	m_ErEdit;
	double	m_SangEdit;
	double	m_ScpxEdit;
	double	m_ScpyEdit;
	double	m_ScpzEdit;
	double	m_SrEdit;
	double	m_PaEdit;
	double	m_PbEdit;
	double	m_PcEdit;
	double	m_PxEdit;
	double	m_PyEdit;
	double	m_PzEdit;
	double	m_Axis1Edit;
	double	m_Axis2Edit;
	double	m_Axis3Edit;
	double	m_Axis4Edit;
	double	m_Axis5Edit;
	double	m_Axis6Edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPmacCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPmacCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnHelpHelp();
	afx_msg void OnCtrlDownload();
	afx_msg void OnDownload();
	afx_msg void OnCtrlLoadfile();
	afx_msg void OnLoadfile();
	afx_msg void OnExit();
	afx_msg void OnShowBUTTON();
	afx_msg void OnStructure1RADIO();
	afx_msg void OnStructure2RADIO();
	afx_msg void OnStructure3RADIO();
	afx_msg void OnStructure4RADIO();
	afx_msg void OnStructure5RADIO();
	afx_msg void OnSelchangeComboChoice();
	afx_msg void OnDefault();
	afx_msg void OnSave();
	afx_msg void OnConfirm();
	afx_msg void OnFileSave();
	afx_msg void OnStructureFive();
	afx_msg void OnStructureFour();
	afx_msg void OnStructureOne();
	afx_msg void OnStructureThree();
	afx_msg void OnStructureTwo();
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnChangeSrEdit();
	afx_msg void OnChangeScpxEdit();
	afx_msg void OnChangeScpyEdit();
	afx_msg void OnChangeScpzEdit();
	afx_msg void OnFileSaveas();
	afx_msg void OnFileDefault();
	afx_msg void OnOutputpara();
	afx_msg void OnCtrlOutputpara();
	afx_msg void OnCtrlZero();
	afx_msg void OnCtrlExcursion();
	afx_msg void OnCtrlExecute();
	afx_msg void OnZero();
	afx_msg void OnExcursion();
	afx_msg void OnExecute();
	afx_msg void OnCtrlAutoexecute();
	afx_msg void OnCtrlLoadnc();
	afx_msg void OnLoadnc();
	afx_msg void OnAutoexecute();
	afx_msg void OnViewInterpolation();
	afx_msg void OnViewInvkine();
	afx_msg void OnCtrlInitial();
	afx_msg void OnInitial();
	afx_msg void OnCtrlInterpolationL();
	afx_msg void OnCtrlInterpolationC();
	afx_msg void OnCtrlInterpolationH();
	afx_msg void OnCtrlInvkineA(double x,double y,double z,double a,double b,double g);
	afx_msg void OnCtrlInvkineB(double x,double y,double z,double a,double b,double g);
	afx_msg void OnCtrlInvkineC(double x,double y,double z,double a,double b,double g);
	afx_msg void OnCtrlInvkineD(double x,double y,double z,double a,double b,double g);
	afx_msg void OnCtrlInvkineE(double x,double y,double z,double a,double b,double g);
	afx_msg double OnGetRoot(double a, double b, double c, int sign);
	afx_msg	void OnSaveText(CString filesave);
	afx_msg void OnCtrlProcess();
	afx_msg void OnCtrlViewInterpolation();
	afx_msg void OnCtrlViewInvkine();
	afx_msg void OnCtrlOutputphoto();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnOpen(CString fileopen);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PMACCTRLDLG_H__6A4C594D_3EFB_4F13_894A_248ABF536E43__INCLUDED_)
