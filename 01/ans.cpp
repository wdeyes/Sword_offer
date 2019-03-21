#include<iostream>
#include <string>
using namespace std;
class CMyString
{
public:
	CMyString(char* pdata=nullptr);
	CMyString(const CMyString& str);
	CMyString& operator=(const CMyString &str);
	~CMyString(){delete[] m_pData;}
	void print(){printf("%s\n",m_pData);}
private:
	char* m_pData;
};
CMyString::CMyString(char* pdata)
{
	if (pdata==nullptr)
	{
		m_pData=nullptr;
		return;
	}
	m_pData=new char[strlen(pdata)+1];
	strcpy(m_pData,pdata);
}
CMyString::CMyString(const CMyString& str)
{
	m_pData=new char[strlen(str.m_pData)+1];
	strcpy(m_pData,str.m_pData);
}
CMyString& CMyString::operator=(const CMyString &str)
{
	//考虑到异常安全的写法
	if (this!=&str)
	{
		CMyString strTemp(str);
		char* pTemp=strTemp.m_pData;
		strTemp.m_pData=m_pData;
		m_pData=pTemp;	
	}
	return *this;
	//能实现功能，但是没有考虑到异常安全
	/*if (this==&str)
	{
		return *this;
	}
	else
	{
		delete[] m_pData;
		m_pData=nullptr;
		m_pData=new char[strlen(str.m_pData)+1];
		strcpy(m_pData,str.m_pData);
		return *this;
	}*/
}
int main()
{
	printf("test01\n");
	char text[]="add";
	CMyString aa;

	CMyString a(text);
	CMyString bb(a);
	
	CMyString b,c;
	//连续赋值
	c=b=a;
	c.print();
	//赋值给自己
	c=c;
	c.print();
 
	cin.get();

}