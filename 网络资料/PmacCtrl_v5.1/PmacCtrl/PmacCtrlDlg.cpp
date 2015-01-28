// PmacCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PmacCtrl.h"
#include "PmacCtrlDlg.h"
#include <math.h>
#include "process.h"
#define BUFFER MAX_PATH

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPmacCtrlDlg dialog

CPmacCtrlDlg::CPmacCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPmacCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPmacCtrlDlg)
	m_TimeCheck = FALSE;
	m_Structure = -1;
	m_Info = _T("");
	m_SzEdit = 0.0;
	m_SyEdit = 0.0;
	m_SxEdit = 0.0;
	m_ExEdit = 0.0;
	m_EyEdit = 0.0;
	m_EzEdit = 0.0;
	m_EaEdit = 0.0;
	m_EbEdit = 0.0;
	m_SaEdit = 0.0;
	m_SbEdit = 0.0;
	m_EangEdit = 0.0;
	m_EcpxEdit = 0.0;
	m_EcpyEdit = 0.0;
	m_EcpzEdit = 0.0;
	m_ErEdit = 0.0;
	m_SangEdit = 0.0;
	m_ScpxEdit = 0.0;
	m_ScpyEdit = 0.0;
	m_ScpzEdit = 0.0;
	m_SrEdit = 0.0;
	m_PaEdit = 0.0;
	m_PbEdit = 0.0;
	m_PcEdit = 0.0;
	m_PxEdit = 0.0;
	m_PyEdit = 0.0;
	m_PzEdit = 0.0;
	m_Axis1Edit = 0.0;
	m_Axis2Edit = 0.0;
	m_Axis3Edit = 0.0;
	m_Axis4Edit = 0.0;
	m_Axis5Edit = 0.0;
	m_Axis6Edit = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPmacCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPmacCtrlDlg)
	DDX_Control(pDX, IDC_TIME_EDIT, m_TimeEdit);
	DDX_Control(pDX, IDC_StructurePara_EDIT, m_StructureParaEdit);
	DDX_Control(pDX, IDC_COMBO_CHOICE, m_cb);
	DDX_Radio(pDX, IDC_Structure1_RADIO, m_Structure);
	DDX_Text(pDX, IDC_INFO, m_Info);
	DDX_Text(pDX, IDC_SZ_EDIT, m_SzEdit);
	DDX_Text(pDX, IDC_SY_EDIT, m_SyEdit);
	DDX_Text(pDX, IDC_SX_EDIT, m_SxEdit);
	DDX_Text(pDX, IDC_EX_EDIT, m_ExEdit);
	DDX_Text(pDX, IDC_EY_EDIT, m_EyEdit);
	DDX_Text(pDX, IDC_EZ_EDIT, m_EzEdit);
	DDX_Text(pDX, IDC_EA_EDIT, m_EaEdit);
	DDX_Text(pDX, IDC_EB_EDIT, m_EbEdit);
	DDX_Text(pDX, IDC_SA_EDIT, m_SaEdit);
	DDX_Text(pDX, IDC_SB_EDIT, m_SbEdit);
	DDX_Text(pDX, IDC_EANG_EDIT, m_EangEdit);
	DDX_Text(pDX, IDC_ECPX_EDIT, m_EcpxEdit);
	DDX_Text(pDX, IDC_ECPY_EDIT, m_EcpyEdit);
	DDX_Text(pDX, IDC_ECPZ_EDIT, m_EcpzEdit);
	DDX_Text(pDX, IDC_ER_EDIT, m_ErEdit);
	DDX_Text(pDX, IDC_SANG_EDIT, m_SangEdit);
	DDX_Text(pDX, IDC_SCPX_EDIT, m_ScpxEdit);
	DDX_Text(pDX, IDC_SCPY_EDIT, m_ScpyEdit);
	DDX_Text(pDX, IDC_SCPZ_EDIT, m_ScpzEdit);
	DDX_Text(pDX, IDC_SR_EDIT, m_SrEdit);
	DDX_Text(pDX, IDC_PA_EDIT, m_PaEdit);
	DDX_Text(pDX, IDC_PB_EDIT, m_PbEdit);
	DDX_Text(pDX, IDC_PC_EDIT, m_PcEdit);
	DDX_Text(pDX, IDC_PX_EDIT, m_PxEdit);
	DDX_Text(pDX, IDC_PY_EDIT, m_PyEdit);
	DDX_Text(pDX, IDC_PZ_EDIT, m_PzEdit);
	DDX_Text(pDX, IDC_AXIS1_EDIT, m_Axis1Edit);
	DDX_Text(pDX, IDC_AXIS2_EDIT, m_Axis2Edit);
	DDX_Text(pDX, IDC_AXIS3_EDIT, m_Axis3Edit);
	DDX_Text(pDX, IDC_AXIS4_EDIT, m_Axis4Edit);
	DDX_Text(pDX, IDC_AXIS5_EDIT, m_Axis5Edit);
	DDX_Text(pDX, IDC_AXIS6_EDIT, m_Axis6Edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPmacCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CPmacCtrlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_HELP_HELP, OnHelpHelp)
	ON_COMMAND(ID_CTRL_LOADFILE, OnCtrlLoadfile)
	ON_BN_CLICKED(IDC_LOADFILE, OnLoadfile)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_Show_BUTTON, OnShowBUTTON)
	ON_BN_CLICKED(IDC_Structure1_RADIO, OnStructure1RADIO)
	ON_BN_CLICKED(IDC_Structure2_RADIO, OnStructure2RADIO)
	ON_BN_CLICKED(IDC_Structure3_RADIO, OnStructure3RADIO)
	ON_BN_CLICKED(IDC_Structure4_RADIO, OnStructure4RADIO)
	ON_BN_CLICKED(IDC_Structure5_RADIO, OnStructure5RADIO)
	ON_CBN_SELCHANGE(IDC_COMBO_CHOICE, OnSelchangeComboChoice)
	ON_BN_CLICKED(IDC_DEFAULT, OnDefault)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_CONFIRM, OnConfirm)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_STRUCTURE_FIVE, OnStructureFive)
	ON_COMMAND(ID_STRUCTURE_FOUR, OnStructureFour)
	ON_COMMAND(ID_STRUCTURE_ONE, OnStructureOne)
	ON_COMMAND(ID_STRUCTURE_THREE, OnStructureThree)
	ON_COMMAND(ID_STRUCTURE_TWO, OnStructureTwo)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_EN_CHANGE(IDC_SR_EDIT, OnChangeSrEdit)
	ON_EN_CHANGE(IDC_SCPX_EDIT, OnChangeScpxEdit)
	ON_EN_CHANGE(IDC_SCPY_EDIT, OnChangeScpyEdit)
	ON_EN_CHANGE(IDC_SCPZ_EDIT, OnChangeScpzEdit)
	ON_COMMAND(ID_FILE_SAVEAS, OnFileSaveas)
	ON_COMMAND(ID_FILE_DEFAULT, OnFileDefault)
	ON_BN_CLICKED(IDC_OUTPUTPARA, OnOutputpara)
	ON_COMMAND(ID_CTRL_OUTPUTPARA, OnCtrlOutputpara)
	ON_COMMAND(ID_CTRL_ZERO, OnCtrlZero)
	ON_COMMAND(ID_CTRL_EXCURSION, OnCtrlExcursion)
	ON_COMMAND(ID_CTRL_EXECUTE, OnCtrlExecute)
	ON_BN_CLICKED(IDC_ZERO, OnZero)
	ON_BN_CLICKED(IDC_EXCURSION, OnExcursion)
	ON_BN_CLICKED(IDC_EXECUTE, OnExecute)
	ON_COMMAND(ID_CTRL_AUTOEXECUTE, OnCtrlAutoexecute)
	ON_COMMAND(ID_CTRL_LOADNC, OnCtrlLoadnc)
	ON_BN_CLICKED(IDC_LOADNC, OnLoadnc)
	ON_BN_CLICKED(IDC_AUTOEXECUTE, OnAutoexecute)
	ON_BN_CLICKED(IDC_VIEW_INTERPOLATION, OnViewInterpolation)
	ON_BN_CLICKED(IDC_VIEW_INVKINE, OnViewInvkine)
	ON_COMMAND(ID_CTRL_INITIAL, OnCtrlInitial)
	ON_BN_CLICKED(IDC_INITIAL, OnInitial)
	ON_COMMAND(ID_CTRL_INTERPOLATION, OnCtrlInterpolationL)
	ON_COMMAND(ID_CTRL_INVKINE, OnCtrlInvkineA)
	ON_COMMAND(ID_CTRL_PROCESS, OnCtrlProcess)
	ON_COMMAND(ID_CTRL_VIEW_INTERPOLATION, OnCtrlViewInterpolation)
	ON_COMMAND(ID_CTRL_VIEW_INVKINE, OnCtrlViewInvkine)
	ON_COMMAND(ID_CTRL_OUTPUTPHOTO, OnCtrlOutputphoto)
	ON_WM_TIMER()
	ON_WM_TIMER()
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPmacCtrlDlg message handlers

BOOL CPmacCtrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

