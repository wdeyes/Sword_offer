#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void BuildProductionArray(const vector<double> &input, vector<double> &output){
	int length = input.size();
	vector<double> left(length);
	left[0] = 1;
	for(int i=1; i<length; ++i)
		left[i] = left[i-1] * input[i-1];

	vector<double> right(length);
	right[length-1] = 1;
	for(int i=length-2; i>=0; --i)
		right[i]=right[i+1] * input[i+1];

	for(int i=0; i<length; ++i)
		output[i] = left[i] * right[i];
}



//================= Test Code =================
static bool EqualArrays(const vector<double>& input, const vector<double>& output)
{
    int length1 = input.size();
    int length2 = output.size();

    if(length1 != length2)
        return false;

    for(int i = 0; i < length1; ++i)
    {
        if(abs(input[i] - output[i]) > 0.0000001)
            return false;
    }

    return true;
}

static void test(const char* testName, const vector<double>& input, vector<double>& output, const vector<double>& expected)
{
    printf("%s Begins: ", testName);

    BuildProductionArray(input, output);
    if(EqualArrays(output, expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

static void test1()
{
    // 输入数组中没有0
    double input[] = { 1, 2, 3, 4, 5 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 120, 60, 40, 30, 24 };

    vector<double> v_input(input, input + sizeof(input) / sizeof(double));
    vector<double> v_output(output, output + sizeof(output) / sizeof(double));
    vector<double> v_expected(expected, expected + sizeof(expected) / sizeof(double));
    test("Test1", v_input, v_output, v_expected);

    // test("Test1", vector<double>(input, input + sizeof(input) / sizeof(double)),
    //     vector<double>(output, output + sizeof(output) / sizeof(double)),
    //     vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}

static void test2()
{
    // 输入数组中有一个0
    double input[] = { 1, 2, 0, 4, 5 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 0, 0, 40, 0, 0 };

    vector<double> v_input(input, input + sizeof(input) / sizeof(double));
    vector<double> v_output(output, output + sizeof(output) / sizeof(double));
    vector<double> v_expected(expected, expected + sizeof(expected) / sizeof(double));
    test("Test2", v_input, v_output, v_expected);

    // test("Test2", vector<double>(input, input + sizeof(input) / sizeof(double)),
    //     vector<double>(output, output + sizeof(output) / sizeof(double)),
    //     vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}

static void test3()
{
    // 输入数组中有两个0
    double input[] = { 1, 2, 0, 4, 0 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 0, 0, 0, 0, 0 };

    vector<double> v_input(input, input + sizeof(input) / sizeof(double));
    vector<double> v_output(output, output + sizeof(output) / sizeof(double));
    vector<double> v_expected(expected, expected + sizeof(expected) / sizeof(double));
    test("Test1", v_input, v_output, v_expected);

    // test("Test3", vector<double>(input, input + sizeof(input) / sizeof(double)),
    //     vector<double>(output, output + sizeof(output) / sizeof(double)),
    //     vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}

static void test4()
{
    // 输入数组中有正、负数
    double input[] = { 1, -2, 3, -4, 5 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 120, -60, 40, -30, 24 };

    vector<double> v_input(input, input + sizeof(input) / sizeof(double));
    vector<double> v_output(output, output + sizeof(output) / sizeof(double));
    vector<double> v_expected(expected, expected + sizeof(expected) / sizeof(double));
    test("Test1", v_input, v_output, v_expected);

    // test("Test4", vector<double>(input, input + sizeof(input) / sizeof(double)),
    //     vector<double>(output, output + sizeof(output) / sizeof(double)),
    //     vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}

static void test5()
{
    // 输入输入中只有两个数字
    double input[] = { 1, -2 };
    double output[] = { 0, 0 };
    double expected[] = { -2, 1 };

    vector<double> v_input(input, input + sizeof(input) / sizeof(double));
    vector<double> v_output(output, output + sizeof(output) / sizeof(double));
    vector<double> v_expected(expected, expected + sizeof(expected) / sizeof(double));
    test("Test1", v_input, v_output, v_expected);

    // test("Test5", vector<double>(input, input + sizeof(input) / sizeof(double)),
    //     vector<double>(output, output + sizeof(output) / sizeof(double)),
    //     vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}