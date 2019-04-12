#include<iostream>
#include<stack>
#include<exception>
using namespace std;

template <typename T> class CQueue
{
	public:
		CQueue(void);
		~CQueue(void);

		void appendTail(const T& node);
		T deleteHead();
	private:	
		stack<T> stack1;
		stack<T> stack2;
};

template<typename T> CQueue<T>::CQueue(void){}
template<typename T> CQueue<T>::~CQueue(void){}

template<typename T> void CQueue<T>::appendTail(const T& element){
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead(){
	if(stack1.empty() && stack2.empty())
		throw "Queue is empty!!!" ;
	T ret;
	if(stack2.empty()){
		while(!stack1.empty()){
			T temp=stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
		ret = stack2.top();
		stack2.pop();
	}
	else{
		ret = stack2.top();
		stack2.pop();
	}
	return ret;
}

int main(){
	CQueue<char> my_queue;
	try{
		my_queue.appendTail('a');
		my_queue.appendTail('b');
		my_queue.appendTail('c');
		cout << my_queue.deleteHead() << endl;
		my_queue.appendTail('d');
		cout << my_queue.deleteHead() << endl;
		cout << my_queue.deleteHead() << endl;
		cout << my_queue.deleteHead() << endl;
		cout << my_queue.deleteHead() << endl;
	}
	catch(const char* msg){
		cerr << msg << endl;
	}
	return 0;
}
