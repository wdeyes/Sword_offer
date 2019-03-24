#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int solve1(vector<int> nums){
	int ret=-1;
	int len=nums.size();
	if(len<=1) return ret;
	int* temp =new int[len] ();
	for(int i=0; i<len; ++i){
		if(temp[nums[i]]!=0){
			ret = nums[i];
			break;
		}
		else{
			temp[nums[i]]=nums[i];
		}
	}

	delete[] temp;
	return ret;
}

int cal_count(const vector<int>& nums, int start, int end){
	int count=0;
	for(int i=0; i<nums.size(); ++i){
		if(nums[i]<=end && nums[i]>=start)
			++count;
	}
	return count;
}

int solve2(vector<int> nums){
	int ret=-1;
	int len=nums.size();
	if(len<=1) return ret;
	
	int start=1;
	int end=len-1;
	while(start<end){
		int	m=(start+end)/2;
		int count = cal_count(nums, start, m);
		if(start==end){
			if(count>1) return start;
			else break;
		}

		if(count>(m-start+1)){
			end=m;
		}	
		else{
			start=m+1;
		}
	}
	return ret;	
}

int main(){
	vector<int> nums;
	//nums.push_back(2);
	//nums.push_back(3);
	//nums.push_back(5);
	//nums.push_back(4);
	//nums.push_back(3);
	//nums.push_back(2);
	//nums.push_back(6);
	//nums.push_back(7);
	
	cout << "enter number: " << endl;
	int num;
	while(cin >> num){
		nums.push_back(num);
	}

	cout << "nums:" ;
	for(int i=0; i<nums.size(); ++i){
		cout << nums[i] << " ";
	}	
	cout << endl;

	cout << "solve1: " << solve1(nums) << endl;
	cout << "solve2: " << solve2(nums) << endl;	

	return 0;
}
