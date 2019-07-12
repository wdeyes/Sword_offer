#include <iostream>
#include<string>
#include<unordered_set>
using namespace std;

//Solution1: Use set.
int longestSubstringWithoutDuplication_1(const string& str){
	int nLength=str.size();
	int max=0;
	unordered_set<char> hash;
	for(int i=0; i<nLength; ++i){
		if(nLength-i < max)
			break;

		int max_temp=0, index=i;
		while(index<nLength && hash.find(str[index])==hash.end() ){
			++max_temp;
			hash.insert(str[index]);
			++index;
		}
		if(max_temp>max)
			max=max_temp;
		hash.clear();
	}
	//cout << max << endl;
	return max;
}

//Solution2: Use dynamic planning.  
int longestSubstringWithoutDuplication_2(const string& str){
	int max=0;
	int length=0;
	int* position = new int[26];
	for(int i=0; i<26; ++i)
		position[i]=-1;

	for(int i=0; i<str.size(); ++i){
		int preIndex=position[str[i]-'a'];
		if(preIndex<0 || i - preIndex>length ){
			++length;
		}
		else{
			if(length>max)
				max=length;
			length=i- preIndex;
		}
		position[str[i]-'a'] = i;
	}
	if(length>max)
		max = length;
	delete[] position;
	return max;
}


// ====================测试代码====================
void testSolution1(const std::string& input, int expected)
{
    int output = longestSubstringWithoutDuplication_1(input);
    if(output == expected)
        std::cout << "Solution 1 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 1 FAILED, with input: " << input << std::endl;
}

void testSolution2(const std::string& input, int expected)
{
    int output = longestSubstringWithoutDuplication_2(input);
    if(output == expected)
        std::cout << "Solution 2 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 2 FAILED, with input: " << input << std::endl;
}

void test(const std::string& input, int expected)
{
    testSolution1(input, expected);
    testSolution2(input, expected);
}

void test1()
{
    const std::string input = "abcacfrar";
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const std::string input = "acfrarabc";
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const std::string input = "arabcacfr";
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const std::string input = "aaaa";
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const std::string input = "abcdefg";
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const std::string input = "aaabbbccc";
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const std::string input = "abcdcba";
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const std::string input = "abcdaef";
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const std::string input = "a";
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const std::string input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}