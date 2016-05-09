// MFCODBCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCODBC.h"
#include "MFCODBCDlg.h"

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
// CMFCODBCDlg dialog

CMFCODBCDlg::CMFCODBCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCODBCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCODBCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCODBCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCODBCDlg)
	DDX_Control(pDX, IDC_LIST1, m_wndList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCODBCDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCODBCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW, OnShow)
	ON_BN_CLICKED(IDC_BIND, OnBind)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCODBCDlg message handlers

BOOL CMFCODBCDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCODBCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCODBCDlg::OnPaint() 
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
HCURSOR CMFCODBCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCODBCDlg::OnShow() 
{
	// TODO: Add your control notification handler code here
	//连接数据库
	CDatabase db;
	if (!db.Open("Test"))
	{
		MessageBox("打开数据源失败！");
		return;
	}
	//查询数据
	CRecordset set(&db);
	set.Open(CRecordset::forwardOnly,
		_T("select * from TBL_MSG"));
	//在CListCtrl中显示数据
    ShowData(&set);
	//关闭记录集
	set.Close();
	//关闭数据库
	db.Close();
}

void CMFCODBCDlg::ShowData(CRecordset *pSet)
{
   //添加数据前，清空
   m_wndList.DeleteAllItems();//清空所有行
   while(m_wndList.DeleteColumn(0));//清空所有列
   //获取数据表中字段的数量
   int nCount=pSet->GetODBCFieldCount();
   for (int index=0;index<nCount;index++)
   {
	   //获取每个字段的信息
	   CODBCFieldInfo info;
       pSet->GetODBCFieldInfo(index,info);
	   //设置CListCtrl控件的列
	   m_wndList.InsertColumn(index,info.m_strName,
		   LVCFMT_LEFT,100);
   }
   //获取记录
   int nItem=0;//控件中数据项的索引
  // pSet->MoveFirst();//将当前游标移动到记录的第一行
   while(!pSet->IsEOF())//判断是否到最后一条记录
   {
      //循环获取当前记录的各个字段的数据
	   for (int nIndex=0;nIndex<nCount;nIndex++)
	   {
		   CString strValue;
		   pSet->GetFieldValue(nIndex,strValue);
		   if (nIndex==0)//第一列
		   {
			   m_wndList.InsertItem(nItem,strValue);
		   }
		   else//其它各列
		   {
              m_wndList.SetItemText(nItem,nIndex,strValue);
		   }
	   }
	   nItem++;
	   pSet->MoveNext();//将游标移动到下一条记录
   }
}
#include "MsgSet.h"
void CMFCODBCDlg::OnBind() 
{
	// TODO: Add your control notification handler code here
	CMsgSet set;
	set.Open();
	ShowData(&set);
}
