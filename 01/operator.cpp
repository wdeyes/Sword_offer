#include <iostream>
using namespace std;

class Mystring
{
public:
	Mystring(char* pData=nullptr);
	Mystring(const Mystring& str);
	~Mystring(){delete[] m_pData;}
	Mystring& operator = (const Mystring& str);
	void print(){
		 cout << m_pData << endl;
		//printf("%s\n", m_pData);
	}
private:
	char* m_pData;
};

Mystring::Mystring(char* pData){
	if(pData==nullptr){
		// m_pData=new char[1];
		// m_pData	[0]='\0';
		m_pData=nullptr;
	}
	else{
		int l = strlen(pData);
		m_pData = new char[l+1];
		strcpy(m_pData, pData);
	}
}

Mystring::Mystring(const Mystring& str){
	m_pData=new char [strlen(str.m_pData)+1];
	strcpy(m_pData, str.m_pData);
}

Mystring& Mystring::operator = (const Mystring& str){
	if(this==&str)
		return *this;

	delete[] m_pData;
	m_pData=nullptr;

	m_pData=new char[strlen(str.m_pData)+1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

int main(int argc, char const *argv[])
{
	// char* str_hello="hello";
	char str_hello[]="hello";
	cout << str_hello << endl;
	Mystring a(str_hello);
	Mystring b;
	b=a;
	Mystring c(str_hello);
	a.print();
	b.print();
	c.print();	
	return 0;
}







