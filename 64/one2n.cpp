#include <iostream>
using namespace std;


// Solution 1: 循环，构造函数，静态成员变量实现
class forStatic{
public:
	forStatic(){
		++num;
		sum += num;
	}
	static void reset(){
		sum=0;
		num=0;
	}
	static unsigned int getSum(){
		return sum;
	}

private:
	static unsigned int num;
	static unsigned int sum;
};
unsigned int forStatic::num=0;
unsigned int forStatic::sum=0;

unsigned int Sum_Solution1(int n){
	forStatic::reset();
	forStatic* nums = new forStatic[n];
	delete[] nums;
	nums=nullptr;
	return forStatic::getSum();
}


// Solution 2: 递归，虚函数实现条件判断
class A{
public:
	virtual unsigned int getSum(int n){
		return 0;
	}
};
A* numsA[2];
class B:public A{
	virtual unsigned int getSum(int n){
		return n + numsA[!!n]->getSum(n-1);
	}
};
unsigned int Sum_Solution2(int n){
	A a;
	B b;
	numsA[0]=&a;
	numsA[1]=&b;
	return numsA[1]->getSum(n);
}


//Solution 3: 递归，函数指针实现条件判断
typedef unsigned int (*fun)(int n);
unsigned int Sum_Solution3_Initial(int n){
	return 0;
}
unsigned int Sum_Solution3(int n){
	fun nums[2]={Sum_Solution3_Initial, Sum_Solution3};
	return n+nums[!!n](n-1);
}



//Solution 4:
template <unsigned int n> struct Sum_Solution4
{
    enum Value { N = Sum_Solution4<n - 1>::N + n};
};

// template <> struct Sum_Solution4<1>
// {
//     enum Value { N = 1};
// };

template <> struct Sum_Solution4<0>
{
    enum Value { N = 0};
};




//Solution 5: 递归，&& 判断具有短路特性，也就是前面判断过了就要判断后面，也就是执行后面，当n=0，判断没过就不执行后面了。
unsigned int Sum_Solution5(int n){
	unsigned int sum = n;
	bool b = (n>0) && ((sum += Sum_Solution5(n-1) )>0);
	return sum;
}



// ====================测试代码====================
void Test(int n, int expected)
{
    printf("Test for %d begins:\n", n);

    if(Sum_Solution1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if(Sum_Solution2(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    if(Sum_Solution3(n) == expected)
        printf("Solution3 passed.\n");
    else
        printf("Solution3 failed.\n");

    if(Sum_Solution5(n) == expected)
    	printf("Solution5 passed.\n");
    else
        printf("Solution5 failed.\n");
}

void Test1()
{
    const unsigned int number = 1;
    int expected = 1;
    Test(number, expected);
    if(Sum_Solution4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

void Test2()
{
    const unsigned int number = 5;
    int expected = 15;
    Test(number, expected);
    if(Sum_Solution4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

void Test3()
{
    const unsigned int number = 10;
    int expected = 55;
    Test(number, expected);
    if(Sum_Solution4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

void Test4()
{
    const unsigned int number = 0;
    int expected = 0;
    Test(number, expected);
    if(Sum_Solution4<number>::N == expected)
        printf("Solution4 passed.\n");
    else
        printf("Solution4 failed.\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}