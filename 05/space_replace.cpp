#include<iostream>
#include<string>
using namespace std;

void solve(string& target){
	int len = target.size();
	if(len==0) return;
	int p1=len, p2=0;
	for(int i=0; i<len; ++i){
		if(target[i]==' ')
			++p2;
	}
	p2=p1 + 2*p2;
	target.resize(p2);

	while(p2>p1){
		if(target[p1] != ' '){
			target[p2--]=target[p1--];
		}	
		else{
			target[p2--]='%';
			target[p2--]='0';
			target[p2--]='2';
			p1--;
		}
	}
}

int main (){
	string target="we are happy.";
	char c_str[]="we are happy.";
	cout << "string: " << target << endl;
	cout << "size: " <<  target.size() << endl;
	cout << "length: " << target.length() << endl;
	cout << target[13]<< endl;
	cout << c_str[13] << endl;
	cout << target[2] << endl;
	if(c_str[13]=='\0') cout << "=" << endl;
	else cout << "!=" << endl;

	cout << "enter string: " << endl;
	string my_target;
	getline(cin, my_target);
	cout << "my_target:" << my_target << endl;
	solve(my_target);
	cout << my_target << endl;
	cout << my_target.size() << endl;
	return 0;
}
