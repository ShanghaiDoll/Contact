
// ContactDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Contact.h"
#include "ContactDlg.h"
#include "afxdialogex.h"
#include "Addone.h"
#include "CPublic.h"
#include "EditOne.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CContactDlg 对话框



CContactDlg::CContactDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONTACT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CContactDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Info_List, m_programLangList);
}

BEGIN_MESSAGE_MAP(CContactDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Add, &CContactDlg::OnBnClickedAdd)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CContactDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_Delete, &CContactDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_Edit, &CContactDlg::OnBnClickedEdit)
END_MESSAGE_MAP()


// CContactDlg 消息处理程序

BOOL CContactDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_programLangList.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_programLangList.SetExtendedStyle(m_programLangList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_programLangList.InsertColumn(0, _T("Name"), LVCFMT_CENTER, rect.Width() / 4, 0);
	m_programLangList.InsertColumn(1, _T("Sex"), LVCFMT_CENTER, rect.Width() / 8, 1);
	m_programLangList.InsertColumn(2, _T("Tel"), LVCFMT_CENTER, rect.Width() - rect.Width() / 4 - rect.Width() / 8, 2);
	//预设
	m_programLangList.InsertItem(0, _T("Konpaku"));
	m_programLangList.SetItemText(0, 1, _T("F"));
	m_programLangList.SetItemText(0, 2, _T("XXXX"));
	m_programLangList.InsertItem(1, _T("Scarlet"));
	m_programLangList.SetItemText(1, 1, _T("F"));
	m_programLangList.SetItemText(1, 2, _T("XXXX"));
	m_programLangList.InsertItem(2, _T("Knowledge"));
	m_programLangList.SetItemText(2, 1, _T("F"));
	m_programLangList.SetItemText(2, 2, _T("XXXX"));
	CPublic::toListCtrl = this;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CContactDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CContactDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CContactDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CContactDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;             // 用于保存DoModal函数的返回值   
	Addone person;           // 构造对话框类CTipDlg的实例   
	nRes = person.DoModal();  // 弹出对话框   
	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		return;
}


void CContactDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	*pResult = 0;
}


void CContactDlg::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);  //获取一个句柄
	int column = pList->GetSelectionMark();        //选择一行
	if (column == -1)
		MessageBox(L"Nothing has been selected!", L"ERROR");
	pList->DeleteItem(column);
}


void CContactDlg::OnBnClickedEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);  //获取一个句柄
	int column = pList->GetSelectionMark();        //选择一行
	if (column == -1)
		MessageBox(L"Nothing has been selected!", L"ERROR");
	else
	{
		INT_PTR nRes;             // 用于保存DoModal函数的返回值   

		EditOne person;           // 构造对话框类CTipDlg的实例   
		nRes = person.DoModal();  // 弹出对话框   
		if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
			return;
	}
}
