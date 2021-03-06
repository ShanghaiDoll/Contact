#pragma once


// Addone 对话框

class Addone : public CDialogEx
{
	DECLARE_DYNAMIC(Addone)

public:
	Addone(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Addone();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = ID_AddOne };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Name;
	CString Tel;
	CString Sex;
	afx_msg void OnBnClickedMale();
	afx_msg void OnBnClickedFemale();
	afx_msg void OnBnClickedOk();
};
