#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Solution1
int LastRemaining_Solution1(unsigned int n, unsigned int m){
	if(n<=0 || m<=0)
		return -1;

	list<int> myList;
	for(int i=0; i<n; ++i)
		myList.push_back(i);

	list<int>::iterator it = myList.begin();
	int maybe;
	while(!myList.empty()){
		for(int i=0; i<m-1; ++i){
			++it;
			if(it==myList.end())
				it=myList.begin();
		}
		maybe = *it;
		list<int>::iterator will_erase = it;
		if(++it==myList.end())
			it=myList.begin();
		myList.erase(will_erase);
	}
	return maybe;
}


//Solution2 强大的数学退出递推关系
int LastRemaining_Solution2(unsigned int n, unsigned int m){
	if(n<=0 || m<=0)
		return -1;

	vector<int> ans(n+1);
	ans[1]=0;
	for(int i=2; i<=n; ++i){
		ans[i] = (ans[i-1]+m)%i;
	}
	return ans[n];
}



// ====================测试代码====================
void Test(const char* testName, unsigned int n, unsigned int m, int expected)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    if(LastRemaining_Solution1(n, m) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if(LastRemaining_Solution2(n, m) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void Test1()
{
    Test("Test1", 5, 3, 3);
}

void Test2()
{
    Test("Test2", 5, 2, 2);
}

void Test3()
{
    Test("Test3", 6, 7, 4);
}

void Test4()
{
    Test("Test4", 6, 6, 3);
}

void Test5()
{
    Test("Test5", 0, 0, -1);
}

void Test6()
{
    Test("Test6", 4000, 997, 1027);
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
