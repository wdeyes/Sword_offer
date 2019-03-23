#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

//排序
int solve1(vector<int> nums){
	int ret=-1;
	int l=nums.size();
	sort(nums.begin(), nums.end());
	for(int i=0; i<l; ++i){
		if(nums[i]==nums[i+1]){
			ret = nums[i];
			break;
		}
	}
	return ret;
}
//哈希表
int solve2(vector<int> nums){
	int ret=-1;
	unordered_map<int, int> hash_nums;
	for(int i=0; i<nums.size(); ++i){
		if(hash_nums.find(nums[i])==hash_nums.end())
			hash_nums[nums[i]]=nums[i];
		else{
			ret=nums[i];
			break;
		}
	}	
	return ret;
}
//交换
vector<int> solve3(vector<int> nums){
	//int ret=-1
	vector<int> ret;
	for(int i=0; i<nums.size(); ++i){
		while(i!=nums[i]){
			
			if(nums[i]==nums[nums[i]]){
				//ret=nums[i];			
				ret.push_back(nums[i]);
				break;
			}	
			swap(nums[i], nums[nums[i]]);
		}
		//if(ret!=-1) break;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> nums;
	char usr;
	cout << "enter 'w' to enter nums, others to run." ;
	if(cin>>usr&&usr=='w'){
		cout << "please enter : 'q' to quit;" << endl;
		int num;
		while(cin>>num){
			nums.push_back(num);
		}
	}
	else{
		nums.push_back(2);
		nums.push_back(3);
		nums.push_back(1);
		nums.push_back(0);
		nums.push_back(2);
		nums.push_back(5);
		nums.push_back(3);
	}
	cout << "nums:" ;
		for(int i=0; i<nums.size(); ++i){
			cout << nums[i] << " ";
		}
		cout<< endl <<"length:"<< nums.size();

	cout << endl << "solve1_ans:" << solve1(nums)<<endl;
	cout << "solve2_ans:" << solve2(nums)<<endl;	
	//cout << "solve3_ans:" << solve3(nums) << endl;
	vector<int> ans = solve3(nums);
	cout << "ans:"<<endl;
	for(int i=0; i<ans.size(); ++i){
			cout << ans[i] << " ";
		}
	cout << endl;
	return 0;
}
