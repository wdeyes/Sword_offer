#include<iostream>
#include"my_list.h"
using namespace std;
 
void delete_duplicated(ListNode** pHead){
	if(pHead==nullptr || *pHead==nullptr)
		return;

	ListNode* pPreNode=nullptr;
	ListNode* pNode = *pHead;

	while(pNode != nullptr){
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;

		if(pNext!=nullptr && pNode->m_nValue == pNext->m_nValue)
			needDelete=true;

		if(!needDelete){
			pPreNode=pNode;
			pNode=pNode->m_pNext;
		}
		else{
			int DupValue = pNode->m_nValue;
			// ListNode* pToDelete = pNode;
			// while(pToDelete!=nullptr && pToDelete->m_nValue == DupValue){
			// 	pNext=pToDelete->m_pNext;
			// 	delete pToDelete;
			// 	pToDelete=pNext;
			// }
			while(pNode!=nullptr && pNode->m_nValue == DupValue){
				pNext=pNode->m_pNext;
				delete pNode;
				pNode=pNext;
			}
			if(pPreNode==nullptr)
				*pHead=pNext;
			else
				pPreNode->m_pNext = pNext;
			pNode=pNext;
		}
	}
}

int main(int argc, char const *argv[])
{
	ListNode* p1 = CreatListNode(1);
	ListNode** pHead = & p1;
	AddToTail(pHead, 1);
	AddToTail(pHead, 5);
	AddToTail(pHead, 4);
	AddToTail(pHead, 3);
	AddToTail(pHead, 3);
	AddToTail(pHead, 2);
	AddToTail(pHead, 1);

	PrintList(p1);
	delete_duplicated(pHead);
	PrintList(p1);


	return 0;
}
















