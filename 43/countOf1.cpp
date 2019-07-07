#include<iostream>
using namespace std;


//青铜解法
int NumberOf1Between1AndN_Solution1(int n){
	if(n<1)
		return 0;
	int count=0;
	for (int i = 1; i <= n; ++i)
	{
		int num=i;
		while(num>0){
			if(num%10==1)
				++count;
			num/=10;
		}
	}
	return count;
}


//参考《编程之美》“1的数目”
int NumberOf1Between1AndN_Solution2(int n){
	if(n<0)
		return 0;

	int iFacter=1;//利用 iFacter 不仅能按照数位遍历，还能用来当做系数使用。
	int count=0;
	int iCur=0, iHigher=0, iLower=0;
	while(n/iFacter!=0){
		iCur=(n/iFacter)%10;
		iHigher=n/(iFacter*10);
		iLower=n - (n/iFacter)*iFacter;
		switch(iCur){
			case 0:
				count += iHigher*iFacter;
				break;
			case 1:
				count += iHigher*iFacter + iLower+1;
				break;
			default:
				count += (iHigher+1)*iFacter;
		}
		iFacter *= 10;
	}
	return count;
}




// ====================测试代码====================
void Test(const char* testName, int n, int expected)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);
    
    if(NumberOf1Between1AndN_Solution1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n"); 
    
    if(NumberOf1Between1AndN_Solution2(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n"); 

    printf("\n");
}

void Test()
{
    Test("Test1", 1, 1);
    Test("Test2", 5, 1);
    Test("Test3", 10, 2);
    Test("Test4", 55, 16);
    Test("Test5", 99, 20);
    Test("Test6", 10000, 4001);
    Test("Test7", 21345, 18821);
    Test("Test8", 0, 0);
}

int main(int argc, char* argv[])
{
    Test();

    return 0;
}
