// Addone.cpp: 实现文件
//

#include "stdafx.h"
#include "Contact.h"
#include "Addone.h"
#include "afxdialogex.h"
#include "CPublic.h"
#include "ContactDlg.h"


// Addone 对话框

IMPLEMENT_DYNAMIC(Addone, CDialogEx)

Addone::Addone(CWnd* pParent /*=nullptr*/)
	: CDialogEx(ID_AddOne, pParent)
	, Name(_T(""))
	, Tel(_T(""))
	,Sex(_T(""))
{

}

Addone::~Addone()
{
}

void Addone::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Name_Edit, Name);
	DDV_MaxChars(pDX, Name, 10);
	DDX_Text(pDX, IDC_Tel_Edit, Tel);
	DDV_MaxChars(pDX, Tel, 20);
}


BEGIN_MESSAGE_MAP(Addone, CDialogEx)
	ON_BN_CLICKED(IDC_Male, &Addone::OnBnClickedMale)
	ON_BN_CLICKED(IDC_Female, &Addone::OnBnClickedFemale)
	ON_BN_CLICKED(IDOK, &Addone::OnBnClickedOk)
END_MESSAGE_MAP()


// Addone 消息处理程序


void Addone::OnBnClickedMale()
{
	// TODO: 在此添加控件通知处理程序代码
	Sex = 'M';
}


void Addone::OnBnClickedFemale()
{
	// TODO: 在此添加控件通知处理程序代码
	Sex = 'F';
}

void Addone::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);// 将各控件中的数据保存到相应的变量
	if (Sex != 'M' && Sex != 'F')
		Sex = '?';
	int listNum = ((CContactDlg*)CPublic::toListCtrl)->m_programLangList.GetItemCount();
	((CContactDlg*)CPublic::toListCtrl)->m_programLangList.InsertItem(listNum, Name);
	((CContactDlg*)CPublic::toListCtrl)->m_programLangList.SetItemText(listNum, 1, Sex);
	((CContactDlg*)CPublic::toListCtrl)->m_programLangList.SetItemText(listNum, 2, Tel);
	// 根据各变量的值更新相应的控件。和的编辑框会显示m_editSum的值   
	UpdateData(FALSE);
	CDialogEx::OnOK();
}
