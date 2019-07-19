#include <iostream>
#include <queue>
#include <deque>
#include <exception>
using namespace std;


template<typename T> class QueueWithMax
{
public:
	QueueWithMax():curIndex(0){}

	void push_back(T num){
		Data temp;
		temp.value = num;
		temp.index = curIndex++;
		data.push(temp);
		while(!maybe_max.empty() && maybe_max.back().value < num)
			maybe_max.pop_back();
		maybe_max.push_back(temp);
	}

	void pop_front(){
		int WillDelete = data.front().index;
		if(maybe_max.front().index == WillDelete)
			maybe_max.pop_front();
		data.pop();
	}

	T max() const{
		if(maybe_max.empty())
			throw "QueueWithMax is empty.";
		return maybe_max.front().value;
	}

private:
	struct Data
	{
		T value;
		int index;
	};
	queue<Data> data;
	deque<Data> maybe_max;
	int curIndex;
};



// ====================测试代码====================
void Test(const char* testName, const QueueWithMax<int>& queue, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(queue.max() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    QueueWithMax<int> queue;
    // {2}
    queue.push_back(2);
    Test("Test1", queue, 2);

    // {2, 3}
    queue.push_back(3);
    Test("Test2", queue, 3);

    // {2, 3, 4}
    queue.push_back(4);
    Test("Test3", queue, 4);

    // {2, 3, 4, 2}
    queue.push_back(2);
    Test("Test4", queue, 4);

    // {3, 4, 2}
    queue.pop_front();
    Test("Test5", queue, 4);

    // {4, 2}
    queue.pop_front();
    Test("Test6", queue, 4);

    // {2}
    queue.pop_front();
    Test("Test7", queue, 2);

    // {2, 6}
    queue.push_back(6);
    Test("Test8", queue, 6);

    // {2, 6, 2}
    queue.push_back(2);
    Test("Test9", queue, 6);

    // {2, 6, 2, 5}
    queue.push_back(5);
    Test("Test9", queue, 6);

    // {6, 2, 5}
    queue.pop_front();
    Test("Test10", queue, 6);

    // {2, 5}
    queue.pop_front();
    Test("Test11", queue, 5);

    // {5}
    queue.pop_front();
    Test("Test12", queue, 5);

    // {5, 1}
    queue.push_back(1);
    Test("Test13", queue, 5);

    return 0;
}
