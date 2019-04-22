#include<iostream>
#include<assert.h>
using namespace std;

long long solve1(unsigned int n){
	if(n<=0)
		return 0;
	if(n==1)
		return 1;

	return solve1(n-1)+solve1(n-2);
}

long long solve2(unsigned int n){
	int result[2]={0,1};
	if(n<2)
		return result[n];

	long long two_pre=0;
	long long one_pre=1;
	long long cur=0;
	for(int i=2; i<=n; ++i){
		cur=two_pre+one_pre;
		two_pre=one_pre;
		one_pre=cur;
	}
	return cur;;
}

struct matrix2_2{
	matrix2_2(long long e00=0, long long e01=0,long long e10=0, long long e11=0)
	   :my_e00(e00), my_e01(e01), my_e10(e10), my_e11(e11)
   	{
	}

	long long my_e00;
	long long my_e01;
	long long my_e10;
	long long my_e11;
};	   

matrix2_2 mult(const matrix2_2& matrix1, const matrix2_2& matrix2){
	matrix2_2 ret(
		matrix1.my_e00*matrix2.my_e00 + matrix1.my_e01*matrix2.my_e10,
		matrix1.my_e00*matrix2.my_e01 + matrix1.my_e01*matrix2.my_e11,
		matrix1.my_e10*matrix2.my_e00 + matrix1.my_e11*matrix2.my_e10,
		matrix1.my_e10*matrix2.my_e01 + matrix1.my_e11*matrix2.my_e11		
	);
	return ret;
}

matrix2_2 solve3_core(unsigned int n){
	assert(n>0);
	if(n==1)
		return matrix2_2(1,1,1,0);

	matrix2_2 ret;
	if(n%2==0){
		ret = mult(solve3_core(n/2), solve3_core(n/2));		
	}
	else{
		matrix2_2 temp=mult(solve3_core((n-1)/2), solve3_core((n-1)/2));
		ret=mult(temp, matrix2_2(1,1,1,0));
	}
	return ret;
}

long long solve3(unsigned int n){
	int result[2]={0,1};
	if(n<2)
		return result[n];
	matrix2_2 m_ans=solve3_core(n-1);
	return m_ans.my_e00;
}

int main(){
	cout << "enter n: "<<endl;
	unsigned int n;
	while(cin >> n){
		cout << "solve2: " << solve2(n) << endl;
		cout << "solve3: " << solve3(n) << endl;
	}
	return 0;
}










