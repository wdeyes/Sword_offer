#include<iostream>
#include<vector>
#include <algorithm>
#include<exception>
#include<cmath>
using namespace std;

template <typename T> class DynamicArray{
public:
	void Insert(T num){
		if( ( (max.size()+min.size() )&1) ==0){
			if(max.size()>0 && num<max[0]){
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<T>());
				num=max[0];
				pop_heap(max.begin(), max.end(), less<T>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());
		}
		else{
			if(min.size()>0 && num>min[0]){
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<T>());
				num=min[0];
				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		}
	}

	T GetMedian(){
		if(max.size()==0 && min.size()==0)
			throw "Max and min are null.";
			//throw exception("No numbers are available");
		
		T ret;
		if( ( (max.size()+min.size())&1) ==1)
			ret=min[0];
		else
			ret=(max[0]+min[0])/2;
		return ret;
	}

private:
	vector<T> max;
	vector<T> min;
};








// ====================测试代码====================
void Test(const char* testName, DynamicArray<double>& numbers, double expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(fabs(numbers.GetMedian() - expected) < 0.0000001)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    DynamicArray<double> numbers;

    printf("Test1 begins: ");
    try
    {
        numbers.GetMedian();
        printf("FAILED.\n");
    }
    catch(const char* msg)
    {
        printf("Passed.\n");
    }

    numbers.Insert(5);
    Test("Test2", numbers, 5);

    numbers.Insert(2);
    Test("Test3", numbers, 3.5);

    numbers.Insert(3);
    Test("Test4", numbers, 3);

    numbers.Insert(4);
    Test("Test6", numbers, 3.5);

    numbers.Insert(1);
    Test("Test5", numbers, 3);

    numbers.Insert(6);
    Test("Test7", numbers, 3.5);

    numbers.Insert(7);
    Test("Test8", numbers, 4);

    numbers.Insert(0);
    Test("Test9", numbers, 3.5);

    numbers.Insert(8);
    Test("Test10", numbers, 4);

    return 0;
}
