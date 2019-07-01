#include<iostream>
#include"BinaryTree.h"
#include<queue>
#include<stack>
using namespace std;

//按顺序打印
// void PrintFromTopToBottom(BinaryTreeNode* pRoot){
// 	if(pRoot==nullptr)
// 		return;

// 	queue<BinaryTreeNode*> m_queue;
// 	m_queue.push(pRoot);
// 	while(!m_queue.empty()){
// 		BinaryTreeNode* pNode=m_queue.front();
// 		m_queue.pop();
// 		cout << pNode->m_nValue << " ";
// 		if(pNode->m_pLeft!=nullptr)
// 			m_queue.push(pNode->m_pLeft);
// 		if(pNode->m_pRight!=nullptr)
// 			m_queue.push(pNode->m_pRight);
// 	}
// }

//打印到每一行
// void PrintFromTopToBottom(BinaryTreeNode* pRoot){
// 	if(pRoot==nullptr)
// 		return;
	
// 	int cur=1, next=0;
// 	queue<BinaryTreeNode*> m_queue;
// 	m_queue.push(pRoot);
// 	while(!m_queue.empty()){
// 		if(cur==0){
// 			cout << endl;
// 			cur=next;
// 			next=0;
// 		}
// 		BinaryTreeNode* pNode=m_queue.front();
// 		m_queue.pop();
// 		cout << pNode->m_nValue << " ";
// 		--cur;
// 		if(pNode->m_pLeft!=nullptr){
// 			++next;
// 			m_queue.push(pNode->m_pLeft);
// 		}
// 		if(pNode->m_pRight!=nullptr){
// 			++next;
// 			m_queue.push(pNode->m_pRight);
// 		}
// 	}
// }

//之字行打印
void PrintFromTopToBottom(BinaryTreeNode* pRoot){
	if(pRoot==nullptr)
		return;

	stack<BinaryTreeNode*> odd_stack;
	stack<BinaryTreeNode*> even_stack;
	odd_stack.push(pRoot);
	int cur=1, next=0, swich=1;
	while(!odd_stack.empty() || !even_stack.empty()){
		if(swich==1 && !odd_stack.empty()){
			BinaryTreeNode* pNode=odd_stack.top();
			odd_stack.pop();
			cout << pNode->m_nValue << " ";
			--cur;
			if(pNode->m_pLeft!=nullptr){
				++next;
				even_stack.push(pNode->m_pLeft);
			}
			if(pNode->m_pRight!=nullptr){
				++next;
				even_stack.push(pNode->m_pRight);
			}
		}
		else if(swich==-1 && !even_stack.empty()){
			BinaryTreeNode* pNode=even_stack.top();
			even_stack.pop();
			cout << pNode->m_nValue << " ";
			--cur;
			if(pNode->m_pRight!=nullptr){
				++next;
				odd_stack.push(pNode->m_pRight);
			}
			if(pNode->m_pLeft!=nullptr){
				++next;
				odd_stack.push(pNode->m_pLeft);
			}
		}
		if(cur==0){
			swich*=-1;
			cout << endl;
			cur=next;
			next=0;
		}
	}
}




// ====================测试代码====================
void Test(const char* testName, BinaryTreeNode* pRoot)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    //PrintTree(pRoot);

    printf("The nodes from top to bottom, from left to right are: \n");
    PrintFromTopToBottom(pRoot);

    printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    //BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    //BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    //ConnectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    Test("Test2", pNode5);

    DestroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test3", pNode1);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyTree(pNode1);
}

// 树中没有结点
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
