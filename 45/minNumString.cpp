#include<iostream>
#include<exception>
#include<algorithm>
#include<time.h>
//#include<string>
//#include<string.h>
using namespace std;

//Solution1：我的实现，书上的利用 stl，更简洁易实现。见 Solution2。
int RandInRange(int start, int end){
	srand( (int)time(0) );
	int ret=rand();
	ret= ret%(end-start+1)+start;
	return ret;
}

bool Smaller(const char* str1, const char* str2){
	if(str1==nullptr || str2==nullptr)
		throw "Smaller function error.";
	char* mStr1 = new char[1];
	char* mStr2 = new char[1];
	strcpy(mStr1, str1);
	strcpy(mStr2, str2);
	strcat(mStr1, str2);
	strcat(mStr2, str1);
	//cout << "mStr1: " << mStr1 << endl;
	//cout << "mStr2: " << mStr2 << endl;
	int length=strlen(mStr1);
	bool ret=false;
	for(int i=0; i<length; ++i){
		if(mStr1[i]<mStr2[i]){
			ret=true;
			break;
		}
		else if(mStr1[i]>mStr2[i]){
			ret=false;
			break;
		}
	}
	delete[] mStr1;
	delete[] mStr2;
	//cout << ret << endl; 
	return ret;
}

int Partiion(char** sNumbers, int nLength, int start, int end){
	if(sNumbers==nullptr || nLength<=0 || start <0 || end>=nLength)
		throw "Partion error.";

	int index = RandInRange(start, end);

	swap(sNumbers[index], sNumbers[end]);

	int small = start-1;
	for(int i=start; i<end; ++i){
		if(Smaller(sNumbers[i], sNumbers[end]) ){
			++small;
			if(small!=i)
				swap(sNumbers[i], sNumbers[small]);
		}
	}
	++small;
	swap(sNumbers[small],sNumbers[end]);

	return small;
}

void Qsort(char** sNumbers, int nLength, int start, int end){
	if(start==end)
		return;
	int index = Partiion(sNumbers, nLength, start, end);
	if(index >start)
		Qsort(sNumbers, nLength, start, index-1);
	if(index < end)
		Qsort(sNumbers, nLength, index+1, end);
}

void PrintMinNumber1(const int* pNumbers, int nLength){
	if(pNumbers==nullptr || nLength<=0)
		return;
	char** sNumbers = new char*[nLength];
	for(int i=0; i<nLength; ++i){
		sNumbers[i] = new char[1];
		sprintf(sNumbers[i], "%d", pNumbers[i]);
	}

	Qsort(sNumbers, nLength, 0, nLength-1);

	for(int i=0; i<nLength; ++i){
		cout << sNumbers[i];
	}
	cout << endl;

	for(int i=0; i<nLength; ++i)
		delete[] sNumbers[i];
	delete[] sNumbers;
}






// //Solution2 on the book.
int cmp(const void* str1, const void* str2){
	char* pStr1Temp=new char[1];
	char* pStr2Temp=new char[1];
	strcpy(pStr1Temp, *(char**)str1 );
	strcat(pStr1Temp, *(char**)str2 );
	strcpy(pStr2Temp, *(char**)str2 );
	strcat(pStr2Temp, *(char**)str1 );
	return strcmp(pStr1Temp, pStr2Temp);
}

void PrintMinNumber2(const int* pNumbers, int nLength){
	if(pNumbers==nullptr || nLength<=0)
		return;
	char** sNumbers = new char*[nLength];
	for(int i=0; i<nLength; ++i){
		sNumbers[i] = new char[1];
		sprintf(sNumbers[i], "%d", pNumbers[i]);
	}
	qsort(sNumbers, nLength, sizeof(char*), cmp);

	for(int i=0; i<nLength; ++i){
		cout << sNumbers[i];
	}
	cout << endl;

	for(int i=0; i<nLength; ++i)
		delete[] sNumbers[i];
	delete[] sNumbers;
}









// ====================测试代码====================
void Test(const char* testName, int* numbers, int length, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    if(expectedResult != nullptr)
        printf("Expected result is: \t%s\n", expectedResult);

    printf("Actual result is: \n");
    PrintMinNumber1(numbers, length);
    PrintMinNumber2(numbers, length);

    printf("\n");
}

void Test1()
{
    int numbers[] = {3, 5, 1, 4, 2};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int), "12345");
}

void Test2()
{
    int numbers[] = {3, 32, 321};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int), "321323");
}

void Test3()
{
    int numbers[] = {3, 323, 32123};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int), "321233233");
}

void Test4()
{
    int numbers[] = {1, 11, 111};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int), "111111");
}

// 数组中只有一个数字
void Test5()
{
    int numbers[] = {321};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int), "321");
}

void Test6()
{
    Test("Test6", nullptr, 0, "Don't print anything.");
}


int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
  

    return 0;
}






