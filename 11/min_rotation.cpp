#include<iostream>
#include <exception>
using namespace std;

int min_circ(int nums[], int start, int end){
	int ret=nums[start];
	for(int i=start; i<=end; ++i){
		ret=(nums[i]<ret)? nums[i]:ret;
	}
	return ret;
}

int min(int nums[], int length){
	if(nums==nullptr || length<=0)
		throw "nums is error";
	int pre=0, beh=length-1, mid=0;
	if(nums[pre]<nums[beh])
		return nums[0];
	while(beh-pre>1){
		mid=(pre+beh)/2;

		if(nums[pre]==nums[mid] && nums[mid]==nums[beh])
			return min_circ(nums, pre, beh);

		if(nums[mid]>=nums[pre])
			pre=mid;
		else 
			beh=mid;
	}
	return nums[beh];
}

void print_nums(int data[], int start, int end){
	for(int i=start; i<=end; ++i){
		cout << data[i] << " ";
	}
	cout << endl;
}

int main(){
	int* nums=new int[50];
	int length= 0;
	cout << "enter the number of nums: "<<endl;
	cin >> length;
	cout << "enter nums: "<< endl;
	for(int i=0; i<length; ++i){
		cin >> nums[i];
	}
	print_nums(nums, 0, length-1);
	try{
		cout << "min is :" << min(nums, length)<< endl;
	}
	catch(const char* msg){
		cerr << msg << endl;
	}


	delete [] nums;
	return 0;
}