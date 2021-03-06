#pragma once


// EditOne 对话框

class EditOne : public CDialogEx
{
	DECLARE_DYNAMIC(EditOne)

public:
	EditOne(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~EditOne();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Edit };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Name;
	CString Tel;
	afx_msg void OnCbnSelchangeCombo4();
	CComboBox Sex;
	CString remarks;
	afx_msg void OnBnClickedButton1();
};
