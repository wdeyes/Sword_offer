#include<iostream>
#include <unordered_map>
#include"ComplexList.h"
using namespace std;

// //Solve 1: Use hash. 没问题，可以通过
// ComplexListNode* Clone(ComplexListNode* pHead){
// 	if(pHead==nullptr)
// 		return nullptr;
// 	unordered_map<ComplexListNode*, ComplexListNode*> mHash;
// 	ComplexListNode* pNode=pHead;
// 	ComplexListNode* pNewHead=CreateNode(pNode->m_nValue);
// 	mHash[pHead]=pNewHead;
// 	ComplexListNode* pPre=pNewHead;
// 	pNode=pNode->m_pNext;
// 	while(pNode!=nullptr){
// 		ComplexListNode* pNew=CreateNode(pNode->m_nValue);
// 		mHash[pNode]=pNew;
// 		pPre->m_pNext=pNew;
// 		pPre=pNew;
// 		pNode=pNode->m_pNext;
// 	}
// 	pNode=pHead;
// 	while(pNode!=nullptr){
// 		if(pNode->m_pSibling!=nullptr){
// 			mHash[pNode]->m_pSibling=mHash[pNode->m_pSibling];
// 		}
// 		pNode=pNode->m_pNext;
// 	}
// 	return pNewHead;
// }


//Solve 2: 
void DoubleList(ComplexListNode* pHead){
	ComplexListNode* pNode=pHead;
	while(pNode!=nullptr){
		ComplexListNode* pCopy=CreateNode(pNode->m_nValue);
		pCopy->m_pNext=pNode->m_pNext;
		pNode->m_pNext=pCopy;
		pNode=pCopy->m_pNext;
	}
}

void ConectSibling(ComplexListNode* pHead){
	ComplexListNode* pNode=pHead;
	while(pNode!=nullptr){
		if(pNode->m_pSibling!=nullptr){
			pNode->m_pNext->m_pSibling=pNode->m_pSibling->m_pNext;
		}
		pNode=pNode->m_pNext->m_pNext;
	}
}

ComplexListNode* Separate(ComplexListNode* pHead){
	if(pHead==nullptr)
		return nullptr;

	ComplexListNode* pOldHead=pHead;
	ComplexListNode* pNewHead=pHead->m_pNext;
	
	ComplexListNode* pOdd=pOldHead;
	ComplexListNode* pEven=pNewHead;
	ComplexListNode* pNode=pEven->m_pNext;
	while(pNode!=nullptr){
		pOdd->m_pNext=pNode;
		pOdd=pNode;
		pNode=pNode->m_pNext;
		if(pNode!=nullptr){
			pEven->m_pNext=pNode;
			pEven=pNode;
			pNode=pNode->m_pNext;
		}
	}
	return pNewHead;
}

ComplexListNode* Clone(ComplexListNode* pHead){
	DoubleList(pHead);
	ConectSibling(pHead);
	return Separate(pHead);
}








// ====================测试代码====================
void Test(const char* testName, ComplexListNode* pHead)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode* pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
    ComplexListNode* pNode1 = CreateNode(1);
    BuildNodes(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

