#include<iostream>
#include<exception>
#include<algorithm>
#include<time.h>
using namespace std;
int Rand_in_range(int start, int end);
void print_nums(int data[], int length, int start);

//自己的
// int partition(int data[], int start, int end, int length){
// 	cout << "******" << endl;///wd
// 	if(data==nullptr || length<=0 || start<0 || end>=length ||start>end)
// 		throw "patition error";

// 	int i=Rand_in_range(start, end);
// 	cout << "rand:" << i << endl;
// 	swap(data[i], data[end]);
// 	int p=start, q=end;
// 	while(p<q){
// 		while(data[p]<data[end] && p<q)
// 			++p;
// 		while(data[q]>=data[end] && p<q)
// 			--q;
// 		if(p<q){
// 			swap(data[p], data[q]);		
// 			++p;
// 		}
// 	}
// 	swap(data[p], data[end]);
// 	print_nums(data, start, end);
// 	return p;
// }



//书上的
int partition(int data[], int start, int end, int length){
	if(data==nullptr || length<=0 || start<0 || end>=length ||start>end)
		throw "patition error";

	int i=Rand_in_range(start, end);
	int small = start-1;
	swap(data[i], data[end]);
	for(int i=start; i<end; ++i){
		if(data[i]<data[end]){
			++small;
			if(data[small]!=data[i])
				swap(data[small], data[i]);
		}
	}
	++small;
	swap(data[small], data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end){
	if(start==end)
		return;
	int index=partition(data, start, end, length);
	if(index>start)
		QuickSort(data, length, start, index-1);
	if(index<end)
		QuickSort(data, length, index+1, end);
}

void print_nums(int data[], int start, int end){
	for(int i=start; i<=end; ++i){
		cout << data[i] << " ";
	}
	cout << endl;
}

int Rand_in_range(int start, int end){
	if(start>end)
		throw "start must be smaller than end";
	srand( (int)time(0) );
	int ret = rand();
	ret=ret%(end-start+1)+start;
	return ret;
}

int main(){
	int* nums=new int[5];
	nums[0]=100;
	nums[1]=3;
	nums[2]=4;
	nums[3]=2;
	nums[4]=5;
	print_nums(nums, 0, 4);
	QuickSort(nums, 5, 0, 4);
	cout << "Ans is :" <<endl;
	print_nums(nums, 0, 4);
	delete[] nums;
	return 0;
}
