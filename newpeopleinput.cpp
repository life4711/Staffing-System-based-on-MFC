
// ��Ա��¼��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��Ա��¼��.h"
#include "��Ա��¼��Dlg.h"
#include "afxdialogex.h"
#include "stdio.h"
#include <string.h>  
#include <string>
#include <algorithm>  
#include <iostream>  
#include "winsock.h"  
//#include "trans.h"
#include "mysql.h"  
using namespace std;  
#pragma comment (lib, "libmysql.lib")  
#pragma comment (lib, "mysqlclient.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C��Ա��¼��Dlg �Ի���



C��Ա��¼��Dlg::C��Ա��¼��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��Ա��¼��Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��Ա��¼��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C��Ա��¼��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C��Ա��¼��Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C��Ա��¼��Dlg ��Ϣ�������

BOOL C��Ա��¼��Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��Ա��¼��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C��Ա��¼��Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C��Ա��¼��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


const char* CStrToChar(CString strSrc)
{
    #ifdef UNICODE
        DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, strSrc.GetBuffer(0), -1, NULL, 0, NULL, FALSE);
        char *psText;
        psText = new char[dwNum];
        if (!psText)
            delete []psText;
        WideCharToMultiByte(CP_OEMCP, NULL, strSrc.GetBuffer(0), -1, psText, dwNum, NULL, FALSE);
        return (const char*)psText;
    #else
        return (LPCTSRT)strSrc;
    #endif
}

void C��Ա��¼��Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name;
	CString id;
	CString father_name;
	CString father_id;
	CString father_ab;
	GetDlgItemText(IDC_EDIT1,name);
	GetDlgItemText(IDC_EDIT2,id);
	GetDlgItemText(IDC_EDIT3,father_name);
	GetDlgItemText(IDC_EDIT4,father_id);
	GetDlgItemText(IDC_EDIT5,father_ab);
	//int aa=_ttoi(a);
	//aa=aa*aa;
	//b.Format(_T("%d"),aa);
	//SetDlgItemText(IDC_EDIT2,b);
	char *host = "localhost";  
    char *user = "root";//mysql���û���  
    char *pass = "root";//���mysql����������  
    char *db = "employee";  
    unsigned int port = 3306; //server port  
    MYSQL *sock;  
    sock=mysql_init(0);  
    if(sock &&mysql_real_connect(sock,host,user,pass,db,0,NULL,0))  
    {  
		mysql_query(sock,"SET NAMES 'gbk'");
		//std::string sql="insert into lv values('��Ƚ',1)";
        std:string name1,id1,father_id1,father_name1,father_ab1; 
		name1=(char *)_bstr_t(name);
		id1=(char *)_bstr_t(id);
		father_name1=(char *)_bstr_t(father_name);
		father_id1=(char *)_bstr_t(father_id);
		father_ab1=(char *)_bstr_t(father_ab);
		char name3[100],id3[100],father_name3[100],father_id3[100],father_ab3[100];
		const char *name2,*id2,*father_name2,*father_id2,*father_ab2;
		name2=name1.c_str();
		id2=id1.c_str();
		father_name2=father_name1.c_str();
		father_id2=father_id1.c_str();
		father_ab2=father_ab1.c_str();
		strcpy(name3,name2);
		strcpy(id3,id2);
		strcpy(father_name3,father_name2);
		strcpy(father_id3,father_id2);
		strcpy(father_ab3,father_ab2);
		char sql[300];
		sprintf( sql,"insert into users(name,id,father_name,father_id,father_ab) values('%s','%s','%s','%s','%s');",name3,id3,father_name3,father_id3,father_ab3);
		//sprintf(sql,"insert into %s",bbb);
		//b=name.c_str();
		if(mysql_query(sock,sql)==0)
		{
		    CString retu(_T("����ɹ���"));
			SetDlgItemText(IDC_EDIT2,retu);
		}
		else
		{
			CString retu(_T("����ʧ�ܣ�"));
			SetDlgItemText(IDC_EDIT2,retu);
		}
    }  
    else  
    {  
         CString retu(_T("�������ݿ����"));
		 SetDlgItemText(IDC_EDIT2,retu);
    }   
}
