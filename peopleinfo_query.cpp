
// Ա��������Ϣ��ѯDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ա��������Ϣ��ѯ.h"
#include "Ա��������Ϣ��ѯDlg.h"
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


// CԱ��������Ϣ��ѯDlg �Ի���



CԱ��������Ϣ��ѯDlg::CԱ��������Ϣ��ѯDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CԱ��������Ϣ��ѯDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CԱ��������Ϣ��ѯDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CԱ��������Ϣ��ѯDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CԱ��������Ϣ��ѯDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CԱ��������Ϣ��ѯDlg ��Ϣ�������

BOOL CԱ��������Ϣ��ѯDlg::OnInitDialog()
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

void CԱ��������Ϣ��ѯDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CԱ��������Ϣ��ѯDlg::OnPaint()
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
HCURSOR CԱ��������Ϣ��ѯDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CԱ��������Ϣ��ѯDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name;
	CString id;
	GetDlgItemText(IDC_EDIT1,name);
	GetDlgItemText(IDC_EDIT2,id);
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
        std:string name1,id1,father_id1,father_name1,father_ab1; 
		name1=(char *)_bstr_t(name);
		id1=(char *)_bstr_t(id);
		char name3[100],id3[100];
		const char *name2,*id2;
		name2=name1.c_str();
		id2=id1.c_str();
		strcpy(name3,name2);
		strcpy(id3,id2);
		char sql[300];
		sprintf( sql,"select father_id,father_name,father_ab from users where id='%s'and name='%s';",id3,name3);
		//sprintf(sql,"insert into %s",bbb);
		//b=name.c_str();
		mysql_query(sock,sql);
		MYSQL_RES *res; 
		MYSQL_ROW row;
		res=mysql_store_result( sock) ;//ȡ�ò�ѯ���,�����ѯ�������ݵ�res 
		int num=0;
		if(row=mysql_fetch_row(res))
		{
			string num1=row[0],num2=row[1],num3=row[2];
			CString father_name;
			CString father_id;
			CString father_ab;
			father_id=num1.c_str();
			father_name=num2.c_str();
			father_ab=num3.c_str();
			SetDlgItemText(IDC_EDIT3,father_name);
			SetDlgItemText(IDC_EDIT4,father_id);
			SetDlgItemText(IDC_EDIT5,father_ab);
		}
		else
		{
			CString retu(_T("������Ϣ����"));
			SetDlgItemText(IDC_EDIT3,retu);
		}
    }  
    else  
    {  
         CString retu(_T("�������ݿ����"));
		 SetDlgItemText(IDC_EDIT2,retu);
    }   
}
