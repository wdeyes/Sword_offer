#include<iostream>
using namespace std;


int GetFirstK(int* data, int k, int start, int end){
	if(start==end){
		if(data[start]==k)
			return start;
		else{
			return -1;
		}
	}

	int mid = (start+end)/2;
	if(mid>0 && data[mid]==k && data[mid-1]!=k)
		return mid;

	if(data[mid]>=k)
		return GetFirstK(data, k, start, mid);
	else 
		return GetFirstK(data, k, mid+1, end);
}

int GetLastK(int* data, int k, int start, int end){
	if(start==end){
		if(data[start]==k)
			return start;
		else
			return -1;
	}

	int mid = (start+end)/2;
	// cout << mid << endl;
	if(data[mid]==k && mid<end && data[mid+1]!=k)
		return mid;

	if(data[mid]>k)
		return GetLastK(data, k, start, mid);
	else 
		return GetLastK(data, k, mid+1, end);
}

int GetNumberOfK(int* data, int length, int k){
	if(data==nullptr || length<=0)
		return 0;

	int first = GetFirstK(data, k, 0, length-1);
	//cout << first;
	if(first < 0)
		return 0;

	int last = GetLastK(data, k, first, length-1);
	//cout << last ;

	return last-first+1;
}



// ====================测试代码====================
void Test(const char* testName, int data[], int length, int k, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result = GetNumberOfK(data, length, k);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 查找的数字出现在数组的中间
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11()
{
    Test("Test11", nullptr, 0, 0, 0);
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
    Test10();
    Test11();

    return 0;
}
