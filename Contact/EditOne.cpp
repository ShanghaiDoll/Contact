// EditOne.cpp: 实现文件
//

#include "stdafx.h"
#include "Contact.h"
#include "EditOne.h"
#include "afxdialogex.h"
#include "CPublic.h"
#include "ContactDlg.h"


// EditOne 对话框

CString SEX;

IMPLEMENT_DYNAMIC(EditOne, CDialogEx)

EditOne::EditOne(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Edit, pParent)
	, Name(_T(""))
	, Tel(_T(""))
	, remarks(_T(""))
{

}

EditOne::~EditOne()
{
}

void EditOne::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, Name);
	DDX_Text(pDX, IDC_EDIT4, Tel);
	DDX_Control(pDX, IDC_COMBO4, Sex);
	DDX_Text(pDX, IDC_EDIT7, remarks);
}


BEGIN_MESSAGE_MAP(EditOne, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO4, &EditOne::OnCbnSelchangeCombo4)
	ON_BN_CLICKED(IDC_BUTTON1, &EditOne::OnBnClickedButton1)
END_MESSAGE_MAP()


// EditOne 消息处理程序


void EditOne::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
	int nSel;

	// 获取组合框控件的列表框中选中项的索引   
	nSel = Sex.GetCurSel();
	// 根据选中项索引获取该项字符串   
	Sex.GetLBText(nSel, SEX);
	if (SEX == "Female")
		SEX = 'F';
	else if (SEX == "Male")
		SEX = 'M';
	else
		SEX = '?';
}


void EditOne::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);// 将各控件中的数据保存到相应的变量
	int listNum = ((CContactDlg*)CPublic::toListCtrl)->m_programLangList.GetSelectedCount();
	((CContactDlg*)CPublic::toListCtrl)->m_programLangList.DeleteItem(listNum);
	((CContactDlg*)CPublic::toListCtrl)->m_programLangList.InsertItem(listNum, Name);
	((CContactDlg*)CPublic::toListCtrl)->m_programLangList.SetItemText(listNum, 1, SEX);
	((CContactDlg*)CPublic::toListCtrl)->m_programLangList.SetItemText(listNum, 2, Tel);
	// 根据各变量的值更新相应的控件。和的编辑框会显示m_editSum的值   
	UpdateData(FALSE);
	CDialogEx::OnOK();
}
