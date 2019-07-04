#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

//Solve 1 失败，思路不如书上的，暂时不探究。
// void core(char* str, unordered_set<int> hash){
// 	for(int i=0; str[i]!='\0'; ++i){
// 		if(hash.find(i)==hash.end()){
// 			cout << str[i] << " ";
// 			hash.insert(i);
// 			core(str, hash);
// 		}
// 	}
// 	//hash.clear();
// 	cout << endl;
// }
// void Permutation(char* str){
// 	if(str ==nullptr)
// 		return;
// 	unordered_set<int> hash;
// 	core(str, hash);
// }

//Solve2
// void core(char* str, char* pBegin){
// 	if(*pBegin=='\0')
// 		cout << str << endl;
// 	else{
// 		for(char* i=pBegin; *i!='\0'; ++i){
// 			//swap i and pBegin
// 			char temp= *pBegin;
// 			*pBegin=*i;
// 			*i=temp;

// 			core(str, pBegin+1);
// 			//swap i and pBegin
// 			temp= *pBegin;
// 			*pBegin=*i;
// 			*i=temp;
// 		}
// 	}
// }
// void Permutation(char* str){
// 	if(str==nullptr)
// 		return;
// 	core(str, str);
// }


//本题扩展答案
void core(char* str, int m, vector<char>& ans){
	if(m==0){
		for(vector<char>::iterator it=ans.begin(); it!=ans.end(); ++it)
			cout << *it ;
		cout << endl;
		return;
	}
	if(*str=='\0')
		return;

	ans.push_back(*str);
	core(str+1, m-1, ans);
	ans.pop_back();
	core(str+1, m, ans);
}
void Permutation(char* str){
	if(str==nullptr)
		return;
	int length=strlen(str);
	vector<char> ans;
	for(int i=0; i<=length; ++i){
		core(str, i, ans);
	}
}



// ====================测试代码====================
void Test(char* pStr)
{
    if(pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(nullptr);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);

    return 0;
}

