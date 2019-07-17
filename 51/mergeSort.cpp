#include<iostream>
using namespace std;

//利用归并排序，time=O(n*logn),space=O(n+logn)=O(n)。
//需要额外 n 的辅助空间。

int core(int* data, int* copy, int start, int end);

int InversePairs(int* data, int length){
	if(data==nullptr || length<=0)
		return 0;

	int* copy = new int[length];
	//这里copy是因为后面使用core函数时copy和data要交换输入顺序。
	for(int i=0; i<length; ++i){
		copy[i]=data[i];
	}

	int ret = core(data, copy, 0, length-1);

	delete[] copy;
	return ret;
}

int core(int* data, int* copy, int start, int end){
	if(start==end)
		return 0;
	//先分成两部分
	int mid = (start+end)/2;
	// 注意这里data在第二个输入位置。进入 core 后，data 出来是排序好的，下面用data，copy当做辅助空间。
	int left = core(copy, data, start, mid); 
	int right = core(copy, data, mid+1, end);
	//再合并
	int i=mid, j=end, p=end;
	int count=0;

	while(i>=start && j>=mid+1){
		if(data[i]>data[j]){
			count+=j-mid;
			copy[p--]=data[i--];
		}
		else{
			copy[p--]=data[j--];
		}
	}
	for(;i>=start; --i)
		copy[p--]=data[i];
	for(; j>=mid+1; --j)
		copy[p--]=data[j];

	return left+right+count;
}




// ====================测试代码====================
void Test(const char* testName, int* data, int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(InversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int data[] = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
}

void Test9()
{
    int data[] = { 7, 5, 6, 4};
    int expected = 5;

    Test("Test9", data, sizeof(data) / sizeof(int), expected);
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
