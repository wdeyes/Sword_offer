#include<iostream>
#include<unordered_map>
#include"my_list.h"
using namespace std;

//Determine if there is loop.
ListNode* MeetingNode(ListNode* pHead){
	if(pHead==nullptr)
		return nullptr;

	ListNode* pFast=pHead;
	ListNode* pSlow=pHead;
	while(pFast->m_pNext != nullptr){
		pFast=pFast->m_pNext;
		if(pFast->m_pNext==nullptr)
			return nullptr;
		pFast=pFast->m_pNext;
		pSlow=pSlow->m_pNext;
		if(pFast==pSlow)
			return pFast;
	}
	return nullptr;
}

// Solve 1  Time:n
// 1.Determine if there is loop; 2.Calculate the length of loop. 3.Find the entrance of loop.

// ListNode* EntryNodeOfLoop(ListNode* pHead){
// 	ListNode* inLoop=MeetingNode(pHead);
// 	if(inLoop==nullptr)
// 		return nullptr;

// 	int count=1;
// 	ListNode* circLoop=inLoop->m_pNext;
// 	while(circLoop!=inLoop){
// 		++count;
// 		circLoop=circLoop->m_pNext;
// 	}
// 	ListNode* fast=pHead;
// 	ListNode* slow=pHead;
// 	for (int i = 0; i < count; ++i)
// 	{
// 		fast=fast->m_pNext;
// 	}
// 	while(fast!=slow){
// 		fast=fast->m_pNext;
// 		slow=slow->m_pNext;
// 	}
// 	return fast;
// }

// Solve 2
// hash.  Time:n*logn

ListNode* EntryNodeOfLoop(ListNode* pHead){
	ListNode* inLoop=MeetingNode(pHead);
	if(inLoop==nullptr)
		return nullptr;

	ListNode* ret=pHead;
	unordered_map<ListNode*, int> my_hash;
	while(my_hash.find(ret) == my_hash.end()){
		my_hash[ret]=1;
		ret=ret->m_pNext;
	}
	return ret;
}




// ==================== Test Code ====================
void Test(const char* testName, ListNode* pHead, ListNode* entryNode)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);

    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop 
void Test6()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
