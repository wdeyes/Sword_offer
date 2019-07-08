#include<iostream>
#include<cmath>
using namespace std;


int digitAtIndex(int n){
	if(n<0)
		return -1;
	int ret=n;
	if(n<10)
		return ret;

	int nCount=n-9;
	int nFacter=2;//两位数
	int nSum=180;//两位数占180个位置
	while(nCount>nSum){
		nCount-=nSum;
		++nFacter;
		nSum=9*pow(10, nFacter-1)*nFacter;
	}
	int nStart=pow(10, nFacter-1);
	int nRemainder = nCount % nFacter;
	//如果余数等于 0，则要的数字在上一个 nNnm 的最后一位。
	int nNum = nStart + (nCount/nFacter);
	if(nRemainder==0){
		--nNum;
		ret=nNum % 10;
	}
	else
		ret = nNum/( (int)pow(10, nFacter- nRemainder) ) % 10;
	return ret;
}



// ====================测试代码====================
void test(const char* testName, int inputIndex, int expectedOutput)
{
	if(digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}


int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // 数字99的最后一位，9
	test("Test6", 190, 1);  // 数字100的第一位，1
	test("Test7", 1000, 3); // 数字370的第一位，3
	test("Test8", 1001, 7); // 数字370的第二位，7
	test("Test9", 1002, 0); // 数字370的第三位，0
	return 0;
}





