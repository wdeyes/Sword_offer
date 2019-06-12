#include <iostream>
#include <cmath>
using namespace std;

//递归思路 循环实现
int max(int n){
	if(n<2)
		return 0;
	if(n==2)
		return 1;
	if(n==3)
		return 2;

	int nums[n+1];
	nums[0]=0;
	nums[1]=1;
	nums[2]=2;
	nums[3]=3;

	for (int i = 4; i <= n; ++i)
	{	
		int max=0;
		for(int j=1; j<=i/2; ++j){
			max = nums[j]*nums[i-j] > max? nums[j]*nums[i-j] : max;
		}
		nums[i]=max;
	}
	return nums[n];
}

//贪心算法
int max1(int n){
	if(n<2)
		return 0;
	if(n==2)
		return 1;
	if(n==3)
		return 2;
	if(n==4)
		return 4;
	
	int ret;
	int timesof3 = n/3;
	//余数分为三种情况，1，0，2
	if(n%3==1)
		ret=pow(3, timesof3-1) * 4;
	else if(n%3==0)
		ret=pow(3, timesof3);
	else 
		ret=pow(3, timesof3)*2;

	return ret;
}

int main(int argc, char const *argv[])
{
	cout << "enter n:" << endl;
	int n;
	while(cin >> n)
		cout << "ans: " << max1(n) << endl;
	return 0;
}