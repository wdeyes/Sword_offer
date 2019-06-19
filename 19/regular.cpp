#include<iostream>
using namespace std;


bool match_core(const char* str, const char* pattern){
	if(*pattern=='\0' && *str=='\0')
		return true;

	//此处的判断是为了避免下一个if里面 pattern+1 越界
	if(*pattern=='\0' && *str!='\0')
		return false;

	if(*(pattern+1) == '*'){
		if(*pattern==*str || (*pattern=='.' && *str!='\0') ){
			return match_core(str+1, pattern+2) || 
					match_core(str, pattern+2) || 
					match_core(str+1, pattern);
		}
		else{
			return match_core(str, pattern+2);
		}
	}
	else if(*pattern==*str || (*pattern=='.' && *str!='\0') ){
		return match_core(str+1, pattern+1);
	}

	return false;
}


bool match(const char* str, const char* pattern){
	if(str==nullptr || pattern==nullptr)
		return false;

	return match_core(str, pattern);
}


// int main(int argc, char const *argv[])
// {
// 	char* str = new char[10];
// 	char* pattern = new char[10];
// 	cout << "enter str and pattern: "<< endl;
// 	cin >> str >> pattern;
// 	cout << str << "\t and \t" << pattern << endl;
// 	if(match(str, pattern))
// 		cout << "is match" << endl;
// 	else
// 		cout << "is not match " << endl;
// 	delete[] str;
// 	delete[] pattern;
// 	return 0;
// }


void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(match(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);
    Test("Test05", "a", ".*", true);
    Test("Test06", "a", "a.", false);
    Test("Test07", "a", "", false);
    Test("Test08", "a", ".", true);
    Test("Test09", "a", "ab*", true);
    Test("Test10", "a", "ab*a", false);
    Test("Test11", "aa", "aa", true);
    Test("Test12", "aa", "a*", true);
    Test("Test13", "aa", ".*", true);
    Test("Test14", "aa", ".", false);
    Test("Test15", "ab", ".*", true);
    Test("Test16", "ab", ".*", true);
    Test("Test17", "aaa", "aa*", true);
    Test("Test18", "aaa", "aa.a", false);
    Test("Test19", "aaa", "a.a", true);
    Test("Test20", "aaa", ".a", false);
    Test("Test21", "aaa", "a*a", true);
    Test("Test22", "aaa", "ab*a", false);
    Test("Test23", "aaa", "ab*ac*a", true);
    Test("Test24", "aaa", "ab*a*c*a", true);
    Test("Test25", "aaa", ".*", true);
    Test("Test26", "aab", "c*a*b", true);
    Test("Test27", "aaca", "ab*a*c*a", true);
    Test("Test28", "aaba", "ab*a*c*a", false);
    Test("Test29", "bbbba", ".*a*a", true);
    Test("Test30", "bcbbabab", ".*a*a", false);

    return 0;
}
















