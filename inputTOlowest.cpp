
// Ա��ҵ��¼��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ա��ҵ��¼��.h"
#include "Ա��ҵ��¼��Dlg.h"
#include "afxdialogex.h"
#include "stdio.h"
#include <string.h>  
#include <string>
#include <algorithm>  
#include <iostream>  
#include <map>
#include <queue>
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


// CԱ��ҵ��¼��Dlg �Ի���



CԱ��ҵ��¼��Dlg::CԱ��ҵ��¼��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CԱ��ҵ��¼��Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CԱ��ҵ��¼��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CԱ��ҵ��¼��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CԱ��ҵ��¼��Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CԱ��ҵ��¼��Dlg ��Ϣ�������

BOOL CԱ��ҵ��¼��Dlg::OnInitDialog()
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

void CԱ��ҵ��¼��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CԱ��ҵ��¼��Dlg::OnPaint()
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
HCURSOR CԱ��ҵ��¼��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

struct note
{
	int v,next;
};
struct note edge[100100];
map<string,int> mp;
string Hash[100100];
int head[100500],ip;

void init()
{
	memset(head,-1,sizeof(head));
	ip=0;
}
void addedge(int u,int v)
{
	edge[ip].v=v,edge[ip].next=head[u],head[u]=ip++;
}

int bfs(int u)
{
	queue<pair<int,int> >q;
	q.push(make_pair(u,0));
	int maxx=-1,ans;
	while(!q.empty())
	{
		u=q.front().first;
		int dep=q.front().second;
		if(dep>maxx)
		{
			ans=u;
		}
		q.pop();
		for(int i=head[u];i!=-1;i=edge[i].next)
		{
			int v=edge[i].v;
			q.push(make_pair(v,dep+1));
		}
	}
	return ans;
}
void CԱ��ҵ��¼��Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString name;
	CString id;
	CString year;
	CString mon;
	CString day;
	CString sum;
	GetDlgItemText(IDC_EDIT1,name);
	GetDlgItemText(IDC_EDIT2,id);
	GetDlgItemText(IDC_EDIT3,year);
	GetDlgItemText(IDC_EDIT4,mon);
	GetDlgItemText(IDC_EDIT5,day);
	GetDlgItemText(IDC_EDIT6,sum);
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
        std:string name1,id1,year1,mon1,day1,sum1; 
		name1=(char *)_bstr_t(name);
		id1=(char *)_bstr_t(id);
		year1=(char *)_bstr_t(year);
		mon1=(char *)_bstr_t(mon);
		day1=(char *)_bstr_t(day);
		sum1=(char *)_bstr_t(sum);
		char name3[100],id3[100],year3[100],mon3[100],day3[100],sum3[100];
		const char *name2,*id2,*year2,*mon2,*day2,*sum2;
		name2=name1.c_str();
		id2=id1.c_str();
		year2=year1.c_str();
		mon2=mon1.c_str();
		day2=day1.c_str();
		sum2=sum1.c_str();
		strcpy(name3,name2);
		strcpy(id3,id2);
		strcpy(year3,year2);
		strcpy(mon3,mon2);
		strcpy(day3,day2);
		strcpy(sum3,sum2);
		char sql[300];

		///
		sprintf(sql,"select id,father_id from users");
		mysql_query(sock,sql);
		MYSQL_RES *res; 
		MYSQL_ROW row;
		res=mysql_store_result( sock) ;//ȡ�ò�ѯ���,�����ѯ�������ݵ�res 
		int num=0;
		while(row=mysql_fetch_row(res))
		{
			mp[row[0]]=num;
			Hash[num]=row[0];
			num++;
		}
		mysql_query(sock,sql);
		res=mysql_store_result( sock) ;
		init();
		bool flag=1;
		while(row=mysql_fetch_row(res))
		{
			if(flag)
			{
				flag=0;
				continue;
			}
			int u=mp[row[1]];//����
			int v=mp[row[0]];//����
			addedge(u,v);
		}
		int u=mp[id1];///��ǰ����Ľڵ�
		int ans=bfs(u);///Ҫ����ֵ�Ľڵ�
		string res0=Hash[ans];
		const char *res1;
		char res2[30];
		res1=res0.c_str();
		strcpy(res2,res1);
        sprintf( sql,"insert into works values('%s','%s-%s-%s','%s');",res2,year2,mon2,day2,sum2);
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
