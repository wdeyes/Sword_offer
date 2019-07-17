#include<iostream>
using namespace std;

int core(int* numbers, int start, int end){
	if(start==end)
		return start;

	int mid = (start+end)/2;
	if(numbers[mid]==mid)
		return core(numbers, mid+1, end);
	else
		return core(numbers, start, mid);
}


int GetMissingNumber(int* numbers, int length){
	if(numbers==nullptr || length<=0)
		return -1;

	if(numbers[length-1]==length-1)
		return length;

	return core(numbers, 0, length-1);
}




// ====================测试代码====================
void Test(const char* testName, int numbers[], int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result = GetMissingNumber(numbers, length);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 缺失的是第一个数字0
void Test1()
{
    int numbers[] = { 1, 2, 3, 4, 5 };
    int expected = 0;
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是最后一个数字
void Test2()
{
    int numbers[] = { 0, 1, 2, 3, 4 };
    int expected = 5;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是中间某个数字0
void Test3()
{
    int numbers[] = { 0, 1, 2, 4, 5 };
    int expected = 3;
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是第一个数字0
void Test4()
{
    int numbers[] = { 1 };
    int expected = 0;
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是最后一个数字1
void Test5()
{
    int numbers[] = { 0 };
    int expected = 1;
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 空数组
void Test6()
{
    int expected = -1;
    Test("Test6", nullptr, 0, expected);
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