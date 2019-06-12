#include <iostream>
using namespace std;

int count(int n){
	int ret=0;
	while(n!=0){
		n=n&(n-1);
		++ret;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int n=0xFFFFFFFF;
	//int n;
	//while(cin >> hex >> n){
		cout << "n: " << n << endl;
		cout << "ans: " << count(n) << endl;
	//}

	return 0;
}