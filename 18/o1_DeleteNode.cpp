#include<iostream>
#include"my_list.h"
using namespace std;

void o1_DeleteNode(ListNode** pHead, ListNode* pDelete){
	if(pDelete->m_pNext != nullptr){
		ListNode* pNext = pDelete->m_pNext;
		pDelete->m_nValue = pNext->m_nValue;
		pDelete->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext=nullptr;
	}
	else if(*pHead == pDelete){
		delete pDelete;
		*pHead = nullptr;
		pDelete = nullptr;
	}
	else{
		ListNode* pNode = *pHead;
		while(pNode->m_pNext != pDelete){
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = nullptr;
		delete pDelete;
		pDelete=nullptr;
	}
}


int main(int argc, char const *argv[])
{
	ListNode* p1 = CreatListNode(1);
	ListNode** pHead = & p1;
	ListNode* p2 = CreatListNode(9);
	ConnextListNode(p1, p2);
	AddToTail(pHead, 2);
	AddToTail(pHead, 3);
	AddToTail(pHead, 4);
	AddToTail(pHead, 5);
	
	PrintList(p1);
	o1_DeleteNode(pHead, p2);
	PrintList(p1);


	DestroyList(p1);
	return 0;
}