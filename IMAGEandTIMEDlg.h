
// IMAGEandTIMEDlg.h : header file
//

#pragma once
class CLayoutHelper;
class CScrollHelper;
// CIMAGEandTIMEDlg dialog
class CIMAGEandTIMEDlg : public CDialogEx
{
// Construction
public:
	CIMAGEandTIMEDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMAGEANDTIME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void mainLUKCIAS();

//	afx_msg void OnBnClickedButton1();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedOkk();
	afx_msg void OnFileOpen();
	afx_msg void DialogFileLUK();
	afx_msg CString ObtainDirectory(CString fullpathName);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTimeChange();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	CLayoutHelper* m_layoutHelper;
	CScrollHelper* m_scrollHelper;

	// OPEN EW DIRECTORY
	CButton C_BUTTONOPEN;
	// EXIT
	CButton C_CANCEL;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	// stsrt slide show
	CButton c_slideshowbut;
	// JUMP TU AN IMAGE
	CEdit C_EDIT1JUMP;
	afx_msg void OnBnClickedButton2jump();
	CButton C_BUTTON2JUMP;
};
