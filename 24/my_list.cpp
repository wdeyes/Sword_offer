#include<iostream>
#include"my_list.h"
#include<stack>
using namespace std;
//创建
ListNode* CreateListNode(int value){
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
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext){
	if(pCurrent==nullptr){
		cout << "error" << endl;
		exit(1);
	}
	pCurrent->m_pNext = pNext;
}

//打印一个节点
void PrintListNode(ListNode* pNode){
	cout << pNode->m_nValue << endl;
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





















