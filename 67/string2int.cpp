#include <iostream>
using namespace std;

enum State {KValid=0, kInvalid};

int g_nStatus=kInvalid;

// 毫无鲁棒性，考虑的太少了
// int StrToInt(const char* string){
// 	if(string == nullptr){
// 		g_nStatus = kInvalid;
// 		return 0;
// 	}
// 	int length = strlen(string);
// 	int ret=0;
// 	int v=1;
// 	for(int i=length-1; i>=0; --i){
// 		int num = string[i]-'0';
// 		ret += num*v;
// 		v *= 10;
// 	}
// 	return ret;
// }


// Solution 2:
long long StrToLonglong(const char* string, bool minus){
	long long  num=0;
	int flag = minus? -1: 1;

	while(*string != '\0'){
		if(*string>='0' && *string<='9'){
			num = num*10 + (*string-'0')*flag; 	
		}
		else{
			num=0;
			break;
		}
		if( (minus && num<(signed int)0x80000000) || (!minus && num>0x7FFFFFFF) ){
			num=0;
			break;
		}
		++string;
	}
	if(*string == '\0')
		g_nStatus = KValid;

	return num;
}

int StrToInt(const char* string){
	g_nStatus=kInvalid;
	if(string==nullptr || *string=='\0'){
		return 0;
	}
	bool minus=false;
	if(*string=='+')
		++string;
	else if(*string=='-'){
		++string;
		minus=true;
	}
	int ret=0;
	if(*string!='\0')
		ret = int( StrToLonglong(string, minus) );

	return ret;
}



// ====================测试代码====================
void Test(const char* string)
{
    int result = StrToInt(string);
    if(result == 0 && g_nStatus == kInvalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char* argv[])
{
    Test(nullptr);

    Test("");

    Test("123");

    Test("+123");
    
    Test("-123");

    Test("1a33");

    Test("+0");

    Test("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");    

    Test("-2147483647");

    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");    

    Test("+2147483649");

    Test("-2147483649");

    Test("+");

    Test("-");

    return 0;
}