//	*********************************************************************************

	//			＝＝＝＝＝＝＝＝＝＝保存当前路径＝＝＝＝＝＝＝＝＝＝	
	// Save current dir
	DWORD cchCurDir;
	LPTSTR lpszCurDir;
	TCHAR tchBuffer[BUFFER];
	lpszCurDir = tchBuffer;
	GetCurrentDirectory(cchCurDir, lpszCurDir);
	BASEDIR = lpszCurDir;			

	// Create a new directory named Data. 
	CreateDirectory(BASEDIR + "\\Data", NULL);

	//			＝＝＝＝＝＝＝＝＝＝初始化对话框数据＝＝＝＝＝＝＝＝＝＝

	// Set timer for real-time time show
	SetTimer(1001,1000,NULL);

	// Initialize Information show
	m_Info = "欢迎使用基于Windows平台的PMAC控制程序！";

	// Initialize Structure Choice Radio Button
	m_Structure = 0;

	// Initialize Track Choice Combo Box
	m_cb.AddString("直线_LINE");
	m_cb.AddString("圆_CIRCLE");
	m_cb.AddString("螺旋线_HELIX");
	m_cb.SelectString(-1, "直线_LINE");
	UpdateData(FALSE);

	// Default: Line is chosen, enable line parameters inputs, disable other inputs
	GetDlgItem(IDC_SR_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_SANG_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_SCPX_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_SCPY_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_SCPZ_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_ER_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_EANG_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_ECPX_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_ECPY_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_ECPZ_EDIT)->EnableWindow(FALSE);

	// Initialize line parameter
	m_SxEdit = 90;		m_ExEdit = 0;
	m_SyEdit = 90;		m_EyEdit = 0;
	m_SzEdit = -800;	m_EzEdit = -800;
	m_SaEdit = 0;		m_EaEdit = 0;
	m_SbEdit = 0;		m_EbEdit = 0;
	UpdateData(FALSE);

	// Initialize Structure Parameter View Edit Box
	char	paraInitialEdit[10000];
	strcpy(paraInitialEdit, "您选择的是：");
	strcat(paraInitialEdit, "构型－1。\t\t\t");
	strcat(paraInitialEdit, "---------------------------------");
	strcat(paraInitialEdit, "静平台直径1485mm，距顶板底面84mm，6个铰链点的角度见图例；\t\t\t");
	strcat(paraInitialEdit, "                                 ");
	strcat(paraInitialEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例。\t\t");
	strcat(paraInitialEdit, "                                 ");
	strcat(paraInitialEdit, "各铰链点位置分布见图例。");

	m_StructureParaEdit.SetSel(0,-1);
	m_StructureParaEdit.ReplaceSel(paraInitialEdit);

	// Initialize progress view in the middle
	CProgressCtrl*	pProg = (CProgressCtrl*) GetDlgItem (IDC_PROGRESS);
	pProg->SetRange(0, 100);
	pProg->SetPos(50);

	//			＝＝＝＝＝＝＝＝＝＝LOAD DLL＝＝＝＝＝＝＝＝＝＝

	hlib = LoadLibrary ("PComm32.dll");

	// Test if PComm32.dll is loaded successfully
	if ( !(hlib = LoadLibrary("PComm32.dll")) )
		{
			AfxMessageBox("Fail to load dll!");
			return FALSE;
		}

	// Get function address
	OpenPmacDevice = (OPENPMACDEVICE)GetProcAddress(hlib,"OpenPmacDevice");
//	if (OpenPmacDevice == NULL) return;
	ClosePmacDevice = (CLOSEPMACDEVICE)GetProcAddress(hlib,"ClosePmacDevice");
//	if (ClosePmacDevice == NULL) return;
	PmacDownload = (PMACDOWNLOADA)GetProcAddress(hlib,"PmacDownloadA");
//	if (PmacDownload == NULL) return;
	PmacFlush = (PMACFLUSH)GetProcAddress(hlib,"PmacFlush");
//	if (PmacFlush == NULL) return;
	PmacGetResponse = (PMACGETRESPONSEA)GetProcAddress(hlib,"PmacGetResponseA");
//	if (PmacGetResponse == NULL) return;

//	*********************************************************************************

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPmacCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

//  If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPmacCtrlDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPmacCtrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//	*******************菜单栏项目(文件——控制——构型——帮助)*******************

//					＝＝＝＝＝＝＝＝＝＝文件－菜单＝＝＝＝＝＝＝＝＝＝

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"新建"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	首先判断选择的轨迹类型，然后将相应的参数全部设置为0；
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnFileNew() 
{
	// TODO: Add your command handler code here
	CString msg;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	// Judge which option is chosen
	if(msg == "直线_LINE")
	{
		UpdateData(TRUE);
		m_SxEdit = 0;	m_ExEdit = 0;
		m_SyEdit = 0;	m_EyEdit = 0;
		m_SzEdit = 0;	m_EzEdit = 0;
		m_SaEdit = 0;	m_EaEdit = 0;
		m_SbEdit = 0;	m_EbEdit = 0;
		UpdateData(FALSE);
	}
	else if(msg == "圆_CIRCLE")
	{
		UpdateData(TRUE);
		m_SrEdit = 0;		m_ErEdit = m_SrEdit;	
		m_SangEdit = 0;		m_EangEdit = 0;
		m_ScpxEdit = 0;		m_EcpxEdit = m_ScpxEdit;
		m_ScpyEdit = 0;		m_EcpyEdit = m_ScpyEdit;
		m_ScpzEdit = 0;		m_EcpzEdit = m_ScpzEdit;
		UpdateData(FALSE);
	}
	else
	{
		UpdateData(TRUE);
		m_SrEdit = 0;		m_ErEdit = 0;
		m_SangEdit = 0;		m_EangEdit = 0;
		m_ScpxEdit = 0;		m_EcpxEdit = 0;
		m_ScpyEdit = 0;		m_EcpyEdit = 0;
		m_ScpzEdit = 0;		m_EcpzEdit = 0;
		UpdateData(FALSE);
	}
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"打开"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	打开以前保存的运动轨迹几何参数文件，将其中的几何参数读入相应轨迹的参数编辑框内。
//	首先弹出打开对话框，供用户选择要打开的文件，然后读取当前选择的轨迹类型，与用户
//	选择的文件的轨迹类型比较，如一致，则读取轨迹参数，否则提示轨迹类型不符。
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnFileOpen() 
{
	// TODO: Add your command handler code here
	// Pop-up the file open dialog box
	static char BASED_CODE szFilter[] = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*||";
	CFileDialog	dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);

	if(dlg.DoModal() == IDOK)
	{
		// Get the full path of the specified file
		CString	fileopen;
		fileopen = dlg.GetPathName();
		if(fileopen == "") return;
		CPmacCtrlDlg::OnOpen(fileopen);
	}	
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝File Open＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnOpen(CString fileopen)
{
	// Open the file
	FILE*	fpopen;
	fpopen = fopen(fileopen, "r");
	// line parameter
	char	row[100], judge[100], spoint[100], sang[100], epoint[100], eang[100];
	char	sx[20], sy[20], sz[20], sa[20], sb[20];
	char	ex[20], ey[20], ez[20], ea[20], eb[20];
	// circle parameter
	char	center[100], radius[100], Csang[100], Ceang[100];
	char	Cx[20], Cy[20], Cz[20];
	// helix parameter
	char	Scenter[100], Sradius[100], Hsang[100], Ecenter[100], Eradius[100], Heang[100];
	char	Hsx[20], Hsy[20], Hsz[20], Hex[20], Hey[20], Hez[20];

	int	num = 100;

	// Get the 4th line of the file to judge which track it is
	fgets(row, num, fpopen);
	fgets(row, num, fpopen);
	fgets(row, num, fpopen);
	fgets(judge, num, fpopen);

	// Get current type of track
	CString msg;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	// Read the file to read in the parameters, and show them to edit box
	if(msg == "直线_LINE")
	{
		if(judge[0]=='L')
		{
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(spoint, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(sang, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(epoint, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(eang, num, fpopen);

			sscanf(spoint, "%s %s %s", sx, sy, sz);
			sscanf(sang, "%s %s", sa, sb);
			sscanf(epoint, "%s %s %s", ex, ey, ez);
			sscanf(eang, "%s %s", ea, eb);

			UpdateData(TRUE);
			m_SxEdit = atof(sx);	m_ExEdit = atof(ex);
			m_SyEdit = atof(sy);	m_EyEdit = atof(ey);
			m_SzEdit = atof(sz);	m_EzEdit = atof(ez);
			m_SaEdit = atof(sa);	m_EaEdit = atof(ea);
			m_SbEdit = atof(sb);	m_EbEdit = atof(eb);
			UpdateData(FALSE);
			AfxMessageBox("指定文件中的参数已被读入！");
		}
		else
			AfxMessageBox("所选参数文件轨迹类型与当前指定的轨迹类型不同，不能读取文件！");
	}
	else if(msg == "圆_CIRCLE")
	{
		if(judge[0]=='C')
		{
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(center, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(radius, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(Csang, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(Ceang, num, fpopen);

			sscanf(center, "%s %s %s", Cx, Cy, Cz);

			UpdateData(TRUE);
			m_SrEdit = atof(radius);	m_ErEdit = m_SrEdit;	
			m_SangEdit = atof(Csang);	m_EangEdit = atof(Ceang);
			m_ScpxEdit = atof(Cx);		m_EcpxEdit = m_ScpxEdit;
			m_ScpyEdit = atof(Cy);		m_EcpyEdit = m_ScpyEdit;
			m_ScpzEdit = atof(Cz);		m_EcpzEdit = m_ScpzEdit;
			UpdateData(FALSE);
			AfxMessageBox("指定文件中的参数已被读入！");
		}
		else
			AfxMessageBox("所选参数文件轨迹类型与当前指定的轨迹类型不同，不能读取文件！");
	}
	else
	{
		if(judge[0]=='H')
		{
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(Scenter, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(Sradius, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(Hsang, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(Ecenter, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(Eradius, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(row, num, fpopen);
			fgets(Heang, num, fpopen);

			sscanf(Scenter, "%s %s %s", Hsx, Hsy, Hsz);
			sscanf(Ecenter, "%s %s %s", Hex, Hey, Hez);

			UpdateData(TRUE);
			m_SrEdit = atof(Sradius);	m_ErEdit = atof(Eradius);
			m_SangEdit = atof(Hsang);	m_EangEdit = atof(Heang);
			m_ScpxEdit = atof(Hsx);		m_EcpxEdit = atof(Hex);
			m_ScpyEdit = atof(Hsy);		m_EcpyEdit = atof(Hey);
			m_ScpzEdit = atof(Hsz);		m_EcpzEdit = atof(Hez);
			UpdateData(FALSE);
			AfxMessageBox("指定文件中的参数已被读入！");
		}
		else
			AfxMessageBox("所选参数文件轨迹类型与当前指定的轨迹类型不同，不能读取文件！");
	}
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"保存"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	首先判断轨迹类型，然后将当前输入的轨迹参数保存在相应的默认文件中，并提示用户。
//	line - Lpmac.txt;	circle - Cpmac.txt;		helix - Hpmac.txt;
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnFileSave() 
{
	// TODO: Add your command handler code here
	CString msg;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);
	if(msg == "直线_LINE")
		CPmacCtrlDlg::OnSaveText(BASEDIR + FILESAVEL);
	else if(msg == "圆_CIRCLE")
		CPmacCtrlDlg::OnSaveText(BASEDIR + FILESAVEC);
	else
		CPmacCtrlDlg::OnSaveText(BASEDIR + FILESAVEH);
	AfxMessageBox(MSGSAVE);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"另存为"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	用户自己指定名称保存运动轨迹参数
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnFileSaveas() 
{
	// TODO: Add your command handler code here
	// Pop-up the file open dialog box
	static char BASED_CODE szFilter[] = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*||";
	CFileDialog	dlg(FALSE,".txt",NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);
	
	if(dlg.DoModal () == IDOK )
	{
		CString	filesaveas;
		filesaveas = dlg.GetPathName();
		if(filesaveas == "") return;
		CPmacCtrlDlg::OnSaveText(filesaveas);
		AfxMessageBox(MSGSAVEAS);
	}
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"默认数据"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	判断当前轨迹类型，将相应的参数设置为默认值。
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnFileDefault() 
{
	// TODO: Add your command handler code here
	CString msg;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	// Judge which track is chosen
	if(msg == "直线_LINE")
	{
		UpdateData(TRUE);
		m_SxEdit = 90;		m_ExEdit = 0;
		m_SyEdit = 90;		m_EyEdit = 0;
		m_SzEdit = -800;	m_EzEdit = -800;
		m_SaEdit = 0;		m_EaEdit = 0;
		m_SbEdit = 0;		m_EbEdit = 0;
		UpdateData(FALSE);
	}
	else if(msg == "圆_CIRCLE")
	{
		UpdateData(TRUE);
		m_SrEdit = 90;		m_ErEdit = m_SrEdit;	
		m_SangEdit = 0;		m_EangEdit = 360;
		m_ScpxEdit = 0;		m_EcpxEdit = m_ScpxEdit;
		m_ScpyEdit = 0;		m_EcpyEdit = m_ScpyEdit;
		m_ScpzEdit = -800;	m_EcpzEdit = m_ScpzEdit;
		UpdateData(FALSE);
	}
	else
	{
		UpdateData(TRUE);
		m_SrEdit = 90;		m_ErEdit = 50;
		m_SangEdit = 0;		m_EangEdit = 360;
		m_ScpxEdit = 0;		m_EcpxEdit = 0;
		m_ScpyEdit = 0;		m_EcpyEdit = 0;
		m_ScpzEdit = -800;	m_EcpzEdit = -400;
		UpdateData(FALSE);
	}
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"退出"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	关闭PMAC，释放DLL，退出程序。
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnFileExit() 
{
	// TODO: Add your command handler code here
	ClosePmacDevice(0);
	FreeLibrary(hlib);	
	OnCancel();	
}

//					＝＝＝＝＝＝＝＝＝＝控制－菜单＝＝＝＝＝＝＝＝＝＝

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"数据处理"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	首先判断当前选择的轨迹类型，然后对相应轨迹参数进行插补和逆解处理，生成供查看用的插补
//	、逆解文件，以及供下载用的*.pmc文件。
//	line - Ltest.pmc;	circle - Ctest.pmc;		helix - Htest.pmc;
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlProcess() 
{
	// TODO: Add your command handler code here
	// Show prompt information at the bottom of the dialog
	UpdateData(TRUE);
	m_Info = "正在进行数据处理：插补——逆解，请稍候...";
	UpdateData(FALSE);

	// Get the current track
	CString msg;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);
	
	// Do interpolation
	if(msg == "直线_LINE")
		CPmacCtrlDlg::OnCtrlInterpolationL();
	else if(msg == "圆_CIRCLE")
		CPmacCtrlDlg::OnCtrlInterpolationC();
	else
		CPmacCtrlDlg::OnCtrlInterpolationH();

	Sleep(5000);	//delay

	// show prompt information
	m_Info = "数据处理完成，可以下载数据文件至PMAC，也可查看插补、逆解数据。";
	UpdateData(FALSE);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"初始化PMAC"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlInitial() 
{
	// TODO: Add your command handler code here
	// show prompt information
	m_Info = "正在对PMAC进行初始化设置，请稍候...";
	UpdateData(FALSE);

	OpenPmacDevice(0);
	PmacFlush(0);

	// Send reset command to PMAC
	char	response[20];
	UINT	maxchar = 20;
	CString	reset;
	reset = "$$$";
	PmacGetResponse(0, response, maxchar, reset);
	Sleep(10000);	// delay
	PmacGetResponse(0, response, maxchar, reset);
	Sleep(10000);	// delay

	// show prompt information
	m_Info = "PMAC初始化完毕！要继续，请执行“机床归零”！";
	UpdateData(FALSE);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"机床归零"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlZero() 
{
	// TODO: Add your command handler code here
	// show prompt information
	m_Info = "正在执行机床归零程序，请稍候...";
	UpdateData(FALSE);

	OpenPmacDevice(0);
	PmacFlush(0);

	// Send closeloop and return zero commands to PMAC
	char	response[20];
	UINT	maxchar = 20;
	CString	closeloop, zerocommand;
	closeloop = "p1=1";
	zerocommand = "p2=1";

	//PmacGetResponse(DWORD dwDevice,LPTSTR response,UINT maxchar,LPCTSTR command);
	//dwDevice		Device number. 
	//response		Pointer to string buffer to copy the PMAC’s response into.
	//maxchar		Maximum characters to copy. 
	//command		Pointer to NULL terminated string to be sent to the PMAC as a question/command.

	PmacGetResponse(0, response, maxchar, closeloop);		// Closeloop command
	PmacGetResponse(0, response, maxchar, zerocommand);		// Return zero command
	Sleep(5000);	//delay

	// show prompt information
	m_Info = "机床归零完成！要继续，请执行“零点偏移”！";
	UpdateData(FALSE);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"零点偏移"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlExcursion() 
{
	// TODO: Add your command handler code here
	// show prompt information
	m_Info = "正在执行零点偏移程序，请稍候...";
	UpdateData(FALSE);

	OpenPmacDevice(0);
	PmacFlush(0);

	// Send zero excursion command to PMAC
	char	response[20];
	UINT	maxchar = 20;
	CString	excommand,excommand2;
	excommand = "b2";
	excommand2 = "r";
	PmacGetResponse(0, response, maxchar, excommand);
	PmacGetResponse(0, response, maxchar, excommand2);
	Sleep(5000);

	// show prompt information
	m_Info = "零点偏移完成！您可以直接“执行程序”，也可以先进行“文件下载”！";
	UpdateData(FALSE);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"文件下载"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	判断当前轨迹类型，下载相应的.pmc文件到PMAC。
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlLoadfile() 
{
	// TODO: Add your command handler code here
	CString	msg, fileload;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	// According to current track, define which file to download
	if(msg == "直线_LINE")
		fileload = FILEPMACL;
	else if(msg == "圆_CIRCLE")
		fileload = FILEPMACC;
	else
		fileload = FILEPMACH;

	// show prompt information
	UpdateData(TRUE);
	m_Info = "正在将数据文件下载到PMAC，请稍候...";
	UpdateData(FALSE);

	// Start download progress bar
	CProgressCtrl*	pProg = (CProgressCtrl*) GetDlgItem (IDC_PROGRESS);
	pProg->SetPos(0);
	SetTimer(1000,100,NULL);

	OpenPmacDevice(0);
	PmacFlush(0);
	// PmacDownload(DWORD dwDevice, DOWNLOADMSGPROC msgp, DOWNLOADGETPROC getp, DOWNLOADPROGRESS pprg, LPCTSTR filename, BOOL macro, BOOL map, BOOL log, BOOL dnld);
	// DWORD dwDevice: Device number
	// DOWNLOADMSGPROC msgp: Pointer to message procedure pointer, if NULL no function is called
	// DOWNLOADGETPROC getp: Pointer to line retrieval function, if NULL no function is called
	// DOWNLOADPROGRESS pprg: Pointer to download progress function, if NULL no function is called
	// LPCTSTR filename: Path to file to download
	// BOOL macro: Flag to parse for macros
	// BOOL map: Flag to create a map file created from macros
	// BOOL log: Flag to create a log file. This is the same messages as sent to the "msgp" procedure
	// BOOL dnld: Flag indicating to send final parsed file to PMAC
	PmacDownload (0, NULL, NULL, NULL, fileload, 1, 1, 1, 1);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"Progress Process"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == 1000)
	{
		CProgressCtrl*	pProg = (CProgressCtrl*) GetDlgItem (IDC_PROGRESS);
		pProg->SetPos(pProg->GetPos()+1);
		if(pProg->GetPos() >= 100)
		{
			KillTimer(nIDEvent);
			m_Info = "文件成功下载到PMAC！您可以“执行程序”！";
			UpdateData(FALSE);
		}
	}

	if(nIDEvent == 1001)
	{
		CTime tNow;
		tNow = CTime::GetCurrentTime();
		CString sNow = tNow.Format(" [%H : %M : %S]  %B %d－%Y  [%a]");
		m_TimeEdit.SetSel(0,-1);
		m_TimeEdit.ReplaceSel(sNow);		
	}
	CDialog::OnTimer(nIDEvent);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"执行程序"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	首先下载文件到PMAC，然后执行运动程序。
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlExecute() 
{
	// TODO: Add your command handler code here
	// Download file
	CString	msg, fileload;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	if(msg == "直线_LINE")
		fileload = FILEPMACL;
	else if(msg == "圆_CIRCLE")
		fileload = FILEPMACC;
	else
		fileload = FILEPMACH;
	
	UpdateData(TRUE);
	m_Info = "开始文件下载，请稍候...";
	UpdateData(FALSE);

	OpenPmacDevice(0);
	PmacFlush(0);
	PmacDownload (0, NULL, NULL, NULL, fileload,1,1,1,1);
	Sleep(10000);

	m_Info = "文件下载完毕，开始执行程序，请稍候...";
	UpdateData(FALSE);

	// Execute the routine
	char	response[20];
	UINT	maxchar = 20;
	CString	execommand1, execommand2;
	execommand1 = "b10";
	execommand2 = "r";
	PmacGetResponse(0, response, maxchar, execommand1);
	PmacGetResponse(0, response, maxchar, execommand2);
	Sleep(20000);

	m_Info = "程序执行完毕！";
	UpdateData(FALSE);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"导出构型参数"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	导出当前构型的参数至程序所在文件夹\Data\Spara.txt
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlOutputpara() 
{
	// TODO: Add your command handler code here
	// prompt path to the parameter file 
	AfxMessageBox(MSGPARA);
	char	paraEdit[10000];
	int		iStructureRADIO;
	iStructureRADIO = GetCheckedRadioButton(IDC_Structure1_RADIO,IDC_Structure5_RADIO);
	strcpy(paraEdit, "您选择的是：");
	if(iStructureRADIO == IDC_Structure1_RADIO)
	{
		strcat(paraEdit, "构型－1。\n");
		strcat(paraEdit, "---------------------------------\n");
		strcat(paraEdit, "静平台直径1485mm，距顶板底面84mm，6个铰链点的角度见图例；\n\n");
		strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例。\n\n");
		strcat(paraEdit, "各铰链点位置分布见图例。");
	}
	else if(iStructureRADIO == IDC_Structure2_RADIO)
	{
		strcat(paraEdit, "构型－2。\n");
		strcat(paraEdit, "---------------------------------\n");
		strcat(paraEdit, "静平台铰链点位于形心高度为357.25mm的正三角形上，距顶板底面84mm，见图例；\n\n");
		strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例；\n\n");
		strcat(paraEdit, "滑块中心平面的极限位置为136－350mm，见图例。");
	}
	else if(iStructureRADIO == IDC_Structure3_RADIO)
	{
		strcat(paraEdit, "构型－3。\n");
		strcat(paraEdit, "---------------------------------\n");
		strcat(paraEdit, "静平台直径1109.02mm，距顶板底面84mm，6个铰链点的角度见图例；\n\n");
		strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例。\n\n");
		strcat(paraEdit, "各铰链点位置分布见图例。");
	}
	else if(iStructureRADIO == IDC_Structure4_RADIO)
	{
		strcat(paraEdit, "构型－4。\n");
		strcat(paraEdit, "---------------------------------\n");
		strcat(paraEdit, "静平台直径1101mm，距顶板底面84mm，3个铰链点的角度见图例；\n\n");
		strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，3个铰链点的角度见图例。\n\n");
		strcat(paraEdit, "各铰链点位置分布见图例。");
	}
	else
	{
		strcat(paraEdit, "构型－5。\n");
		strcat(paraEdit, "---------------------------------\n");
		strcat(paraEdit, "静平台直径1485mm，距顶板底面84mm，6个铰链点的角度见图例；\n\n");
		strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例。\n\n");
		strcat(paraEdit, "各铰链点位置分布见图例。");
	}

	// Write the parameter of current structure down to the default file
	FILE	*parafp;
	parafp = fopen(BASEDIR + FILEPARA, "w+");
	if(parafp == NULL)
	{
		AfxMessageBox("保存构型参数失败!");
		return;
	}
	fputs(paraEdit, parafp);
	fclose(parafp);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"显示构型图例"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	采用mspaint或iexplore显示当前构型的图例。
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlOutputphoto() 
{
	// TODO: Add your command handler code here
	CString	illuA, illuB, illuC, illuD, illuE;
	CString	struA, struB, struC, struD, struE;

	// Show illustration by mspaint
/*	illuA = "C:\\WINDOWS\\system32\\mspaint.exe " + BASEDIR + "\\Illustration\\IllustrationA.jpg";
	illuB = "C:\\WINDOWS\\system32\\mspaint.exe " + BASEDIR + "\\Illustration\\IllustrationB.jpg";
	illuC = "C:\\WINDOWS\\system32\\mspaint.exe " + BASEDIR + "\\Illustration\\IllustrationC.jpg";
	illuD = "C:\\WINDOWS\\system32\\mspaint.exe " + BASEDIR + "\\Illustration\\IllustrationD.jpg";
	illuE = "C:\\WINDOWS\\system32\\mspaint.exe " + BASEDIR + "\\Illustration\\IllustrationE.jpg";
*/
	// Show illustration by iexplore
	illuA = "C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE " + BASEDIR + "\\Illustration\\IllustrationA.jpg";
	illuB = "C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE " + BASEDIR + "\\Illustration\\IllustrationB.jpg";
	illuC = "C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE " + BASEDIR + "\\Illustration\\IllustrationC.jpg";
	illuD = "C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE " + BASEDIR + "\\Illustration\\IllustrationD.jpg";
	illuE = "C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE " + BASEDIR + "\\Illustration\\IllustrationE.jpg";

	// Show illustration by iexplore
	struA = "C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE " + BASEDIR + "\\Illustration\\StructureA.jpg";
	struB = "C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE " + BASEDIR + "\\Illustration\\StructureB.jpg";
	struC = "C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE " + BASEDIR + "\\Illustration\\StructureC.jpg";
	struD = "C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE " + BASEDIR + "\\Illustration\\StructureD.jpg";
	struE = "C:\\Program Files\\Internet Explorer\\IEXPLORE.EXE " + BASEDIR + "\\Illustration\\StructureE.jpg";

	// Call WinExec() function to show illustration
	UpdateData(TRUE);
	if(m_Structure == 0)
	{
//		WinExec(illuA,SW_MAXIMIZE);
		WinExec(illuA,SW_SHOW);
		WinExec(struA,SW_SHOW);
	}
	else if(m_Structure == 1)
	{
//		WinExec(illuB,SW_MAXIMIZE);
		WinExec(illuB,SW_SHOW);
		WinExec(struB,SW_SHOW);
	}
	else if(m_Structure == 2)
	{
//		WinExec(illuC,SW_MAXIMIZE);
		WinExec(illuC,SW_SHOW);
		WinExec(struC,SW_SHOW);
	}
	else if(m_Structure == 3)
	{
//		WinExec(illuD,SW_MAXIMIZE);
		WinExec(illuD,SW_SHOW);
		WinExec(struD,SW_SHOW);
	}
	else
	{
//		WinExec(illuE,SW_MAXIMIZE);
		WinExec(illuE,SW_SHOW);
		WinExec(struE,SW_SHOW);
	}
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"查看插补数据"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	以记事本的形式打开数据处理过程中生成的插补文件供用户查看。
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlViewInterpolation() 
{
	// TODO: Add your command handler code here
	CString viewintp;

	CString	msg, fileload;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	if(msg == "直线_LINE")
		viewintp = "C:\\Windows\\notepad.exe " + BASEDIR + FILEINTPL;
	else if(msg == "圆_CIRCLE")
		viewintp = "C:\\Windows\\notepad.exe " + BASEDIR + FILEINTPC;
	else
		viewintp = "C:\\Windows\\notepad.exe " + BASEDIR + FILEINTPH;

//	WinExec(viewintp,SW_MAXIMIZE);
	WinExec(viewintp,SW_SHOW);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"查看逆解数据"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//	以记事本的形式打开数据处理过程中生成的逆解文件供用户查看。
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlViewInvkine() 
{
	// TODO: Add your command handler code here
	CString viewinvk;

	CString	msg, fileload;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	if(msg == "直线_LINE")
		viewinvk = "C:\\Windows\\notepad.exe " + BASEDIR + FILEINVKL;
	else if(msg == "圆_CIRCLE")
		viewinvk = "C:\\Windows\\notepad.exe " + BASEDIR + FILEINVKC;
	else
		viewinvk = "C:\\Windows\\notepad.exe " + BASEDIR + FILEINVKH;

//	WinExec(viewinvk,SW_MAXIMIZE);
	WinExec(viewinvk,SW_SHOW);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"自动运行"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlAutoexecute() 
{
	// TODO: Add your command handler code here
	AfxMessageBox("这是一个预置功能按钮，有待进一步开发。");
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"加载NC代码"－函数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPmacCtrlDlg::OnCtrlLoadnc() 
{
	// TODO: Add your command handler code here
	AfxMessageBox("这是一个预置功能按钮，有待进一步开发。");
}

//					＝＝＝＝＝＝＝＝＝＝构型－菜单＝＝＝＝＝＝＝＝＝＝
//	菜单栏中的构型选项，选择某构型后，对话框中的构型选项相应改变。
//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝	
void CPmacCtrlDlg::OnStructureOne() 
{
	// TODO: Add your command handler code here
	char	paraEdit[10000];
	strcpy(paraEdit, "您选择的是：");
	strcat(paraEdit, "构型－1。\t\t\t");
	strcat(paraEdit, "---------------------------------");
	strcat(paraEdit, "静平台直径1485mm，距顶板底面84mm，6个铰链点的角度见图例；\t\t\t");
	strcat(paraEdit, "                                 ");
	strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例。\t\t");
	strcat(paraEdit, "                                 ");
	strcat(paraEdit, "各铰链点位置分布见图例。");

	// Show the parameter to the dialog
	m_StructureParaEdit.SetSel(0,-1);
	m_StructureParaEdit.ReplaceSel(paraEdit);

	// Renew which structure choice button is chosen
	m_Structure = 0;
	UpdateData(FALSE);	
}

void CPmacCtrlDlg::OnStructureTwo() 
{
	// TODO: Add your command handler code here
	char	paraEdit[10000];
	strcpy(paraEdit, "您选择的是：");
	strcat(paraEdit, "构型－2。\t\t\t");
	strcat(paraEdit, "---------------------------------");
	strcat(paraEdit, "静平台铰链点位于形心高度为357.25mm的正三角形上，距顶板底面84mm，见图例；\t\t\t\t");
	strcat(paraEdit, "                                     ");
	strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例；\t\t");
	strcat(paraEdit, "                                 ");
	strcat(paraEdit, "滑块中心平面的极限位置为136－350mm，见图例。");
	
	m_StructureParaEdit.SetSel(0,-1);
	m_StructureParaEdit.ReplaceSel(paraEdit);

	// Renew which structure choice button is chosen
	m_Structure = 1;
	UpdateData(FALSE);
}

void CPmacCtrlDlg::OnStructureThree() 
{
	// TODO: Add your command handler code here
	char	paraEdit[10000];
	strcpy(paraEdit, "您选择的是：");
	strcat(paraEdit, "构型－3。\t\t\t");
	strcat(paraEdit, "---------------------------------");
	strcat(paraEdit, "静平台直径1109.02mm，距顶板底面84mm，6个铰链点的角度见图例；\t\t");
	strcat(paraEdit, "                                 ");
	strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例。\t\t");
	strcat(paraEdit, "                                 ");
	strcat(paraEdit, "各铰链点位置分布见图例。");
	
	m_StructureParaEdit.SetSel(0,-1);
	m_StructureParaEdit.ReplaceSel(paraEdit);

	// Renew which structure choice button is chosen
	m_Structure = 2;
	UpdateData(FALSE);
}

void CPmacCtrlDlg::OnStructureFour() 
{
	// TODO: Add your command handler code here
	char	paraEdit[10000];
	strcpy(paraEdit, "您选择的是：");
	strcat(paraEdit, "构型－4。\t\t\t");
	strcat(paraEdit, "---------------------------------");
	strcat(paraEdit, "静平台直径1101mm，距顶板底面84mm，3个铰链点的角度见图例；\t\t\t");
	strcat(paraEdit, "                                 ");
	strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，3个铰链点的角度见图例。\t\t");
	strcat(paraEdit, "                                 ");
	strcat(paraEdit, "各铰链点位置分布见图例。");
		
	m_StructureParaEdit.SetSel(0,-1);
	m_StructureParaEdit.ReplaceSel(paraEdit);

	// Renew which structure choice button is chosen
	m_Structure = 3;
	UpdateData(FALSE);
}

void CPmacCtrlDlg::OnStructureFive() 
{
	// TODO: Add your command handler code here
	char	paraEdit[10000];
	strcpy(paraEdit, "您选择的是：");
	strcat(paraEdit, "构型－5。\t\t\t");
	strcat(paraEdit, "---------------------------------");
	strcat(paraEdit, "静平台直径1485mm，距顶板底面84mm，6个铰链点的角度见图例；\t\t\t");
	strcat(paraEdit, "                                 ");
	strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例。\t\t");
	strcat(paraEdit, "                                 ");
	strcat(paraEdit, "各铰链点位置分布见图例。");

	m_StructureParaEdit.SetSel(0,-1);
	m_StructureParaEdit.ReplaceSel(paraEdit);

	// Renew which structure choice button is chosen
	m_Structure = 4;
	UpdateData(FALSE);
}

//					＝＝＝＝＝＝＝＝＝＝帮助－菜单＝＝＝＝＝＝＝＝＝＝

void CPmacCtrlDlg::OnHelpAbout() 
{
	// TODO: Add your command handler code here
	// Define variable dlgAbout belong to CAboutDlg class
	CAboutDlg	dlgAbout;
	dlgAbout.DoModal();
}

void CPmacCtrlDlg::OnHelpHelp() 
{
	// TODO: Add your command handler code here
	//AfxMessageBox(" Help documents are developing ! ");	
	CString help;
	help = "C:\\Windows\\notepad.exe .\\Help.txt";
//	WinExec(help,SW_MAXIMIZE);
	WinExec(help,SW_SHOW);
}

//		*****************************对话框窗口控件*******************************

//	========================="构型选择"单选RADIO－函数==============================
//	选中某一单选框后，在构型参数显示框内显示相应的构型参数
//	================================================================================
void CPmacCtrlDlg::OnStructure1RADIO() 
{
	// TODO: Add your control notification handler code here
	// Output structure parameter in structure parameter edit box
	char	paraEdit[10000];
	int		iStructureRADIO;
	iStructureRADIO = GetCheckedRadioButton(IDC_Structure1_RADIO,IDC_Structure5_RADIO);
	strcpy(paraEdit, "您选择的是：");
	if(iStructureRADIO == IDC_Structure1_RADIO)
	{
		strcat(paraEdit, "构型－1。\t\t\t");
		strcat(paraEdit, "---------------------------------");
		strcat(paraEdit, "静平台直径1485mm，距顶板底面84mm，6个铰链点的角度见图例；\t\t\t");
		strcat(paraEdit, "                                 ");
		strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例。\t\t");
		strcat(paraEdit, "                                 ");
		strcat(paraEdit, "各铰链点位置分布见图例。");
	}
	else if(iStructureRADIO == IDC_Structure2_RADIO)
	{
		strcat(paraEdit, "构型－2。\t\t\t");
		strcat(paraEdit, "---------------------------------");
		strcat(paraEdit, "静平台铰链点位于形心高度为357.25mm的正三角形上，距顶板底面84mm，见图例；\t\t\t\t");
		strcat(paraEdit, "                                     ");
		strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例；\t\t");
		strcat(paraEdit, "                                 ");
		strcat(paraEdit, "滑块中心平面的极限位置为136－350mm，见图例。");
	}
	else if(iStructureRADIO == IDC_Structure3_RADIO)
	{
		strcat(paraEdit, "构型－3。\t\t\t");
		strcat(paraEdit, "---------------------------------");
		strcat(paraEdit, "静平台直径1109.02mm，距顶板底面84mm，6个铰链点的角度见图例；\t\t");
		strcat(paraEdit, "                                 ");
		strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例。\t\t");
		strcat(paraEdit, "                                 ");
		strcat(paraEdit, "各铰链点位置分布见图例。");
	}
	else if(iStructureRADIO == IDC_Structure4_RADIO)
	{
		strcat(paraEdit, "构型－4。\t\t\t");
		strcat(paraEdit, "---------------------------------");
		strcat(paraEdit, "静平台直径1101mm，距顶板底面84mm，3个铰链点的角度见图例；\t\t\t");
		strcat(paraEdit, "                                 ");
		strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，3个铰链点的角度见图例。\t\t");
		strcat(paraEdit, "                                 ");
		strcat(paraEdit, "各铰链点位置分布见图例。");
	}
	else
	{
		strcat(paraEdit, "构型－5。\t\t\t");
		strcat(paraEdit, "---------------------------------");
		strcat(paraEdit, "静平台直径1485mm，距顶板底面84mm，6个铰链点的角度见图例；\t\t\t");
		strcat(paraEdit, "                                 ");
		strcat(paraEdit, "动平台直径340mm，距动平台顶面61.5mm，6个铰链点的角度见图例。\t\t");
		strcat(paraEdit, "                                 ");
		strcat(paraEdit, "各铰链点位置分布见图例。");
	}
	m_StructureParaEdit.SetSel(0,-1);
	m_StructureParaEdit.ReplaceSel(paraEdit);
}

void CPmacCtrlDlg::OnStructure2RADIO() 
{
	// TODO: Add your control notification handler code here
	CPmacCtrlDlg::OnStructure1RADIO();	
}

void CPmacCtrlDlg::OnStructure3RADIO() 
{
	// TODO: Add your control notification handler code here
	CPmacCtrlDlg::OnStructure1RADIO();	
}

void CPmacCtrlDlg::OnStructure4RADIO() 
{
	// TODO: Add your control notification handler code here
	CPmacCtrlDlg::OnStructure1RADIO();	
}

void CPmacCtrlDlg::OnStructure5RADIO() 
{
	// TODO: Add your control notification handler code here
	CPmacCtrlDlg::OnStructure1RADIO();	
}

//	============================="轨迹选择"组合框－函数================================
//	选择某一轨迹后，将其对应的参数编辑框激活，其他参数编辑框锁定。
//	===================================================================================	
void CPmacCtrlDlg::OnSelchangeComboChoice() 
{
	// TODO: Add your control notification handler code here
	CString msg;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	// if LINE is chosen, enable Line parameter input zone,
	// disable other parameter input zone
	if(msg == "直线_LINE")
	{
		GetDlgItem(IDC_SX_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SY_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SZ_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SA_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SB_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_EX_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_EY_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_EZ_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_EA_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_EB_EDIT)->EnableWindow(TRUE);

		GetDlgItem(IDC_SR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SANG_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SCPX_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SCPY_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SCPZ_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ER_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EANG_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ECPX_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ECPY_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ECPZ_EDIT)->EnableWindow(FALSE);
	}

	// if CIRCLE is chosen, enable circle parameter input zone,
	// disable other parameter input zone
	else if(msg == "圆_CIRCLE")
	{
		GetDlgItem(IDC_SX_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SY_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SZ_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SA_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SB_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EX_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EY_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EZ_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EA_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EB_EDIT)->EnableWindow(FALSE);

		GetDlgItem(IDC_ER_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ECPX_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ECPY_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ECPZ_EDIT)->EnableWindow(FALSE);

		GetDlgItem(IDC_SR_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SANG_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SCPX_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SCPY_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SCPZ_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_EANG_EDIT)->EnableWindow(TRUE);

		UpdateData(TRUE);
		m_SrEdit = 0;		m_ErEdit = m_SrEdit;
		m_SangEdit = 0;		m_EangEdit = 0;
		m_ScpxEdit = 0;		m_EcpxEdit = m_ScpxEdit;
		m_ScpyEdit = 0;		m_EcpyEdit = m_ScpyEdit;
		m_ScpzEdit = 0;		m_EcpzEdit = m_ScpzEdit;
		UpdateData(FALSE);		
	}

	// if HELIX is chosen, enable helix parameter input zone,
	// disable other parameter input zone
	else
	{
		GetDlgItem(IDC_SX_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SY_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SZ_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SA_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_SB_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EX_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EY_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EZ_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EA_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EB_EDIT)->EnableWindow(FALSE);

		GetDlgItem(IDC_SR_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SANG_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SCPX_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SCPY_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_SCPZ_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_ER_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_EANG_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_ECPX_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_ECPY_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_ECPZ_EDIT)->EnableWindow(TRUE);

		UpdateData(TRUE);
		m_SrEdit = 0;		m_ErEdit = 0;		
		m_SangEdit = 0;		m_EangEdit = 0;
		m_ScpxEdit = 0;		m_EcpxEdit = 0;
		m_ScpyEdit = 0;		m_EcpyEdit = 0;
		m_ScpzEdit = 0;		m_EcpzEdit = 0;
		UpdateData(FALSE);
	}
}

//	============================="默认"按钮－函数================================
//	对应于"菜单－默认数据"
//	=============================================================================
void CPmacCtrlDlg::OnDefault() 
{
	CPmacCtrlDlg::OnFileDefault();
}

//	============================="保存"按钮－函数================================
void CPmacCtrlDlg::OnSave() 
{
	CPmacCtrlDlg::OnFileSave();
}

//	============================="确定"按钮－函数================================
//	对应于"控制－数据处理"
//	=============================================================================
void CPmacCtrlDlg::OnConfirm() 
{
	CPmacCtrlDlg::OnCtrlProcess();
}

//	============================="退出"按键－函数================================
void CPmacCtrlDlg::OnExit() 
{
	CPmacCtrlDlg::OnFileExit();
}

//	============================="初始化PMAC"－按钮================================
void CPmacCtrlDlg::OnInitial() 
{
	CPmacCtrlDlg::OnCtrlInitial();
}

//	============================="机床归零"－按钮================================
void CPmacCtrlDlg::OnZero() 
{
	CPmacCtrlDlg::OnCtrlZero();	
}

//	============================="零点偏移"－按钮================================
void CPmacCtrlDlg::OnExcursion() 
{
	CPmacCtrlDlg::OnCtrlExcursion();
}

//	============================="文件下载"按键－函数================================
void CPmacCtrlDlg::OnLoadfile() 
{
	CPmacCtrlDlg::OnCtrlLoadfile();	
}

//	============================="执行程序"－按钮================================
void CPmacCtrlDlg::OnExecute() 
{
	CPmacCtrlDlg::OnCtrlExecute();
}

//	============================="显示构型图例"－函数================================
void CPmacCtrlDlg::OnShowBUTTON() 
{
	CPmacCtrlDlg::OnCtrlOutputphoto();
}

//	============================="输出构型参数"－函数================================
void CPmacCtrlDlg::OnOutputpara() 
{
	CPmacCtrlDlg::OnCtrlOutputpara();
}

//	============================="查看插补数据"－函数================================
void CPmacCtrlDlg::OnViewInterpolation() 
{
	CPmacCtrlDlg::OnCtrlViewInterpolation();
}

//	============================="查看逆解数据"－函数================================
void CPmacCtrlDlg::OnViewInvkine() 
{
	CPmacCtrlDlg::OnCtrlViewInvkine();
}

//	============================="加载NC代码"按钮－函数================================
void CPmacCtrlDlg::OnLoadnc() 
{
	CPmacCtrlDlg::OnCtrlLoadnc();
}

//	============================="自动运行"按钮－函数================================
void CPmacCtrlDlg::OnAutoexecute() 
{
	CPmacCtrlDlg::OnCtrlAutoexecute();
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝"Linear Interpolation"＝＝＝＝＝＝＝＝＝＝＝＝＝＝

void CPmacCtrlDlg::OnCtrlInterpolationL() 
{
	double	Vmax = 200, Amax = 500;	//	unit: mm/s, mm/s2;
	double	dt = 0.02;				//	unit: s;
	double	dx, dy, dz, da, db, dmax;
	double	ta, tr, tt, T;
	double	vx, vy, vz, wa, wb, ax, ay, az, ea, eb;
	double	Inx, Iny, Inz, Ina, Inb, Ing;

	UpdateData(TRUE);
	dx = m_ExEdit - m_SxEdit;
	dy = m_EyEdit - m_SyEdit;
	dz = m_EzEdit - m_SzEdit;
	da = m_EaEdit*pi/180 - m_SaEdit*pi/180;
	db = m_EbEdit*pi/180 - m_SbEdit*pi/180;
	dmax = max(max(fabs(dx),fabs(dy)),fabs(dz));

	ta = Vmax/Amax;
	tr = dmax/Vmax - ta;
	tt = tr + 2*ta;

	vx = dx/(ta+tr);	ax = vx/ta;
	vy = dy/(ta+tr);	ay = vy/ta;
	vz = dz/(ta+tr);	az = vz/ta;
	wa = da/(ta+tr);	ea = wa/ta;
	wb = db/(ta+tr);	eb = wb/ta;

	FILE	*fp1, *fp2;
	FILE	*fp;
	fp1 = fopen(BASEDIR+FILEINTPL, "w+");	
	fp2 = fopen(BASEDIR+FILEINVKL, "w+");
	fp  = fopen(BASEDIR+FILEPMACL, "w+");
	fprintf(fp1, "*************插补数据*************\n");
	fprintf(fp1, "-----------------------------------------------------------\n");
	fprintf(fp2, "*************逆解数据*************\n");
	fprintf(fp2, "-----------------------------------------------------------\n");
	fprintf(fp, "\nOPEN PROG 10\nCLEAR\nABS\nF10\nLINEAR\n");
	for(int i=0; i<tt/dt+1; i++)
	{
		T = i*dt;
		if(T < ta)
		{
			Inx = m_SxEdit + 0.5*ax*T*T;
			Iny = m_SyEdit + 0.5*ay*T*T;
			Inz = m_SzEdit + 0.5*az*T*T;
			Ina = m_SaEdit + 0.5*ea*T*T;
			Inb = m_SbEdit + 0.5*eb*T*T;
			Ing = 0;
			fprintf(fp1, "X %.3f Y %.3f Z %.3f A %.3f B %.3f G %.3f\n", Inx,Iny,Inz,Ina,Inb,Ing);
			if(m_Structure == 0)
				CPmacCtrlDlg::OnCtrlInvkineA(Inx, Iny, Inz, Ina, Inb, Ing);
			else if(m_Structure == 1)
				CPmacCtrlDlg::OnCtrlInvkineB(Inx, Iny, Inz, Ina, Inb, Ing);
			else if(m_Structure == 2)
				CPmacCtrlDlg::OnCtrlInvkineC(Inx, Iny, Inz, Ina, Inb, Ing);
			else if(m_Structure == 3)
				CPmacCtrlDlg::OnCtrlInvkineD(Inx, Iny, Inz, Ina, Inb, Ing);
			else
				CPmacCtrlDlg::OnCtrlInvkineE(Inx, Iny, Inz, Ina, Inb, Ing);
			if(dl1 > 180 || dl2 > 180 || dl3 > 180 || dl4 > 180 || dl5 > 180 || dl6 > 180)
				goto quota;
			fprintf(fp2, "X %.3f Y %.3f Z %.3f U %.3f V %.3f W %.3f\n", -dl6,-dl5,-dl2,-dl1,-dl4,-dl3);
			fprintf(fp, "X %.3f Y %.3f Z %.3f U %.3f V %.3f W %.3f\n", -dl6,-dl5,-dl2,-dl1,-dl4,-dl3);
		}
		else if(T < (tt-ta))
		{
			Inx = m_SxEdit + 0.5*ax*T*T + vx*(T-ta);
			Iny = m_SyEdit + 0.5*ay*T*T + vy*(T-ta);
			Inz = m_SzEdit + 0.5*az*T*T + vz*(T-ta);
			Ina = m_SaEdit + 0.5*ea*T*T + wa*(T-ta);
			Inb = m_SbEdit + 0.5*eb*T*T + wb*(T-ta);
			Ing = 0;
			fprintf(fp1, "X %.3f Y %.3f Z %.3f A %.3f B %.3f G %.3f\n", Inx,Iny,Inz,Ina,Inb,Ing);
			if(m_Structure == 0)
				CPmacCtrlDlg::OnCtrlInvkineA(Inx, Iny, Inz, Ina, Inb, Ing);
			else if(m_Structure == 1)
				CPmacCtrlDlg::OnCtrlInvkineB(Inx, Iny, Inz, Ina, Inb, Ing);
			else if(m_Structure == 2)
				CPmacCtrlDlg::OnCtrlInvkineC(Inx, Iny, Inz, Ina, Inb, Ing);
			else if(m_Structure == 3)
				CPmacCtrlDlg::OnCtrlInvkineD(Inx, Iny, Inz, Ina, Inb, Ing);
			else
				CPmacCtrlDlg::OnCtrlInvkineE(Inx, Iny, Inz, Ina, Inb, Ing);
			if(dl1 > 180 || dl2 > 180 || dl3 > 180 || dl4 > 180 || dl5 > 180 || dl6 > 180)
				goto quota;
			fprintf(fp2, "X %.3f Y %.3f Z %.3f U %.3f V %.3f W %.3f\n", -dl6,-dl5,-dl2,-dl1,-dl4,-dl3);
			fprintf(fp, "X %.3f Y %.3f Z %.3f U %.3f V %.3f W %.3f\n", -dl6,-dl5,-dl2,-dl1,-dl4,-dl3);
		}
		else
		{
			Inx = m_ExEdit - 0.5*ax*(tt-T)*(tt-T);
			Iny = m_EyEdit - 0.5*ay*(tt-T)*(tt-T);
			Inz = m_EzEdit - 0.5*az*(tt-T)*(tt-T);
			Ina = m_EaEdit - 0.5*ea*(tt-T)*(tt-T);
			Inb = m_EbEdit - 0.5*eb*(tt-T)*(tt-T);
			Ing = 0;
			fprintf(fp1, "X %.3f Y %.3f Z %.3f A %.3f B %.3f G %.3f\n", Inx,Iny,Inz,Ina,Inb,Ing);
			if(m_Structure == 0)
				CPmacCtrlDlg::OnCtrlInvkineA(Inx, Iny, Inz, Ina, Inb, Ing);
			else if(m_Structure == 1)
				CPmacCtrlDlg::OnCtrlInvkineB(Inx, Iny, Inz, Ina, Inb, Ing);
			else if(m_Structure == 2)
				CPmacCtrlDlg::OnCtrlInvkineC(Inx, Iny, Inz, Ina, Inb, Ing);
			else if(m_Structure == 3)
				CPmacCtrlDlg::OnCtrlInvkineD(Inx, Iny, Inz, Ina, Inb, Ing);
			else
				CPmacCtrlDlg::OnCtrlInvkineE(Inx, Iny, Inz, Ina, Inb, Ing);
			if(dl1 > 180 || dl2 > 180 || dl3 > 180 || dl4 > 180 || dl5 > 180 || dl6 > 180)
				goto quota;
			fprintf(fp2, "X %.3f Y %.3f Z %.3f U %.3f V %.3f W %.3f\n", -dl6,-dl5,-dl2,-dl1,-dl4,-dl3);
			fprintf(fp, "X %.3f Y %.3f Z %.3f U %.3f V %.3f W %.3f\n", -dl6,-dl5,-dl2,-dl1,-dl4,-dl3);
		}
	}
	fprintf(fp,"CLOSE\n");
	goto	normal;
quota:	AfxMessageBox("给出轨迹参数超出机床的运动空间，请更改参数！");
normal:	fclose(fp1);
	fclose(fp2);
	fclose(fp);
	UpdateData(FALSE);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"Circle Interpolation"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

void CPmacCtrlDlg::OnCtrlInterpolationC()
{
	double	dt = 0.03, tt, T, rad = pi/180;
	double	AngVel = 200*rad;
	double	Xd[3] = {1, 0, 0}, Yd[3] = {0, 1, 0};	// Orientation;
	double	R, Ang, CInx, CIny, CInz, CIna, CInb, CIng;

	UpdateData(TRUE);
	R = m_SrEdit;
	tt = (m_EangEdit - m_SangEdit)/AngVel;
	
	FILE	*fp1, *fp2;
	FILE	*fp;
	fp1 = fopen(BASEDIR + FILEINTPC, "w+"); 
	fp2 = fopen(BASEDIR + FILEINVKC, "w+");
	fp =  fopen(BASEDIR + FILEPMACC, "w+");
	fprintf(fp1, "*************插补数据*************\n");
	fprintf(fp1, "-----------------------------------------------------------\n");
	fprintf(fp2, "*************逆解数据*************\n");
	fprintf(fp2, "-----------------------------------------------------------\n");
	fprintf(fp, "\nOPEN PROG 10\nCLEAR\nABS\nF10\nLINEAR\n");
	for(int i=0; i<tt/dt+1; i++)
	{
		T = i*dt;
		Ang = T*AngVel + m_SangEdit;
		CInx = m_ScpxEdit + R*Xd[0]*cos(Ang) + R*Yd[0]*sin(Ang);
		CIny = m_ScpyEdit + R*Xd[1]*cos(Ang) + R*Yd[1]*sin(Ang);
		CInz = m_ScpzEdit + R*Xd[2]*cos(Ang) + R*Yd[2]*sin(Ang);
		CIna = 0;
		CInb = 0;
		CIng = 0;
		fprintf(fp1, "X %.3f Y %.3f Z %.3f A %.3f B %.3f G %.3f\n", CInx,CIny,CInz,CIna,CInb,CIng);
		if(m_Structure == 0)
			CPmacCtrlDlg::OnCtrlInvkineA(CInx, CIny, CInz, CIna, CInb, CIng);
		else if(m_Structure == 1)
			CPmacCtrlDlg::OnCtrlInvkineB(CInx, CIny, CInz, CIna, CInb, CIng);
		else if(m_Structure == 2)
			CPmacCtrlDlg::OnCtrlInvkineC(CInx, CIny, CInz, CIna, CInb, CIng);
		else if(m_Structure == 3)
			CPmacCtrlDlg::OnCtrlInvkineD(CInx, CIny, CInz, CIna, CInb, CIng);
		else
			CPmacCtrlDlg::OnCtrlInvkineE(CInx, CIny, CInz, CIna, CInb, CIng);
		if(dl1 > 180 || dl2 > 180 || dl3 > 180 || dl4 > 180 || dl5 > 180 || dl6 > 180)
			goto quota;
		fprintf(fp2, "X %.3f Y %.3f Z %.3f U %.3f V %.3f W %.3f\n", -dl6,-dl5,-dl2,-dl1,-dl4,-dl3);
		fprintf(fp, "X %.3f Y %.3f Z %.3f U %.3f V %.3f W %.3f\n", -dl6,-dl5,-dl2,-dl1,-dl4,-dl3);
	}
	fprintf(fp,"CLOSE\n");
	goto	normal;
quota:	AfxMessageBox("给出轨迹参数超出机床的运动空间，请更改参数！");
normal:	fclose(fp1);
	fclose(fp2);
	fclose(fp);
	UpdateData(FALSE);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"Helix Interpolation"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

void CPmacCtrlDlg::OnCtrlInterpolationH()
{
	double	dt = 0.03, tt, T, rad = pi/180;
	double	AngVel = 200*rad;
	double	Xd[3] = {1, 0, 0}, Yd[3] = {0, 1, 0};	// Orientation;
	double	R, Ang, Xv, Yv, Zv;
	double	HInx, HIny, HInz, HIna, HInb, HIng;

	UpdateData(TRUE);
	tt = (m_EangEdit - m_SangEdit)/AngVel;
	Xv = (m_EcpxEdit - m_ScpxEdit)/tt;
	Yv = (m_EcpyEdit - m_ScpyEdit)/tt;
	Zv = (m_EcpzEdit - m_ScpzEdit)/tt;
	
	FILE	*fp1, *fp2;
	FILE	*fp;
	fp1 = fopen(BASEDIR + FILEINTPH, "w+"); 
	fp2 = fopen(BASEDIR + FILEINVKH, "w+");
	fp =  fopen(BASEDIR + FILEPMACH, "w+");
	fprintf(fp1, "*************插补数据*************\n");
	fprintf(fp1, "-----------------------------------------------------------\n");
	fprintf(fp2, "*************逆解数据*************\n");
	fprintf(fp2, "-----------------------------------------------------------\n");
	fprintf(fp, "\nOPEN PROG 10\nCLEAR\nABS\nF10\nLINEAR\n");
	for(int i=0; i<tt/dt+1; i++)
	{
		T = i*dt;
		R = m_SrEdit + T*((m_ErEdit - m_SrEdit)/tt);
		Ang = T*AngVel + m_SangEdit;
		HInx = m_ScpxEdit + R*Xd[0]*cos(Ang) + R*Yd[0]*sin(Ang) + Xv*T;
		HIny = m_ScpyEdit + R*Xd[1]*cos(Ang) + R*Yd[1]*sin(Ang) + Yv*T;
		HInz = m_ScpzEdit + R*Xd[2]*cos(Ang) + R*Yd[2]*sin(Ang) + Zv*T;
		HIna = 0;
		HInb = 0;
		HIng = 0;
		fprintf(fp1, "X %.3f Y %.3f Z %.3f A %.3f B %.3f G %.3f\n", HInx,HIny,HInz,HIna,HInb,HIng);
		if(m_Structure == 0)
			CPmacCtrlDlg::OnCtrlInvkineA(HInx, HIny, HInz, HIna, HInb, HIng);
		else if(m_Structure == 1)
			CPmacCtrlDlg::OnCtrlInvkineB(HInx, HIny, HInz, HIna, HInb, HIng);
		else if(m_Structure == 2)
			CPmacCtrlDlg::OnCtrlInvkineC(HInx, HIny, HInz, HIna, HInb, HIng);
		else if(m_Structure == 3)
			CPmacCtrlDlg::OnCtrlInvkineD(HInx, HIny, HInz, HIna, HInb, HIng);
		else
			CPmacCtrlDlg::OnCtrlInvkineE(HInx, HIny, HInz, HIna, HInb, HIng);
		if(dl1 > 180 || dl2 > 180 || dl3 > 180 || dl4 > 180 || dl5 > 180 || dl6 > 180)
			goto quota;
		fprintf(fp2, "X %.3f Y %.3f Z %.3f U %.3f V %.3f W %.3f\n", -dl6,-dl5,-dl2,-dl1,-dl4,-dl3);
		fprintf(fp, "X %.3f Y %.3f Z %.3f U %.3f V %.3f W %.3f\n", -dl6,-dl5,-dl2,-dl1,-dl4,-dl3);
	}
	fprintf(fp,"CLOSE\n");
	goto	normal;
quota:	AfxMessageBox("给出轨迹参数超出机床的运动空间，请更改参数！");
normal:	fclose(fp1);
	fclose(fp2);
	fclose(fp);
	UpdateData(FALSE);
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"Inverse Kinematics A"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

void CPmacCtrlDlg::OnCtrlInvkineA(double x,double y,double z,double a,double b,double g)
{
	double	Ltz=788, rb=742.5, r=170;
	double	rad=pi/180;
	double	B[3][6], A1[3][6], R[3][3], T[3][1], A[3][6], C[3][6], L[6];
	double	sa, ca, sb, cb, sg, cg;
	// U joint coordinate on the base reference
	B[0][0] = rb*sin(15*rad);	B[0][1] = -rb*sin(15*rad);	B[0][2] = -rb*cos(15*rad);
	B[0][3] = -rb*sin(45*rad);	B[0][4] = rb*sin(45*rad);	B[0][5] = rb*cos(15*rad);
	B[1][0] = -rb*cos(15*rad);	B[1][1] = -rb*cos(15*rad);	B[1][2] = rb*sin(15*rad);
	B[1][3] = rb*cos(45*rad);	B[1][4] = rb*cos(45*rad);	B[1][5] = rb*sin(15*rad);
	B[2][0] = -84;				B[2][1] = -84;				B[2][2] = -84;
	B[2][3] = -84;				B[2][4] = -84;				B[2][5] = -84;
	// S joint coordinate on the mobile reference
	A1[0][0] = r*sin(28.25*rad);	A1[0][1] = -r*sin(28.25*rad);	A1[0][2] = -r*cos(1.75*rad);
	A1[0][3] = -r*sin(31.75*rad);	A1[0][4] = r*sin(31.75*rad);	A1[0][5] = r*cos(1.75*rad);
	A1[1][0] = -r*cos(28.25*rad);	A1[1][1] = -r*cos(28.25*rad);	A1[1][2] = r*sin(1.75*rad);
	A1[1][3] = r*cos(31.75*rad);	A1[1][4] = r*cos(31.75*rad);	A1[1][5] = r*sin(1.75*rad);
	A1[2][0] = 61.5;				A1[2][1] = 61.5;				A1[2][2] = 61.5;
	A1[2][3] = 61.5;				A1[2][4] = 61.5;				A1[2][5] = 61.5;
	// Rotation matrix
	sa=sin(a);	ca=cos(a);	sb=sin(b);	cb=cos(b);	sg=sin(g);	cg=cos(g);
	R[0][0] = cg*cb;	R[0][1] = cg*sb*sa-sg*ca;	R[0][2] = cg*sb*ca+sg*sa;
	R[1][0] = sg*cb;	R[1][1] = sg*sb*sa+cg*ca;	R[1][2] = sg*sb*ca-cg*sa;
	R[2][0] = -sb;		R[2][1] = cb*sa;			R[2][2] = cb*ca;
	// T joint coordinate on the mobile reference
	T[0][0] = x;	T[1][0] = y;	T[2][0] = z;

	for(int i=0; i<3; i++)
		for(int j=0; j<6; j++)
			A[i][j] = R[i][0]*A1[0][j]+R[i][1]*A1[1][j]+R[i][2]*A1[2][j];

	for(int k=0; k<6; k++)
	{
		A[0][k] = A[0][k] + T[0][0];
		A[1][k] = A[1][k] + T[1][0];
		A[2][k] = A[2][k] + T[2][0];
		C[0][k] = B[0][k] - A[0][k];
		C[1][k] = B[1][k] - A[1][k];
		C[2][k] = B[2][k] - A[2][k];
		L[k] = sqrt(C[0][k]*C[0][k]+C[1][k]*C[1][k]+C[2][k]*C[2][k]);
	}
	dl1 = L[0] - Ltz;	dl2 = L[1] - Ltz;	dl3 = L[2] - Ltz;
	dl4 = L[3] - Ltz;	dl5 = L[4] - Ltz;	dl6 = L[5] - Ltz;
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"Inverse Kinematics B"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

void CPmacCtrlDlg::OnCtrlInvkineB(double x,double y,double z,double a,double b,double g)
{
	double	Lmz=322.25, Lcst=500, h=357.25, r=170, zi=-145.5;
	double	rad=pi/180;
	double	A1[3][6], R[3][3], T[3][1], A[3][6], L[6];
	double	sa, ca, sb, cb, sg, cg;
	double	s=sin(30*rad), c=cos(30*rad); 
	// S joint coordinate on the mobile reference
	A1[0][0] = -r*sin(31.75*rad);	A1[0][1] = r*sin(31.75*rad);	A1[0][2] = r*cos(1.75*rad);
	A1[0][3] = r*cos(61.75*rad);	A1[0][4] = -r*cos(61.75*rad);	A1[0][5] = -r*cos(1.75*rad);
	A1[1][0] = r*cos(31.75*rad);	A1[1][1] = r*cos(31.75*rad);	A1[1][2] = r*sin(1.75*rad);
	A1[1][3] = -r*sin(61.75*rad);	A1[1][4] = -r*sin(61.75*rad);	A1[1][5] = r*sin(1.75*rad);
	A1[2][0] = 61.5;				A1[2][1] = 61.5;				A1[2][2] = 61.5;
	A1[2][3] = 61.5;				A1[2][4] = 61.5;				A1[2][5] = 61.5;
	// Rotation matrix
	sa=sin(a);	ca=cos(a);	sb=sin(b);	cb=cos(b);	sg=sin(g);	cg=cos(g);
	R[0][0] = cg*cb;	R[0][1] = cg*sb*sa-sg*ca;	R[0][2] = cg*sb*ca+sg*sa;
	R[1][0] = sg*cb;	R[1][1] = sg*sb*sa+cg*ca;	R[1][2] = sg*sb*ca-cg*sa;
	R[2][0] = -sb;		R[2][1] = cb*sa;			R[2][2] = cb*ca;
	// T joint coordinate on the mobile reference
	T[0][0] = x;	T[1][0] = y;	T[2][0] = z;

	for(int i=0; i<3; i++)
		for(int j=0; j<6; j++)
			A[i][j] = R[i][0]*A1[0][j]+R[i][1]*A1[1][j]+R[i][2]*A1[2][j];

	for(int k=0; k<6; k++)
	{
		A[0][k] = A[0][k] + T[0][0];
		A[1][k] = A[1][k] + T[1][0];
		A[2][k] = A[2][k] + T[2][0];
	}
	L[0]=CPmacCtrlDlg::OnGetRoot(1,-2*(Lmz+A[0][0]),(A[0][0]+Lmz)*(A[0][0]+Lmz)+(A[1][0]-h)*
		(A[1][0]-h)+(A[2][0]-zi)*(A[2][0]-zi)-Lcst*Lcst,-1);
	L[1]=CPmacCtrlDlg::OnGetRoot(1,-2*(Lmz-A[0][1]),(A[0][1]-Lmz)*(A[0][1]-Lmz)+(A[1][1]-h)*
		(A[1][1]-h)+(A[2][1]-zi)*(A[2][1]-zi)-Lcst*Lcst,-1);
	L[2]=CPmacCtrlDlg::OnGetRoot(1,-2*(Lmz*s+h*c-A[0][2])*s-2*(Lmz*c-h*s-A[1][2])*c,A[0][2]*
		A[0][2]+(Lmz*s+h*c)*(Lmz*s+h*c)-2*A[0][2]*(Lmz*s+h*c)+A[1][2]*A[1][2]+(Lmz*c-h*s)*
		(Lmz*c-h*s)-2*A[1][2]*(Lmz*c-h*s)+(A[2][2]-zi)*(A[2][2]-zi)-Lcst*Lcst,-1);
	L[3]=CPmacCtrlDlg::OnGetRoot(1,2*(-Lmz*s+h*c-A[0][3])*s-2*(Lmz*c+h*s+A[1][3])*c,A[0][3]*
		A[0][3]+(-Lmz*s+h*c)*(-Lmz*s+h*c)-2*A[0][3]*(-Lmz*s+h*c)+A[1][3]*A[1][3]+(-Lmz*c-h*s)*
		(-Lmz*c-h*s)-2*A[1][3]*(-Lmz*c-h*s)+(A[2][3]-zi)*(A[2][3]-zi)-Lcst*Lcst,-1);
	L[4]=CPmacCtrlDlg::OnGetRoot(1,2*(A[0][4]-Lmz*s+h*c)*s-2*(A[1][4]+Lmz*c+h*s)*c,(A[0][4]-
		Lmz*s+h*c)*(A[0][4]-Lmz*s+h*c)+(A[1][4]+Lmz*c+h*s)*(A[1][4]+Lmz*c+h*s)+(A[2][4]-zi)*
		(A[2][4]-zi)-Lcst*Lcst,-1);
	L[5]=CPmacCtrlDlg::OnGetRoot(1,-2*(A[0][5]+Lmz*s+h*c)*s+2*(A[1][5]-Lmz*c+h*s)*c,(A[0][5]+
		Lmz*s+h*c)*(A[0][5]+Lmz*s+h*c)+(A[1][5]-Lmz*c+h*s)*(A[1][5]-Lmz*c+h*s)+(A[2][5]-zi)*
		(A[2][5]-zi)-Lcst*Lcst,-1);
	dl1 = L[0];	dl2 = L[1];	dl3 = L[2];	dl4 = L[3];	dl5 = L[4];	dl6 = L[5];
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"GetRoot"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

double CPmacCtrlDlg::OnGetRoot(double a, double b, double c, int sign)
{
	// x=(-b+sign*sqrt(b^2-4*a*c))/(2*a);
	double result;
	if((b*b-4*a*c) < 0)
		result = -b/(2*a);
	else
		result = (-b+sign*sqrt(b*b-4*a*c))/(2*a);	
	return result;
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"Inverse Kinematics C"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

void CPmacCtrlDlg::OnCtrlInvkineC(double x,double y,double z,double a,double b,double g)
{
	double	Ltz=-355.5, Lcst=500, rb=1119.02/2, r=361.5/2;
	double	rad=pi/180;
	double	B[2][6], A1[3][6], R[3][3], T[3][1], A[3][6], L[6];
	double	sa, ca, sb, cb, sg, cg;
	// U joint coordinate on the base reference
	B[0][0] = rb*cos(49.705*rad);	B[0][1] = rb*cos(49.705*rad);	B[0][2] = rb*sin(19.705*rad);
	B[0][3] = -rb*sin(79.705*rad);	B[0][4] = -rb*sin(79.705*rad);	B[0][5] = rb*sin(19.705*rad);
	B[1][0] = -rb*sin(49.705*rad);	B[1][1] = rb*sin(49.705*rad);	B[1][2] = rb*cos(19.705*rad);
	B[1][3] = rb*cos(79.705*rad);	B[1][4] = -rb*cos(79.705*rad);	B[1][5] = -rb*cos(19.705*rad);
	// S joint coordinate on the mobile reference
	A1[0][0] = r*cos(35.6*rad);		A1[0][1] = r*cos(35.6*rad);		A1[0][2] = r*sin(5.6*rad);
	A1[0][3] = -r*sin(65.6*rad);	A1[0][4] = -r*sin(65.6*rad);	A1[0][5] = r*sin(5.6*rad);
	A1[1][0] = -r*sin(35.6*rad);	A1[1][1] = r*sin(35.6*rad);		A1[1][2] = r*cos(5.6*rad);
	A1[1][3] = r*cos(65.6*rad);		A1[1][4] = -r*cos(65.6*rad);	A1[1][5] = -r*cos(5.6*rad);
	A1[2][0] = 46.5;				A1[2][1] = 46.5;				A1[2][2] = 46.5;
	A1[2][3] = 46.5;				A1[2][4] = 46.5;				A1[2][5] = 46.5;
	// Rotation matrix
	sa=sin(a);	ca=cos(a);	sb=sin(b);	cb=cos(b);	sg=sin(g);	cg=cos(g);
	R[0][0] = cg*cb;	R[0][1] = cg*sb*sa-sg*ca;	R[0][2] = cg*sb*ca+sg*sa;
	R[1][0] = sg*cb;	R[1][1] = sg*sb*sa+cg*ca;	R[1][2] = sg*sb*ca-cg*sa;
	R[2][0] = -sb;		R[2][1] = cb*sa;			R[2][2] = cb*ca;
	// T joint coordinate on the mobile reference
	T[0][0] = x;	T[1][0] = y;	T[2][0] = z;

	for(int i=0; i<3; i++)
		for(int j=0; j<6; j++)
			A[i][j] = R[i][0]*A1[0][j]+R[i][1]*A1[1][j]+R[i][2]*A1[2][j];

	for(int k=0; k<6; k++)
	{
		A[0][k] = A[0][k] + T[0][0];
		A[1][k] = A[1][k] + T[1][0];
		A[2][k] = A[2][k] + T[2][0];
		L[k] = A[2][k]+sqrt(Lcst*Lcst-(A[0][k]-B[0][k])*(A[0][k]-B[0][k])-(A[1][k]-B[1][k])*(A[1][k]-B[1][k]));
	}
	dl1 = L[0] - Ltz;	dl2 = L[1] - Ltz;	dl3 = L[2] - Ltz;
	dl4 = L[3] - Ltz;	dl5 = L[4] - Ltz;	dl6 = L[5] - Ltz;
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"Inverse Kinematics D"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

void CPmacCtrlDlg::OnCtrlInvkineD(double x,double y,double z,double a,double b,double g)
{
	double	Ltz=-355.5, Lcst=500, rb=1101/2, r=340/2;
	double	rad=pi/180;
	double	B[2][3], A1[3][3], R[3][3], T[3][1], A[3][3], L[3];
	double	sa, ca, sb, cb;
	// U joint coordinate on the base reference
	B[0][0] = rb/2;				B[0][1] = rb/2;			B[0][2] = -rb;
	B[1][0] = -sqrt(3)*rb/2;	B[1][1] = sqrt(3)*rb/2;	B[1][2] = 0;
	// S joint coordinate on the mobile reference
	A1[0][0] = r/2;				A1[0][1] = r/2;			A1[0][2] = -r;
	A1[1][0] = -sqrt(3)*r/2;	A1[1][1] = sqrt(3)*r/2;	A1[1][2] = 0;
	A1[2][0] = 46.5;			A1[2][1] = 46.5;		A1[2][2] = 46.5;
	// Rotation matrix
	b = atan(x/z);			a = atan(-(y*sin(b))/x);
	sa=sin(a);	ca=cos(a);	sb=sin(b);	cb=cos(b);
	R[0][0] = cb;	R[0][1] = sb*sa;	R[0][2] = sb*ca;
	R[1][0] = 0;	R[1][1] = ca;		R[1][2] = -sa;
	R[2][0] = -sb;	R[2][1] = cb*sa;	R[2][2] = cb*ca;
	// T joint coordinate on the mobile reference
	T[0][0] = x;	T[1][0] = y;	T[2][0] = z;

	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			A[i][j] = R[i][0]*A1[0][j]+R[i][1]*A1[1][j]+R[i][2]*A1[2][j];

	for(int k=0; k<3; k++)
	{
		A[0][k] = A[0][k] + T[0][0];
		A[1][k] = A[1][k] + T[1][0];
		A[2][k] = A[2][k] + T[2][0];
		L[k] = A[2][k]+sqrt(Lcst*Lcst-(A[0][k]-B[0][k])*(A[0][k]-B[0][k])-(A[1][k]-B[1][k])*(A[1][k]-B[1][k]));
	}
	dl1 = L[0] - Ltz;	dl2 = L[1] - Ltz;	dl3 = L[2] - Ltz;
	dl4 = 0;			dl5 = 0;			dl6 = 0;
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"Inverse Kinematics E"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

void CPmacCtrlDlg::OnCtrlInvkineE(double x,double y,double z,double a,double b,double g)
{
	double	Ltz=-355.5, Lcst=500, rb=1093.45/2, r=340/2;
	double	rad=pi/180;
	double	B[2][6], A1[3][6], R[3][3], T[3][1], A[3][6], L[6];
	double	sa, ca, sb, cb, sg, cg;
	// U joint coordinate on the base reference
	B[0][0] = -rb*sin(60*rad);	B[0][1] = rb*cos(60*rad);	B[0][2] = rb*cos(60*rad);
	B[0][3] = 0;				B[0][4] = 0;				B[0][5] = -rb*sin(60*rad);
	B[1][0] = rb*cos(60*rad);	B[1][1] = rb*sin(60*rad);	B[1][2] = rb*sin(60*rad);
	B[1][3] = -rb;				B[1][4] = -rb;				B[1][5] = rb*cos(60*rad);
	// S joint coordinate on the mobile reference
	A1[0][0] = -r*sin(60*rad);	A1[0][1] = r*cos(60*rad);	A1[0][2] = r*cos(60*rad);
	A1[0][3] = 0;				A1[0][4] = 0;				A1[0][5] = -r*sin(60*rad);
	A1[1][0] = r*cos(60*rad);	A1[1][1] = r*sin(60*rad);	A1[1][2] = r*sin(60*rad);
	A1[1][3] = -r;				A1[1][4] = -r;				A1[1][5] = r*cos(60*rad);
	A1[2][0] = 46.5;			A1[2][1] = 46.5;			A1[2][2] = 46.5;
	A1[2][3] = 46.5;			A1[2][4] = 46.5;			A1[2][5] = 46.5;
	// Rotation matrix
	sa=sin(a);	ca=cos(a);	sb=sin(b);	cb=cos(b);	sg=sin(g);	cg=cos(g);
	R[0][0] = cg*cb;	R[0][1] = cg*sb*sa-sg*ca;	R[0][2] = cg*sb*ca+sg*sa;
	R[1][0] = sg*cb;	R[1][1] = sg*sb*sa+cg*ca;	R[1][2] = sg*sb*ca-cg*sa;
	R[2][0] = -sb;		R[2][1] = cb*sa;			R[2][2] = cb*ca;
	// T joint coordinate on the mobile reference
	T[0][0] = x;	T[1][0] = y;	T[2][0] = z;

	for(int i=0; i<3; i++)
		for(int j=0; j<6; j++)
			A[i][j] = R[i][0]*A1[0][j]+R[i][1]*A1[1][j]+R[i][2]*A1[2][j];

	for(int k=0; k<6; k++)
	{
		A[0][k] = A[0][k] + T[0][0];
		A[1][k] = A[1][k] + T[1][0];
		A[2][k] = A[2][k] + T[2][0];
		L[k] = A[2][k]+sqrt(Lcst*Lcst-(A[0][k]-B[0][k])*(A[0][k]-B[0][k])-(A[1][k]-B[1][k])*(A[1][k]-B[1][k]));
	}
	dl1 = L[0] - Ltz;	dl2 = L[1] - Ltz;	dl3 = L[2] - Ltz;
	dl4 = L[3] - Ltz;	dl5 = L[4] - Ltz;	dl6 = L[5] - Ltz;
}

//	＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝"Save in Text format"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

void CPmacCtrlDlg::OnSaveText(CString filesave)
{
	CTime	tNow;
	tNow = CTime::GetCurrentTime();
	CString	sDate = tNow.Format("%y - %m - %d");
	CString	sTime = tNow.Format("%I : %M : %S");

	FILE	*fp;
	fp = fopen(filesave, "w+");
	if(fp == NULL)
	{
		AfxMessageBox("建立数据保存文件出错!");
		return;
	}
	fprintf(fp, "--------------------------------------------------------------\n");
	fprintf(fp, "运动几何参数：");
	UpdateData(TRUE);
	switch(m_Structure)
	{
	case 0 : fprintf(fp, "【构型】 构型－1\t"); break;
	case 1 : fprintf(fp, "【构型】 构型－2\t"); break;
	case 2 : fprintf(fp, "【构型】 构型－3\t"); break;	
	case 3 : fprintf(fp, "【构型】 构型－4\t"); break;
	case 4 : fprintf(fp, "【构型】 构型－5\t"); break;
	default: break;
	}

	CString msg;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);
	if(msg == "直线_LINE")
	{
		fprintf(fp, "【轨迹】 直线\n");
		fprintf(fp, "--------------------------------------------------------------\n");
		fprintf(fp, "LINE\n\n");
		fprintf(fp, "[起点]\n\n%.3f %.3f %.3f\n\n",m_SxEdit,m_SyEdit,m_SzEdit);
		fprintf(fp, "[起点方向角]\n\n%.3f %.3f\n\n",m_SaEdit,m_SbEdit);
		fprintf(fp, "[终点]\n\n%.3f %.3f %.3f\n\n",m_ExEdit,m_EyEdit,m_EzEdit);
		fprintf(fp, "[终点方向角]\n\n%.3f %.3f\n",m_EaEdit,m_EbEdit);
	}
	else if(msg == "圆_CIRCLE")
	{
		fprintf(fp, "【轨迹】 圆\n");	
		fprintf(fp, "--------------------------------------------------------------\n");
		fprintf(fp, "CIRCLE\n\n");
		fprintf(fp, "[圆心]\n\n%.3f %.3f %.3f\n\n",m_ScpxEdit,m_ScpyEdit,m_ScpzEdit);
		fprintf(fp, "[半径]\n\n%.3f\n\n",m_SrEdit);
		fprintf(fp, "[起始角]\n\n%.3f\n\n",m_SangEdit);
		fprintf(fp, "[终止角]\n\n%.3f\n",m_EangEdit);
	}
	else
	{
		fprintf(fp, "【轨迹】 螺旋线\n");	
		fprintf(fp, "--------------------------------------------------------------\n");
		fprintf(fp, "HELIX\n\n");
		fprintf(fp, "[起始圆圆心]\n\n%.3f %.3f %.3f\n\n",m_ScpxEdit,m_ScpyEdit,m_ScpzEdit);
		fprintf(fp, "[起始圆半径]\n\n%.3f\n\n",m_SrEdit);
		fprintf(fp, "[起始圆起始角]\n\n%.3f\n\n",m_SangEdit);
		fprintf(fp, "[终止圆圆心]\n\n%.3f %.3f %.3f\n\n",m_EcpxEdit,m_EcpyEdit,m_EcpzEdit);
		fprintf(fp, "[终止圆半径]\n\n%.3f\n\n",m_ErEdit);
		fprintf(fp, "[终止圆终止角]\n\n%.3f\n",m_EangEdit);
	}
	fprintf(fp, "--------------------------------------------------------------\n");
	fprintf(fp, "【时间】 ");
	fprintf(fp, sTime);
	fprintf(fp, "\t【日期】 ");
	fprintf(fp, sDate);
	fclose(fp);
}

// ***************************************************************************//
//	当轨迹形式选择为圆时，起始圆心、半径与终止圆心、半径相同，当输入起始圆心、
//  半径时，终止圆心、半径自动随之变化，以下四个函数实现此功能。
// ***************************************************************************//
//	终止圆半径与起始半径自动同步
void CPmacCtrlDlg::OnChangeSrEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString msg;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	// Judge which option is chosen
	if(msg == "圆_CIRCLE")
	{
		UpdateData(TRUE);
		m_ErEdit = m_SrEdit;
	//	m_EcpxEdit = m_ScpxEdit;
	//	m_EcpyEdit = m_ScpyEdit;
	//	m_EcpzEdit = m_ScpzEdit;
		UpdateData(FALSE);
	}
	return;	
}

//	终止圆心x坐标与起始自动同步
void CPmacCtrlDlg::OnChangeScpxEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString msg;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	// Judge which option is chosen
	if(msg == "圆_CIRCLE")
	{
		UpdateData(TRUE);
	//	m_ErEdit = m_SrEdit;
		m_EcpxEdit = m_ScpxEdit;
	//	m_EcpyEdit = m_ScpyEdit;
	//	m_EcpzEdit = m_ScpzEdit;
		UpdateData(FALSE);
	}
	return;		
}

//	终止圆心y坐标与起始自动同步
void CPmacCtrlDlg::OnChangeScpyEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString msg;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	// Judge which option is chosen
	if(msg == "圆_CIRCLE")
	{
		UpdateData(TRUE);
	//	m_ErEdit = m_SrEdit;
	//	m_EcpxEdit = m_ScpxEdit;
		m_EcpyEdit = m_ScpyEdit;
	//	m_EcpzEdit = m_ScpzEdit;
		UpdateData(FALSE);
	}
	return;	
}

//	终止圆心z坐标与起始自动同步
void CPmacCtrlDlg::OnChangeScpzEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString msg;
	m_cb.GetLBText(m_cb.GetCurSel(),msg);

	// Judge which option is chosen
	if(msg == "圆_CIRCLE")
	{
		UpdateData(TRUE);
	//	m_ErEdit = m_SrEdit;
	//	m_EcpxEdit = m_ScpxEdit;
	//	m_EcpyEdit = m_ScpyEdit;
		m_EcpzEdit = m_ScpzEdit;
		UpdateData(FALSE);
	}
	return;	
}

// ***************************************************************************//

