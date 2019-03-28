#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int>::iterator t;
	vector<int> a(5, 0);
	for(t=a.begin();t!=a.end();t++){
		cout << *t << " ";
	}
	cout << endl;
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	a.insert(a.begin()+2,1);
	for(t=a.begin();t!=a.end();t++){
		cout << *t << " ";
	}
	cout << endl;
	cout << a.size() << endl;
	cout << a.capacity() << endl;

	int* nums=new int[3];
	for(int i=0; i<5; i++){
		cout << nums[i] << " " ;
	}
	cout << endl;
	nums[4]=233;
	for(int i=0; i<5; i++){
		cout << nums[i] << " " ;
	}
	cout << endl;

	//动态数组没有长度，不能这么求，这是求静态数组长度的。
	//cout << "length: " << sizeof(nums)/sizeof(nums[0]) << endl;
	delete[] nums;
	return 0;
}
