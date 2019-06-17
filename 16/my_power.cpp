#include<iostream>
#include<cmath>
using namespace std;
bool invalidinput = false;

bool equal_0(double n){
	double accurate=1e-8;
	if(fabs(n)<accurate)
		return true;
	else
		return false;
}

double power_core(double base, int e){
	double ret = 1.0;
	if(e==0)
		return ret;

	if((e&1) == 0)//是偶数
		ret = power_core(base, e>>1)*power_core(base, e>>1);
	else
		ret = power_core(base, e>>1)*power_core(base, e>>1)*base;

	return ret;
}

double power(double base, int exponent){
	//初始化全局变量
	invalidinput=false;

	if(equal_0(base) ){
		if(exponent<0){
			invalidinput=true;
			return 0;
		}
		else
			return 0;
	}

	double ret=1;
	int abs_exponent = abs(exponent);
	//递归可以实现更高的效率
	ret = power_core(base, abs_exponent);

	if(exponent>0)
		return ret;
	else{
		ret=1/ret;
		return ret;
	}
		
}

int main(int argc, char const *argv[])
{
	double base;
	int exponent;
	cout << "enter base and exponent in order: "<< endl;
	while(cin >> base >> exponent){
		cout << "ans: " << power(base, exponent) << endl;
		if(invalidinput)
			cout << "invalid input" << endl;
	}

	return 0;
}