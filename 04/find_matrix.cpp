#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<vector<int> >  matrix, int target){
	int cows=matrix.size();
	if(cows==0) return false;

	int cols=matrix[0].size();
	if(cols==0) return false;

	int i=cows-1;
	int j=0;
	while(i>=0 && j<cols){
		if(matrix[i][j]==target)
			return true;
		else if(matrix[i][j]>target){
			--i;
		}
		else{
			++j;
		}
	}
	return false;
}

int main(){
	int cows=4;
	int cols=4;
	int a[4][4]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
	vector<vector<int> > matrix(cows, vector<int>(cols));
	for(int i=0; i<cows; ++i){
		for(int j=0; j<cols; ++j){
			matrix[i][j]=a[i][j];
			//matrix[i].push_back(a[i][j]);
			cout << matrix[i][j] << " ";	
		}
		cout << endl;
	}

	int target;
	cout << "enter target: " << endl;
	cin >> target;
	if(	solve(matrix, target))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}
