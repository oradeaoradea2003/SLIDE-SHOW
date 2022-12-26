
// IMAGEandTIMEDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "IMAGEandTIME.h"
#include "IMAGEandTIMEDlg.h"
#include "afxdialogex.h"
#include "PictureCtrl.h"
#include<windows.h>
#include <string.h>
#include<cstringt.h>
#include <stdio.h>
#include <atlstr.h>
#include <algorithm>

#include "LayoutHelper.h"
#include "ScrollHelper.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIMAGEandTIMEDlg dialog
CString pathName;
CString dirE;
CString dirE2;
bool stoptimer = FALSE;
CString fullpath;
int nr_total_images = 0;
CIMAGEandTIMEDlg::CIMAGEandTIMEDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IMAGEANDTIME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}
CPictureCtrl m_img;
void CIMAGEandTIMEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC, m_img);
	DDX_Control(pDX, IDOPEN, C_BUTTONOPEN);
	DDX_Control(pDX, IDCANCEL, C_CANCEL);
	DDX_Control(pDX, IDC_BUTTON1, c_slideshowbut);
	DDX_Control(pDX, IDC_EDIT1JUMP, C_EDIT1JUMP);
	DDX_Control(pDX, IDC_BUTTON2JUMP, C_BUTTON2JUMP);
}

BEGIN_MESSAGE_MAP(CIMAGEandTIMEDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOKK, &CIMAGEandTIMEDlg::OnBnClickedOkk)
	ON_BN_CLICKED(IDC_BUTTON1, &CIMAGEandTIMEDlg::OnBnClickedButton1)
ON_WM_TIMER()
ON_WM_SIZE()
ON_BN_CLICKED(IDC_BUTTON2JUMP, &CIMAGEandTIMEDlg::OnBnClickedButton2jump)
END_MESSAGE_MAP()

int k = 0;
// CIMAGEandTIMEDlg message handlers
#include<winuser.h>

BOOL CIMAGEandTIMEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	/*  
	CLayoutInfo info;
	info.Reset();
	info.AddOption(CLayoutInfo::OT_MIN_WIDTH, 40);
	info.AddOption(CLayoutInfo::OT_MAX_WIDTH, 400);
	info.AddOption(CLayoutInfo::OT_MIN_HEIGHT, 23);
	info.AddOption(CLayoutInfo::OT_MAX_HEIGHT, 239);
	m_layoutHelper->AddControl(GetDlgItem(IDC_STATIC), info);
	m_layoutHelper->LayoutControls();
*/

	//luk SetTimer(4,9000,NULL);
	DialogFileLUK();
	
	
     
		//DialogFileLUK();
	

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CIMAGEandTIMEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIMAGEandTIMEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CIMAGEandTIMEDlg::DialogFileLUK()
{

	CFileDialog fileDialog(true, NULL, NULL, 6, L"IMAGES|*.jpg; *.jpeg; *.png; *.gif|", GetParent());
	int result = fileDialog.DoModal();
	if (result == IDOK)
	{
		pathName = fileDialog.GetPathName();
		//SetWindowText(pathName);
		SetWindowText(pathName);
		//MessageBox(pathName);
		m_img.LoadFromFile(CString(pathName));
		fullpath = pathName;
	}
	else
	{
		pathName = "Pic2.gif";
		SetWindowText(pathName);
		MessageBox(pathName);
		m_img.LoadFromFile(CString("Pic2.gif"));
		fullpath = pathName;
	}
	using namespace std;
	//using namespace System;
	CString filename = pathName; //CString(_T("C\\CORONA\\BEER\\DRINK.NOW"));
	CString directory;
	int r = filename.ReverseFind('\\');
	//ASSERT(r == 23||r==24||r==25||r==26);
	char numchar[1000];
	sprintf_s(numchar, "%d", r);
	//MessageBox(CString(numchar));

	
	if (r >= 0)
	{
		dirE = filename.Mid(0, r);
		dirE = dirE + _T("\\");
		dirE2= _T("\"") + dirE + _T("\"");
		//MessageBox(CString(dirE2));
		CString forsys = CString("DIR /B ") + dirE2 + CString(" *.jpg *.png *.gif > FILES.TXT");
		//MessageBox(forsys);
		CStringA s(forsys);
		const char* c = s;
		int out2=system("del FILES.TXT");
	//LUK 	if (out2 == 0)MessageBox(CString("out2=0"));
	//LUK 	if (out2< 0)MessageBox(CString("out2<0"));
	//LUK 	if (out2> 0)MessageBox(CString("out2>0"));

		int out=system(c);
		//if(out==0)MessageBox(CString("COMMAND DIR e OK"));
		if (out< 0)MessageBox(CString("COMMAND DIR NOT OK out <0"));
		if (out > 0)MessageBox(CString("COMMAND DIR NOT OK out>0"));
	
	}
}

void CIMAGEandTIMEDlg::OnBnClickedOkk()
{
	// TODO: Add your control notification handler code here

	KillTimer(4);
	stoptimer = FALSE;
	c_slideshowbut.SetWindowTextW(CString("SlideShow"));
	DialogFileLUK();
}

using namespace std;
void CIMAGEandTIMEDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	//m_img.LoadFromFile(CString("Pic1.jpg"));
	if (stoptimer == FALSE) {
		SetTimer(4, 1000, NULL);
		stoptimer = TRUE;
		c_slideshowbut.SetWindowTextW(CString("STOP "));
	}
	else {
		KillTimer(4);
		stoptimer=FALSE;
		c_slideshowbut.SetWindowTextW(CString("SlideShow"));
	}
}


