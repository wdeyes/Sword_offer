#include<iostream>
#include<cmath>
using namespace std;


//青铜解法
//=========================================
void cout_1tomax_1(int n){
	long long max=pow(10, n)-1;
	long long number = 1;
	while(max-- > 0){
		cout << number++ << " ";
	}
	cout << endl;
}


//字符串解决大数问题
//打印：
//打印是从非零开始,并不是为零的都不打印
void print_number(char* number){
	bool isStart=false;
	for (int i = 0; i < strlen(number); ++i)
	{
		if(number[i]!='0' && !isStart){
			isStart=true;
		}
		if(isStart)
			cout << number[i];
	}
}

//大师解法，写出字符串的加一运算
//==============================================

//加一时判断是否到最大
bool add1(char* number){
	bool isOver=false;
	int nLegth=strlen(number);
	int nTakeover=0;
	for (int i = nLegth-1; i>=0 ; --i)
	{
		int nNum=number[i]-'0'+nTakeover;
		if(i==nLegth-1)
			++nNum;

		if(nNum>=10){
			if(i==0)
				isOver=true;
			else{
				nTakeover=1;
				nNum-=10;
				number[i]=nNum+'0';
			}
		}
		else{
			number[i]=nNum+'0';
			break;
		}
	}
	return isOver;
}

void cout_1tomax_2(int n){
	if(n<=0)
		return;

	char* number = new char[n+1];
	memset(number, '0', n);
	number[n]='\0';

	while(!add1(number)){
		print_number(number);
		cout << " ";
	}
	cout << endl;
	delete[] number;
}


//王者解法，全排列问题
//=========================================
void cout_core(char* number, int n, int index){
	if(index==n-1){
		print_number(number);
		cout << " ";
		return;
	}

	for(int i=0; i<10; ++i){
		number[index+1]=i+'0';
		cout_core(number, n, index+1);
	}
}

void cout_1tomax_3(int n){
	if(n<=0)
		return;

	char* number = new char[n+1];
	number[n]='\0';

	for(int i=0; i<10; ++i){
		number[0]=i+'0';
		cout_core(number, n, 0);
	}
	cout << endl;

	delete[] number;
}




int main(int argc, char const *argv[])
{
	int n;
	cout << "enter n: "<< endl;
	while(cin >> n)
		cout_1tomax_3(n);

	return 0;
}


















