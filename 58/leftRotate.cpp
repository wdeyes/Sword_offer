#include <iostream>
using namespace std;

void Reverse(char* start, char* end){
	if(start==nullptr || end == nullptr)
		return;

	while(start<end){
		char temp=*start;
		*start=*end;
		*end=temp;

		++start;
		--end;
	}
}

char* LeftRotateString(char* input, int num){
	if(input==nullptr)
		return nullptr;

	int length = strlen(input);
	if(num>=length || num<=0)
		return input;

	int index = length - num;
	Reverse(input, input+length-1);
	Reverse(input, input+index-1);
	Reverse(input+index, input+length-1);

	return input;
}




// ====================测试代码====================
void Test(const char* testName, char* input, int num, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    char* result = LeftRotateString(input, num);

    if((input == nullptr && expectedResult == nullptr)
        || (input != nullptr && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", nullptr, 6, nullptr);
}

// 鲁棒性测试
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
