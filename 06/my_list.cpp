#include<iostream>
#include"my_list.h"
#include<stack>
using namespace std;
//创建
ListNode* CreatListNode(int value){
	ListNode* pNode=new ListNode();
	pNode->m_nValue=value;
	pNode->m_pNext = nullptr;
	return pNode;
}

//释放
void DestroyList(ListNode* pHead){
	ListNode* pNode=pHead;
	while(pNode!=nullptr){
		pNode=pNode->m_pNext;
		delete pHead;
		pHead=pNode;
	}
}

//连接
void ConnextListNode(ListNode* pCurrent, ListNode* pNext){
	if(pCurrent==nullptr){
		cout << "error" << endl;
		exit(1);
	}
	pCurrent->m_pNext = pNext;
}

//打印这个list
void PrintList(ListNode* pHead){
	ListNode* pNode=pHead;
	while(pNode!= nullptr){
		cout << pNode->m_nValue ;
		if(pNode->m_pNext!=nullptr)
			cout << "->" ;
		pNode=pNode->m_pNext;
	}
	cout << endl;
}

//在末尾添加一个
void AddToTail(ListNode** pHead, int value){
	ListNode* pNew = new ListNode();
	pNew->m_nValue=value;
	pNew->m_pNext=nullptr;
	if(*pHead==nullptr){
		*pHead=pNew;
	}
	else{
		ListNode* pNode=*pHead;
		while(pNode->m_pNext!=nullptr)
			pNode=pNode->m_pNext;
		pNode->m_pNext=pNew;
	}
}

//删除一个
void RemoveNode(ListNode** pHead, int value){
	if(*pHead==nullptr||pHead==nullptr)
		return;
	
	ListNode* pToBeDeleted =nullptr;
	if((*pHead)->m_nValue==value){
		pToBeDeleted=*pHead;
		*pHead=(*pHead)->m_pNext;
	}
	else{
		ListNode* pNode=*pHead;
		while(pNode->m_pNext!=nullptr && pNode->m_pNext->m_nValue!=value){
			pNode=pNode->m_pNext;
		}
		if(pNode->m_pNext!=nullptr && pNode->m_pNext->m_nValue==value){
			pToBeDeleted=pNode->m_pNext;
			pNode->m_pNext=pNode->m_pNext->m_pNext;
		}
	}
	if(pToBeDeleted!=nullptr){
		delete pToBeDeleted;
		pToBeDeleted=nullptr;
	}
}

void solve1(ListNode* pHead){
	stack<int> nodes;
	ListNode* pNode=pHead;
	while(pNode!=nullptr){
		nodes.push(pNode->m_nValue);
		pNode=pNode->m_pNext;
	}
	while(!nodes.empty()){
		cout << nodes.top() << " ";
		nodes.pop();
	}
	cout << endl;
}

void solve2(ListNode* pHead){
	if(pHead!=nullptr){
		if(pHead->m_pNext!=nullptr)
			solve2(pHead->m_pNext);
		cout << pHead->m_nValue << " ";
	}
}

int main(){
	ListNode* pNode1=CreatListNode(1);
	ListNode* pNode2=CreatListNode(2);
	ListNode* pNode3=CreatListNode(3);
	ListNode* pNode4=CreatListNode(4);

	ConnextListNode(pNode1, pNode2);
	ConnextListNode(pNode2, pNode3);
	ConnextListNode(pNode3, pNode4);

	PrintList(pNode1);	

	ListNode** pHead = & pNode1;
	RemoveNode(pHead, 3);
	PrintList(pNode1);
	AddToTail(pHead, 5);
	PrintList(pNode1);

	RemoveNode(pHead, 1);//这里把 pNode1 指向了2，因此打印 pNode1 可以，它仍然是头结点。
	PrintList(pNode1);
	PrintList(*pHead);

	cout << "solve1: " << endl;
	solve1(pNode1);
	cout << "solve2: " << endl;
	solve2(pNode1);
	cout << endl;
	DestroyList(pNode1);
	return 0;
}















