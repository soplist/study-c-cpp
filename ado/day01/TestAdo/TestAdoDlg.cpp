// TestAdoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestAdo.h"
#include "TestAdoDlg.h"

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
// CTestAdoDlg dialog

CTestAdoDlg::CTestAdoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestAdoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestAdoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestAdoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestAdoDlg)
	DDX_Control(pDX, IDC_LIST1, m_wndList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestAdoDlg, CDialog)
	//{{AFX_MSG_MAP(CTestAdoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENDB, OnOpendb)
	ON_BN_CLICKED(IDC_OPENTABLE, OnOpentable)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_SQL, OnSql)
	ON_BN_CLICKED(IDC_CMD, OnCmd)
	ON_BN_CLICKED(IDC_TRANS, OnTrans)
	ON_BN_CLICKED(IDC_BIN, OnBin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestAdoDlg message handlers

BOOL CTestAdoDlg::OnInitDialog()
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

void CTestAdoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestAdoDlg::OnPaint() 
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
HCURSOR CTestAdoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestAdoDlg::OnOpendb() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE);
	if (dlg.DoModal()!=IDOK)
	{
		return;
	}
	CString strPath=dlg.GetPathName();
	if (!m_database.OpenMDB(strPath))
	{
		MessageBox("打开数据库失败！");
		return;
	}
	
}

void CTestAdoDlg::OnOpentable() 
{
	// TODO: Add your control notification handler code here
	CAdoRecordset set;
	if (!set.OpenTable("TBL_MSG",&m_database))
	{
		MessageBox("打开表失败");
		return;
	}
	//显示数据
    ShowData(&set);
}

void CTestAdoDlg::ShowData(CAdoRecordset *pSet)
{
   //添加数居前，清空
	m_wndList.DeleteAllItems();
	while(m_wndList.DeleteColumn(0));
	//获取字段的数量
	UINT nCount=pSet->GetFieldsCount();
	for (int index=0;index<nCount;index++)
	{
		CString strName=pSet->GetFieldName(index);
		m_wndList.InsertColumn(index,strName,
			LVCFMT_LEFT,100);
			
	}
	//添加数据
    int nItem=0;//控件数据项的索引
	pSet->MoveFirst();
	while(!pSet->IsEOF())
	{
		//获取数据
        for (int nIndex=0;nIndex<nCount;nIndex++)
        {
			CString strValue;
			pSet->GetValue(nIndex,strValue);
			if (nIndex==0)//第一列
			{
				m_wndList.InsertItem(nItem,strValue);
			}
			else
			{
				m_wndList.SetItemText(nItem,
					nIndex,strValue);
			}
        }
		pSet->MoveNext();
		nItem++;
	}
}

void CTestAdoDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CAdoRecordset set;
	set.OpenTable("TBL_MSG",&m_database);
	//添加新行
	set.AddNew();
	//设置该行每一个字段的值
	set.SetValue(0,"6");
	set.SetValue(1,"66");
	set.SetValue(2,"666");
	set.SetValue(3,"6666");
	set.SetValue(4,"66666");
	//更新到数据库
	set.Update();
	ShowData(&set);
}
void CTestAdoDlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	int nSel=m_wndList.GetNextItem(
		-1,LVNI_SELECTED);
	if (nSel==-1)
	{
		MessageBox("请选择要删除的数据项");
		return;
	}
	CAdoRecordset set;
	set.OpenTable("TBL_MSG",&m_database);
	set.Move(nSel);
	set.Delete();
	set.Update();
	//重新显示
	ShowData(&set);
}

void CTestAdoDlg::OnSql() 
{
	// TODO: Add your control notification handler code here
	CString strSql=
		"insert into TBL_MSG values('7','7','77','77','77')";
    m_database.OpenSql(strSql);
	CAdoRecordset set;
	CString strsql2=
		"select * from TBL_MSG";
	set.OpenSql(strsql2,&m_database);
	ShowData(&set);

}

void CTestAdoDlg::OnCmd() 
{
	// TODO: Add your control notification handler code here
	CString strSql=
		"delete from TBL_MSG where msg_id='2'";
	CAdoCommand cmd;
	cmd.OpenSql(strSql,&m_database);
	OnOpentable();
}

void CTestAdoDlg::OnTrans() 
{
	// TODO: Add your control notification handler code here
	CString strSql="delete * from TBL_MSG";
	m_database.BeginTrans();//启动事务
	m_database.OpenSql(strSql);//删除表的数据
	OnOpentable();
	MessageBox("回滚事务");
	m_database.EndTrans(FALSE);
    OnOpentable();

}

void CTestAdoDlg::OnBin() 
{
	// TODO: Add your control notification handler code here
	//打开表
	CAdoRecordset set;
	set.OpenTable("TBL_MSG",&m_database);
	CHAR szText[]="Hello Binary";
	//把字符数组以二进制的形式保存包数据库中
	set.SetBinaryValue(5,(BYTE*)szText,
		strlen(szText));
	set.Update();
	//获取二进制数据，以字符串的形式显示
	ULONG nLen=0;
	//第一次调用，获取数据的长度
	set.GetBinaryValue(5,NULL,nLen);
	if (nLen==0)
	{
		return;
	}
	//分配空间以保存从数据库中读取的数据
	char* pszValue=(char*)malloc(nLen+1);
	memset(pszValue,0,nLen+1);
	//第二次调用，获取数据
	set.GetBinaryValue(5,(BYTE*)pszValue,nLen);
	MessageBox(pszValue);
	free(pszValue);

}
