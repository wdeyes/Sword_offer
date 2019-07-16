#include<iostream>
#include<limits>
using namespace std;

class CharStatistics{
public:
	CharStatistics():index(0){
		fill(times, times+256, -1);
	}
	void Insert(char ch){
		if(times[ch]==-1)
			times[ch]=index;
		else if(times[ch]>=0)
			times[ch]=-2;

		++index;
	}
	char FirstAppearingOnce(){
		int min_index=numeric_limits<int>::max();
		char ret;
		for(int i=0; i<256; ++i){
			if(times[i]>=0 && times[i]<min_index){
				min_index=times[i];
				ret = i;
			}
		}
		return ret;
	}

private:
	int times[256];
	int index;// it is order.
};



// ====================测试代码====================
void Test(const char* testName, CharStatistics chars, char expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(chars.FirstAppearingOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    CharStatistics chars;

    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

    return 0;
}
