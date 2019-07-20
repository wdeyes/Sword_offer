#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

//动态规划 time=O(n^2) space=O(n^2)
void PrintProbability_Solution1(int n){
	if(n<1)
		return;

	const int face = 6;
	const int maxNum = face*n;
	//创建 rows=n+1, cols=maxNum+1 的二维数组，初始化为0，i代表骰子个数，j代表有i个骰子时投出j点的次数
	vector< vector<long> > dp(n+1, vector<long>(maxNum+1) );
	for(int i=0; i<n+1; ++i)
		for(int j=0; j<maxNum+1; ++j)
			dp[i][j]=0;
	// 有一个骰子时，投出每个点的次数为1
	for(int i=1; i<=face; ++i)
		dp[1][i]=1;
	// 从2个骰子开始，更新投出点数j的次数, i个骰子最小的点数为i，所以j从i开始
	for(int i=2; i<=n; ++i){
		for(int j=i; j<=maxNum; ++j){
			//递推关系,k为新加入的这个骰子投出的点数，则j-k为前面骰子投出的点数
			for(int k=1; k<=face && j-k>0; ++k)
				dp[i][j]+=dp[i-1][j-k];
		}
	}
	double total = pow(6, n);
	for(int i=n; i<=maxNum; ++i){
		double probability = dp[n][i]/total;
		cout << i << ": " << setiosflags(ios::scientific) << probability << endl;
	}

}

// time=O(n^2) space O(n)
void PrintProbability_Solution2(int n){
	if(n<1)
		return;

	const int face = 6;
	const int maxNum = face*n;
	//因为每次只用上一次的，所以使用两行的数组就可以了,节省空间。
	//两行数组交换着使用，叫旋转数组。
	vector< vector<long> > dp(2, vector<long>(maxNum+1));

	for(int i=1; i<=face; ++i)
		dp[0][i]=1;

	int flag=1;
	for(int i=2; i<=n; ++i){
		//不要忘了清零
		for(int j=0; j<=maxNum; ++j)
			dp[flag][j]=0;

		for(int j=i; j<=maxNum; ++j){
			for(int k=1; k<=face && j-k>0; ++k)
				dp[flag][j] += dp[1-flag][j-k];
		}
		flag=1-flag;
	}
	double total = pow(6, n);
	for(int i=n; i<=maxNum; ++i){
		double probability = dp[1-flag][i]/total;
		cout << i << ": " << setiosflags(ios::scientific) << probability << endl;
	}
}


// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);
    
    printf("Test for solution1\n");
    PrintProbability_Solution1(n);

    printf("Test for solution2\n");
    PrintProbability_Solution2(n);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(4);
    
    Test(11);

    Test(0);

    return 0;
}
