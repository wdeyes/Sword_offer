#include<iostream>
using namespace std;


void FindNumsAppearOnce(int* data, int length, int* result1, int* result2){
	if(data==nullptr || length<2)
		return;

	int twoNum=data[0];
	for(int i=1; i<length; ++i){
		twoNum=twoNum^data[i];
	}

	int index=0;//从右起第index位为1
	while( (twoNum&1)!=1 && index<(sizeof(int)*8) ){
		twoNum = twoNum>>1;
		++index;
	}

	*result1=0;
	*result2=0;
	for(int i=0; i<length; ++i){
		if( ((data[i]>>index)&1)==1 )
			*result1 ^= data[i];
		else
			*result2 ^= data[i];
	}
}




// ====================测试代码====================
void Test(const char* testName, int data[], int length, int expected1, int expected2)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result1, result2;
    FindNumsAppearOnce(data, length, &result1, &result2);

    if((expected1 == result1 && expected2 == result2) ||
        (expected2 == result1 && expected1 == result2))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

void Test1()
{
    int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
    Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2()
{
    int data[] = { 4, 6 };
    Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3()
{
    int data[] = { 4, 6, 1, 1, 1, 1 };
    Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
