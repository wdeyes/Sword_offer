#include<iostream>
// #include<set>
// #include<queue>
#include <vector>
using namespace std;
//这个方法失败，找丑数不能按照从小到大
// int GetUglyNumber_Solution1(int index){
// 	if(index==0) return 0;

// 	set<int> hash;//The key is ugly_num. The value is number.
// 	queue<int> wait;
// 	int i=1;
// 	hash.insert(1);
// 	wait.push(1);
// 	int next=0;
// 	while(i<=index*3 ){
// 		next=wait.front()*2;
// 		if(hash.find(next)==hash.end()){
// 			hash.insert(next);
// 			++i;
// 			wait.push(next);
// 		}
// 		next=wait.front()*3;
// 		if(hash.find(next)==hash.end()){
// 			hash.insert(next);
// 			++i;
// 			wait.push(next);
// 		}
// 		next=wait.front()*5;
// 		if(hash.find(next)==hash.end()){
// 			hash.insert(next);
// 			++i;
// 			wait.push(next);
// 		}
// 		wait.pop();
// 	}
// 	set<int>::iterator it = hash.begin();
// 	for(int i=0; i<index-1; ++i){
// 		//cout << *it << " ";
// 		++it;
// 	}
// 	int ret = *it;

// 	cout << ret << endl;
// 	return ret;
// }

//改成如下思路，每次推入一个最小的，而不是推入三个，并且不记录未乘2、3、5的数字，直接在前面的丑数里面找的乘。
int min(int num1, int num2, int num3){
	int ret=num1;
	if(num2<ret)
		ret=num2;
	if(num3<ret)
		ret=num3;

	return ret;
}
int GetUglyNumber_Solution1(int index){
	if(index<=0) return 0;
	vector<int> ans;
	ans.push_back(1);
	int it2=0;
	int it3=0;
	int it5=0;
	int end=0;
	for(int i=1; i<index; ++i){
		while( ans[it2]*2 <= ans[end] ) ++it2;
		int next2=2*ans[it2];
		while( ans[it3]*3 <= ans[end] ) ++it3;
		int next3=3*ans[it3];
		while( ans[it5]*5 <= ans[end] ) ++it5;
		int next5=5*ans[it5];

		int next=min(next2, next3, next5);
		ans.push_back(next);
		++end;
	}

	return ans[end];
}



// ====================测试代码====================
void Test(int index, int expected)
{
    if(GetUglyNumber_Solution1(index) == expected)
        printf("solution1 passed\n");
    else
        printf("solution1 failed\n");

    // if(GetUglyNumber_Solution2(index) == expected)
    //     printf("solution2 passed\n");
    // else
    //     printf("solution2 failed\n");
}

int main(int argc, char* argv[])
{
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}
