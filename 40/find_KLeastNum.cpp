#include<iostream>
#include <vector>
#include <set>
using namespace std;

int RandInRange(int start, int end){
	srand( int(time(0)) );
	int nRand = rand();
	int ret = nRand%(end-start+1) + start;
	//cout << "between "<< start << " and "<< end <<"is" << ret <<endl; 
	return ret;
}

int Partition(int* numbers, int length, int start, int end){
	if(numbers==nullptr || length<=0 || start<0 || end>=length)
		throw "Partition error.";
	//Find randomly a number and put it to the end
	int nRand = RandInRange(start, end);
	swap(numbers[nRand], numbers[end]);
	
	int small = start-1;
	for(int i=start; i<length; ++i){
		if(numbers[i]<numbers[end]){
			++small;
			if(small!=i)
				swap(numbers[i], numbers[small]);
		}
	}
	++small;
	swap(numbers[small], numbers[end]);
	return small;
}

void GetLeastNumbers_Solution1(int* input, int n, int* output, int k){
	if(input==nullptr || n<k || n<=0 || k<=0 || output==nullptr)
		return;

	if(n!=k){
		int start=0, end=n-1;
		int index=Partition(input, n, start, end);
		while(index!=k){
			if(index>k){
				end=index-1;
				index=Partition(input, n, start, end);
			}
			else{
				start=index+1;
				index=Partition(input, n, start, end);
			}
		}
	}
	for(int i=0; i<k; ++i){
		output[i]=input[i];
	}
}


typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;
void GetLeastNumbers_Solution2(const vector<int>& data, intSet& leastNumbers, int k){
	if(data.size()<k || k<=0)
		return;

	leastNumbers.clear();

	for(int i=0; i<data.size(); ++i){
		if(leastNumbers.size()<k)
			leastNumbers.insert(data[i]);
		else if(data[i] < *leastNumbers.begin()){
			leastNumbers.erase(*leastNumbers.begin());
			leastNumbers.insert(data[i]);
		}
	}
}






// ====================测试代码====================
void Test(const char* testName, int* data, int n, int* expectedResult, int k)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    vector<int> vectorData;
    for(int i = 0; i < n; ++ i)
        vectorData.push_back(data[i]);

    if(expectedResult == nullptr)
        printf("The input is invalid, we don't expect any result.\n");
    else
    {
        printf("Expected result: \n");
        for(int i = 0; i < k; ++ i)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }

    printf("Result for solution1:\n");
    int* output = new int[k];
    GetLeastNumbers_Solution1(data, n, output, k);
    if(expectedResult != nullptr)
    {
        for(int i = 0; i < k; ++ i)
            printf("%d\t", output[i]);
        printf("\n");
    }

    delete[] output;

    printf("Result for solution2:\n");
    intSet leastNumbers;
    GetLeastNumbers_Solution2(vectorData, leastNumbers, k);
    printf("The actual output numbers are:\n");
    for(setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
        printf("%d\t", *iter);
    printf("\n\n");
}

// k小于数组的长度
void Test1()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    Test("Test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test2()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test3()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1};
    Test("Test4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于0
void Test5()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int* expected = nullptr;
    Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6()
{
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    int expected[] = {1, 2};
    Test("Test6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test7()
{
    int* expected = nullptr;
    Test("Test7", nullptr, 0, expected, 0);
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

    return 0;
}
