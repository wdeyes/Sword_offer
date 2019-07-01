#pragma once

#include<iostream>
#include<stack>
#include<cstddef>
#include<assert.h>
using namespace std;

template <typename T> class StackWithMin
{
public:
	StackWithMin(){}
	virtual ~StackWithMin(){}

	const T& top() const;
	void push(const T& value);
	void pop();
	const T& min() const;

	bool empty() const;
	size_t size() const;

private:
	stack<T> m_data;
	stack<T> m_min;
};

//1
template <typename T> const T& StackWithMin<T>::top() const {
	return m_data.top();
}

//2
template <typename T> void StackWithMin<T>::push(const T& value){
	if(m_data.empty() || value<m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());

	m_data.push(value);
}

//3
template <typename T> void StackWithMin<T>::pop(){
	assert(!m_data.empty() && !m_min.empty());

	m_data.pop();
	m_min.pop();
}

//4
template <typename T> const T& StackWithMin<T>::min() const {
	assert(!m_data.empty() && !m_min.empty());
	return m_min.top();
}

//5
template <typename T> bool StackWithMin<T>::empty() const {
	return m_data.empty();
} 

//6
template <typename T> size_t StackWithMin<T>::size() const {
	return m_data.size();
}










