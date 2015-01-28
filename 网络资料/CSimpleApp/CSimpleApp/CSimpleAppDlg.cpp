// CSimpleAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CSimpleApp.h"
#include "CSimpleAppDlg.h"
#include "runtime.h"

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
// CCSimpleAppDlg dialog

CCSimpleAppDlg::CCSimpleAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCSimpleAppDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCSimpleAppDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bDriverOpen = FALSE;
	m_dwDevice = 0;
	m_hPmacLib = FALSE;
}

void CCSimpleAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCSimpleAppDlg)
	DDX_Control(pDX, IDC_STATIC_Z, m_ZValue);
	DDX_Control(pDX, IDC_STATIC_Y, m_YValue);
	DDX_Control(pDX, IDC_STATIC_X, m_XValue);
	DDX_Control(pDX, IDC_INCREMENT_EDIT, m_incrementEditCtrl);
	DDX_Control(pDX, IDC_INCREMENT_CHECK, m_incrementCheckCtrl);
	DDX_Control(pDX, IDC_JOGTO_EDIT, m_jogToEditCtrl);
	DDX_Control(pDX, IDC_SELMOTOR_STATIC, m_selMotorStaticCtrl);
	DDX_Control(pDX, IDC_SELMOTOR_SPIN, m_selMotorSpinCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCSimpleAppDlg, CDialog)
	//{{AFX_MSG_MAP(CCSimpleAppDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_JOGTO_BTN, OnJogtoBtn)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SELMOTOR_SPIN, OnDeltaposSelmotorSpin)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCSimpleAppDlg message handlers

BOOL CCSimpleAppDlg::OnInitDialog()
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
	m_selMotorStaticCtrl.SetWindowText("1");

	//set selmotor_static control buddy with spin control
	m_selMotorSpinCtrl.SetBuddy(GetDlgItem(IDC_SELMOTOR_STATIC));
	m_selMotorSpinCtrl.SetRange(1,3);//单轴仅有三个方向
	SetTimer(1,500,NULL);
	PmacInitialize();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCSimpleAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCSimpleAppDlg::OnPaint() 
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
HCURSOR CCSimpleAppDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCSimpleAppDlg::OnJogtoBtn() 
{
	CString strMotorID;
	CString strSpecPos;
	int  nSpecPos;
	CString strCmd;
	CString strTemp;

	m_jogToEditCtrl.GetWindowText(strSpecPos);	
	m_selMotorStaticCtrl.GetWindowText(strMotorID);

	nSpecPos = (INT)(atof(strSpecPos.GetBuffer(0)) * 2000);

	if (strSpecPos == "") 
	   MessageBox("请输入有效数据","警告");
	else
	{
	   strCmd.Format("#%sj=%d",strMotorID,nSpecPos);
	   SendLine(strCmd);
	}
}

void CCSimpleAppDlg::OnDeltaposSelmotorSpin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	CString strMotorID;
	CString temp;
	m_selMotorStaticCtrl.GetWindowText(strMotorID);
	int val = atoi(strMotorID.GetBuffer(strMotorID.GetLength()+1));
	val += pNMUpDown->iDelta;
	if(val==0) val = 7;
	if(val==8) val = 1;
	temp.Format("%d", val);
	m_selMotorStaticCtrl.SetWindowText(temp);
	
	*pResult = 0;
}

