#include <iostream> 
#include <queue>
#include <exception>
using namespace std;

template<typename T> class my_stack
{
public:
	my_stack();
	~my_stack();
	void add(const T& node);
	T pop();
private:
	queue<T> queue1;
	queue<T> queue2;	
};

template<typename T> my_stack<T>::my_stack(void){}
template<typename T> my_stack<T>::~my_stack(void){}

template<typename T> void my_stack<T>::add(const T& node){
	if(!queue1.empty() && queue2.empty())
		queue1.push(node);
	else
		queue2.push(node);
}

template<typename T> T my_stack<T>::pop(){
	if(queue1.empty()&&queue2.empty())
		throw "the stack is empty!!";

	T ret;			
	if(!queue1.empty() && queue2.empty()){
		while(queue1.size()>1){
			T temp=queue1.front();
			queue1.pop();
			queue2.push(temp);
		}
		ret=queue1.front();
		queue1.pop();
	}
	else{
		while(queue2.size()>1){
			T temp=queue2.front();
			queue2.pop();
			queue1.push(temp);
		}	
		ret=queue2.front();
		queue2.pop();
	}
	return ret;
}

int main (){
	my_stack<int> stack_test;
	try{
		stack_test.add(1);
		stack_test.add(2);
		stack_test.add(3);
		cout << "pop a node which is : " << stack_test.pop()<<endl;
		cout << "pop a node which is : " << stack_test.pop() << endl;
		stack_test.add(4);
		cout << "pop a node which is : " << stack_test.pop() << endl;
		cout << "pop a node which is : " << stack_test.pop() << endl;
		cout << "pop a node which is : " << stack_test.pop() << endl;
	}
	catch(const char* msg){
		cerr<< msg << endl;
	}
	return 0;
}
