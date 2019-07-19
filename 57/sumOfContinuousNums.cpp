#include <iostream>
using namespace std;

void mPrint(int start, int end){
	while(start<=end)
		cout << start++ << " ";
	cout << endl;
}
void FindContinuousSequence(int sum){
	if(sum<3)
		return;

	int small=1, big=2;
	int mid = (1+sum/2);
	int s = 3;
	while(small <= mid){
		if(s == sum){
			mPrint(small, big);
			++big;
			s+=big;
		}
		else if(s<sum){
			++big;
			s+=big;
		}
		else {
			s-=small;
			++small;
		}
	}
}



// ====================测试代码====================
void Test(const char* testName, int sum)
{
    if(testName != nullptr)
        printf("%s for %d begins: \n", testName, sum);

    FindContinuousSequence(sum);
}

int main(int argc, char* argv[])
{
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    return 0;
}
