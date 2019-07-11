#include<iostream>
using namespace std;

//Solution1：递归
// void core(char* sNumber, int index, int& count){
// 	if(sNumber==nullptr)
// 		return;

// 	if(sNumber[index]=='\0'){
// 		++count;
// 		return;
// 	}
// 	if(sNumber[index]=='1'){
// 		if(sNumber[index+1]!='\0'){
// 			core(sNumber, index+2, count);
// 			core(sNumber, index+1, count);
// 		}
// 		else
// 			core(sNumber, index+1, count);
// 	}
// 	else if(sNumber[index]=='2'){
// 		if(sNumber[index+1]!='\0' && sNumber[index+1]<'6'){
// 			core(sNumber, index+2, count);
// 			core(sNumber, index+1, count);
// 		}
// 		else
// 			core(sNumber, index+1, count);
// 	}
// 	else
// 		core(sNumber, index+1, count);
// }

// int GetTranslationCount(int number){
// 	char* sNumber = new char[1];
// 	sprintf(sNumber, "%d", number);
// 	if(sNumber[0]<'0' || sNumber[0]>'9')
// 		return 0;

// 	int count=0;
// 	core(sNumber, 0, count);
// 	delete sNumber;
// 	return count;
// }


//Solution2：由下而上
int GetTranslationCount(int number){
	char* sNumber = new char[1];
	sprintf(sNumber, "%d", number);
	if(sNumber[0]<'0' || sNumber[0]>'9')
		return 0;

	int length=strlen(sNumber);

	int ans[length+1];//多的这个为了初始化ans的倒数第二个答案。
	ans[length]=1;

	ans[length-1]=1;
	for(int i=length-2; i>=0; --i){
		if( sNumber[i]=='1'|| (sNumber[i]=='2'&&sNumber[i+1]<'6') )
			ans[i]=ans[i+1]+ans[i+2];
		else
			ans[i]=ans[i+1];
	}
	return ans[0];
}



// ====================测试代码====================
void Test(const string& testName, int number, int expected)
{
    if(GetTranslationCount(number) == expected)
        cout << testName << " passed." << endl;
    else
        cout << testName << " FAILED." << endl;
}

void Test1()
{
    int number = 0;
    int expected = 1;
    Test("Test1", number, expected);
}

void Test2()
{
    int number = 10;
    int expected = 2;
    Test("Test2", number, expected);
}

void Test3()
{
    int number = 125;
    int expected = 3;
    Test("Test3", number, expected);
}

void Test4()
{
    int number = 126;
    int expected = 2;
    Test("Test4", number, expected);
}

void Test5()
{
    int number = 426;
    int expected = 1;
    Test("Test5", number, expected);
}

void Test6()
{
    int number = 100;
    int expected = 2;
    Test("Test6", number, expected);
}

void Test7()
{
    int number = 101;
    int expected = 2;
    Test("Test7", number, expected);
}

void Test8()
{
    int number = 12258;
    int expected = 5;
    Test("Test8", number, expected);
}

void Test9()
{
    int number = -100;
    int expected = 0;
    Test("Test9", number, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