#include <fstream>
#include <string>
void CIMAGEandTIMEDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	// TODO: Add your message handler code here and/or call default
	//MessageBox(CString("cucu"));
	std::ifstream file;
	file.open("FILES.TXT");
	std::string str;
	std::string strtab[9000];
	int i = 0;
	while (getline(file, str)) {
		//MessageBox(CString("este:") + CString(str.c_str()));
		//MessageBox(CString("este:")+CString(str.data()));
		strtab[i] = str;
		i++;
	}
	nr_total_images = i - 1;
	if (nr_total_images > 9000)MessageBox(CString("number of images to great than 9000  "));
	CString str_total_images;
	str_total_images.Format(_T("%d"), nr_total_images);
	CString str_this_image;
	str_this_image.Format(_T("%d"), k+1);
	if (k + 1 == nr_total_images)
	{
		KillTimer(4);
		stoptimer = FALSE;
		c_slideshowbut.SetWindowTextW(CString("SlideShow"));
		k = 0;


	}

	SetWindowText(str_this_image +CString("/")+ str_total_images+ CString(" :") + dirE+CString(strtab[k].c_str()));
	
	
	//dirE.Replace(_T(" "), _T("\ ")); //Replace(_T('in.'), _T(' '));
	 fullpath = dirE + CString(strtab[k].c_str());
	 //MessageBox(fullpath);
	m_img.LoadFromFile(CString(fullpath));
	k++;
	file.close();

	CDialogEx::OnTimer(nIDEvent);
}


void CIMAGEandTIMEDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here



	CRect r;
	GetClientRect(&r);
	CRect lb;
	m_img.GetWindowRect(&lb);
	ScreenToClient(&lb);
	m_img.SetWindowPos(NULL, 0, 0, r.Width(), r.Height() - 80,
		SWP_NOMOVE | SWP_NOZORDER);
	///////////////////////  C_BUTTONOPEN
	CRect lb2;
	C_BUTTONOPEN.GetWindowRect(&lb2);
	ScreenToClient(&lb2);
	C_BUTTONOPEN.SetWindowPos(NULL, 20, lb.Height() + 50, lb2.Width(), lb2.Height(),
		//SWP_NOMOVE |
		SWP_NOZORDER);
	///////////////////////  C_CANCEL
	CRect lb3;
	C_CANCEL.GetWindowRect(&lb3);
	ScreenToClient(&lb3);
	C_CANCEL.SetWindowPos(NULL, r.Width() - lb2.Width() - 40, lb.Height()+50, lb2.Width(), lb2.Height(),
		//SWP_NOMOVE |
		SWP_NOZORDER);
	/// c_slideshowbut
	CRect lb4;
	c_slideshowbut.GetWindowRect(&lb4);
	ScreenToClient(&lb4);
	c_slideshowbut.SetWindowPos(NULL, lb2.Width()+ 50, lb.Height()+50, lb2.Width(), lb2.Height(),
	//	SWP_NOMOVE | SWP_NOZORDER);
		SWP_NOZORDER);

	/// C_EDIT1JUMP
	CRect lb5;
	C_EDIT1JUMP.GetWindowRect(&lb5);
	ScreenToClient(&lb5);
	C_EDIT1JUMP.SetWindowPos(NULL, 2*lb2.Width() + 2*50, lb.Height() + 50, lb5.Width(), lb5.Height(),
		//	SWP_NOMOVE | SWP_NOZORDER);
		SWP_NOZORDER);
	/// C_BUTTON2JUMP
	CRect lb6;
	C_BUTTON2JUMP.GetWindowRect(&lb6);
	ScreenToClient(&lb6);
	C_BUTTON2JUMP.SetWindowPos(NULL, 2 * lb2.Width() + 2 * 50+lb5.Width()+5, lb.Height() + 50, lb3.Width(), lb3.Height(),
		//	SWP_NOMOVE | SWP_NOZORDER);
		SWP_NOZORDER);




		m_img.LoadFromFile(CString(fullpath));






	//MessageBox(CString("pos"));
	// TODO: Add your message handler code here
	//UINT flags = SWP_NOZORDER| SWP_NOACTIVATE;
//	::SetWindowPos(GetDlgItem(IDC_STATIC)->m_hWnd,0,0,0,cx,cy,flags);
	// Initialization: Set the reference/minimum size for layout,
	// and the display size for scrolling.

}

#include <stdlib.h>
//#include <cstring.h>

bool IsNumber(CStringA s2)
{
	int countfalse = 0;
	for (unsigned int g = 0; g < strlen(s2); g++)
	{
		if (std::isdigit(s2[g]) == false)countfalse++;
	}
		if (countfalse>0)	return false;
		return true;
   

}



void CIMAGEandTIMEDlg::OnBnClickedButton2jump()
{
	// TODO: Add your control notification handler code here
	
	CString jumpstr;
	C_EDIT1JUMP.GetWindowText(jumpstr);
	
	CStringA s2 (jumpstr);
	if (IsNumber(s2) == true) {
		int jumpint = atoi(s2);
		if (jumpint <=0 || jumpint > nr_total_images)
		{
			MessageBox(jumpstr + CString("is negative or zero or is greater than total images")); return;
		}
		k = jumpint - 1;
	}else 	MessageBox(jumpstr +CString("IS NOT NUMBER"));
}