BEGIN_EVENTSINK_MAP(CCSimpleAppDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CCSimpleAppDlg)
	ON_EVENT(CCSimpleAppDlg, IDC_JOGMINU_BTN, -605 /* MouseDown */, OnMouseDownJogminuBtn, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
	ON_EVENT(CCSimpleAppDlg, IDC_JOGMINU_BTN, -607 /* MouseUp */, OnMouseUpJogminuBtn, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
	ON_EVENT(CCSimpleAppDlg, IDC_JOGPLUS_BTN, -605 /* MouseDown */, OnMouseDownJogplusBtn, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
	ON_EVENT(CCSimpleAppDlg, IDC_JOGPLUS_BTN, -607 /* MouseUp */, OnMouseUpJogplusBtn, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()


void CCSimpleAppDlg::OnMouseDownJogminuBtn(short Button, short Shift, float X, float Y) 
{
	CString strStepPos;
    CString strMotorID;
	CString strCmd;
	CString strTemp;
	m_incrementEditCtrl.GetWindowText(strStepPos);
    m_selMotorStaticCtrl.GetWindowText(strMotorID);

	int nStepPos = (INT)(atof(strStepPos.GetBuffer(0)) * (2000));
	if(m_incrementCheckCtrl.GetCheck()==0)
	{
	     strCmd="#"+strMotorID+"j-";
	}
	else
	{
		if(strStepPos == "")
			MessageBox("请输入有效数据","警告");
		else
		{
			strCmd.Format("#%sj:-%d",strMotorID,nStepPos);
		}
	}

	SendLine(strCmd);
	
}

void CCSimpleAppDlg::OnMouseUpJogminuBtn(short Button, short Shift, float X, float Y) 
{
	CString strCmd;
	CString strMotorID;
	m_selMotorStaticCtrl.GetWindowText(strMotorID);

	if(m_incrementCheckCtrl.GetCheck()==0)
	{
	  strCmd="#"+strMotorID+"j/";
	}
	SendLine(strCmd);
	
}

void CCSimpleAppDlg::OnMouseDownJogplusBtn(short Button, short Shift, float X, float Y) 
{
	CString strStepPos;
    CString strMotorID;
	CString strCmd;
	CString strTemp;
	m_incrementEditCtrl.GetWindowText(strStepPos);
    m_selMotorStaticCtrl.GetWindowText(strMotorID);//电机号

	int nStepPos = (INT)(atof(strStepPos.GetBuffer(0)) * (2000));
	if(m_incrementCheckCtrl.GetCheck()==0)
	{
		strCmd="#"+strMotorID+"j+";
	}	
	else
	{
		if(strStepPos == "")
			MessageBox("请输入有效数据","警告");
		else
		{
			strCmd.Format("#%sj:%d",strMotorID,nStepPos);
		}
	}
	SendLine(strCmd);
}

void CCSimpleAppDlg::OnMouseUpJogplusBtn(short Button, short Shift, float X, float Y) 
{
	CString strCmd;
	CString strMotorID;
	m_selMotorStaticCtrl.GetWindowText(strMotorID);

	if(m_incrementCheckCtrl.GetCheck()==0)
	{
	  strCmd="#"+strMotorID+"j/"; 
	}
	SendLine(strCmd);
}

void CCSimpleAppDlg::SendLine(const CString &s)
{
	if(m_bDriverOpen)
    DeviceSendLine(m_dwDevice,(char *)LPCTSTR(s));
}

BOOL CCSimpleAppDlg::PmacInitialize()
{
	// Get handle to PMAC.DLL
	if(!m_hPmacLib)
		m_hPmacLib = OpenRuntimeLink();
	
	if(m_hPmacLib == NULL)
		return FALSE;
	
	m_bDriverOpen = DeviceOpen(m_dwDevice);
	
	if(m_bDriverOpen)
	{
		DeviceSendLine(m_dwDevice,"open prog 1\nclear\nclose\nopen prog 2\nclear\nclose");
		//DeviceSendCommand(m_dwDevice,"open prog 2\nclear\nclose");
		DeviceSetAsciiComm(m_dwDevice,BUS);
	    DeviceDPRBackground(m_dwDevice,1);
		//这里要注意的是：DeviceSendLine的用法和意义!
		return TRUE;
	}
	else
	{
		MessageBox("无法与PMAC卡建立通讯");
		PmacConfigureComm(NULL);
		return FALSE;
	}
}

void CCSimpleAppDlg::PmacConfigureComm(HWND Wnd)
{
		// Close PMAC Device
	if(m_bDriverOpen) 
	{
		m_bDriverOpen = !DeviceClose(m_dwDevice);
	}
	
	// Configure Device
	if(DevicePmacConfigure(Wnd,m_dwDevice)) // ReOpen PMAC Device
		m_bDriverOpen = DeviceOpen(m_dwDevice);
	else
		m_bDriverOpen = FALSE;
	
	// Setup View to reflect device open status
	if(!m_bDriverOpen)
	{
		MessageBox("Could not initialize PMAC Comm.");
	}

}

void CCSimpleAppDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	KillTimer(1);
	if(m_bDriverOpen) 
	{
		m_bDriverOpen = !DeviceClose(m_dwDevice);
	}
	if(m_hPmacLib)
	{
		FreeLibrary(m_hPmacLib);
		m_hPmacLib = NULL;
	}		
}

void CCSimpleAppDlg::OnTimer(UINT nIDEvent) 
{
	TCHAR tcResponseX[18];
	TCHAR tcResponseY[18];
	TCHAR tcResponseZ[18];

	float  fltXValue = 0;
	float  fltYValue = 0;
	float  fltZValue = 0;

	CString strXValue;  //X-Axis position value
	CString strYValue;  //Y-Axis position value
	CString strZValue;  //Z-Axis position value

    //send command "P" to PMAC and wait for getting response
	DeviceGetResponse(m_dwDevice,tcResponseX,sizeof(tcResponseX),"#1p");
	DeviceGetResponse(m_dwDevice,tcResponseY,sizeof(tcResponseY),"#2p");
	DeviceGetResponse(m_dwDevice,tcResponseZ,sizeof(tcResponseZ),"#3p");

	//{
	//compute real axis position_value
	fltXValue = (FLOAT)atof(tcResponseX)/(2000);
	fltYValue = (FLOAT)atof(tcResponseY)/(2000);
	fltZValue = (FLOAT)atof(tcResponseZ)/(2000);

	strXValue.Format("%.2f",fabs(fltXValue));
	strYValue.Format("%.2f",fabs(fltYValue));
	strZValue.Format("%.2f",fabs(fltZValue));

    m_XValue.SetWindowText(strXValue);
	m_YValue.SetWindowText(strYValue);
	m_ZValue.SetWindowText(strZValue);
	
	CDialog::OnTimer(nIDEvent);
}
