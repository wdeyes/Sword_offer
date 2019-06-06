#include<iostream>
using namespace std;

bool check(int k, int row, int col){
	int sum=0;
	while(row>0){
		sum+=(row%10);
		row/=10;
	}

	while(col>0){
		sum+=(col%10);
		col/=10;
	}

	if(sum>k)
		return false;
	else 
		return true;
}

int move_core(int m, int n, int row, int col, int k, bool* visited){
	int count=0;

	if(row>=0 && row<m && col>=0 && col<n && check(k, row, col) && !visited[row*n+col]){
		visited[row*n+col] = true;
		count=1+ move_core(m, n, row-1, col, k, visited)+
					move_core(m, n, row+1, col, k, visited)+ 
					move_core(m, n, row, col-1, k, visited)+
					move_core(m, n, row, col+1, k, visited);
	}
	return count;
}


int move(int m, int n, int k){
	int ans=0;
	//边界判断
	if(m<=0 || n<=0 || k<0)
		return ans;

	bool* visited=new bool[m*n];
	memset(visited, false, m*n);


	ans=move_core(m, n, 0, 0, k, visited);

	delete[] visited;
	return ans;
}


int main(){
	int m,n,k;
	cout << "enter m,n,k" << endl;
	while(cin >> m >> n >> k){
		cout << "ans：" << move(m, n, k) << endl;
	}

	return 0;
}










