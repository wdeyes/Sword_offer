#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int>& a1, vector<int>& a2){
	int l1=a1.size(), l2=a2.size();
	int	l=l1+l2;
	a1.resize(l);
	while(l>0){
		if(l1==0)
			for(int i=0;i<l2;++i){
				a1[i]=a2[i];
				l--;
			}
		else if(l2==0)
			{
				l=l-l1;
			}
		else{
			if(a1[l1-1]>a2[l2-1]){
				a1[l-1]=a1[l1-1];
				l1--;
			}
			else{
				a1[l-1]=a2[l2-1];
				l2--;
			}
			l--;
		}
	}
}

int main(){
	vector<int> a1, a2;
	int num1, num2;
	cout << "enter a1, q to quit" << endl;
	while(cin >> num1)
		a1.push_back(num1);
	cin.clear();
	cin.get();
	cout << "enter a2, q to quit" << endl;
	while(cin >> num2)
		a2.push_back(num2);
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	vector<int>::iterator t;
	for(t=a1.begin(); t!=a1.end(); t++){
		cout << *t << " " ;
	}
	cout << endl;
	for(t=a2.begin(); t!=a2.end(); t++){
		cout << *t << " " ;
	}
	cout << endl;
	solve(a1, a2);
	cout << "anser: " << endl;
	for(t=a1.begin(); t!=a1.end(); t++){
		cout << *t << " " ;
	}
	cout << endl;

	return 0;
}
