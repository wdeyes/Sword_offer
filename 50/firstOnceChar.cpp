#include<iostream>
#include<exception>
using namespace std;

char FirstNotRepeatingChar(const char* pSring){
    if(pSring==nullptr)
        return '\0';

	int* times = new int[26];
    memset(times, 0, sizeof(int)*26);
	int nLength = strlen(pSring);
    int ans=-1;
	for(int i=0; i<nLength; ++i){
        int position=pSring[i]-'a';
        times[position]+=1;
	}
    for(int i=0; i<nLength; ++i){
        int position=pSring[i]-'a';
        if(times[position]==1){
            ans=position;
            break;
        }
    }
    char ret='\0';
    if(ans>=0) 
        ret='a'+ans;
	delete[] times;
    return ret;
}



// ====================测试代码====================
void Test(const char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    Test(nullptr, '\0');

    return 0;
}