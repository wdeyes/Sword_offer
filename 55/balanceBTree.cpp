#include<iostream>
#include"BinaryTree.h"
#include <cmath>
using namespace std;


// Solution1: Use two recursions.
int deep(const BinaryTreeNode* pNode){
	if(pNode==nullptr)
		return 0;
	int left = deep(pNode->m_pLeft);
	int right = deep(pNode->m_pRight);
	int ret = 1+ (left>right?left:right);
	return ret;
}

bool IsBalanced_Solution1(const BinaryTreeNode* pRoot){
	if(pRoot==nullptr)
		return true;
	int left = deep(pRoot->m_pLeft);
	int right = deep(pRoot->m_pRight);
	bool cur = true;
	if( abs(left-right)>1 )
		cur = false;

	return ( cur && IsBalanced_Solution1(pRoot->m_pLeft) && IsBalanced_Solution1(pRoot->m_pRight) );
}


// Solution2: Use one recursions. 
// 本质上是把方法1的两个递归合并，边计算深度边维护一个 ans 量，一旦遇到不符合的情况就将它置为false。
// 本方法是传递深度int，因为每次用到，书上是传递ans（bool量），不是每次用到，所以比书上方法好些。
int core(const BinaryTreeNode* pNode, bool &ans){
	if(pNode==nullptr)
		return 0;
	int left = core(pNode->m_pLeft, ans);
	int right = core(pNode->m_pRight, ans);
	if(abs(left-right)>1)
		ans = false;
	return 1+ (left>right?left:right);
}

bool IsBalanced_Solution2(const BinaryTreeNode* pRoot){
	bool ans=true;
	int deep = core(pRoot, ans);
	return ans;
}



// ====================测试代码====================
void Test(const char* testName, const BinaryTreeNode* pRoot, bool expected)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("Solution1 begins: ");
    if(IsBalanced_Solution1(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Solution2 begins: ");
    if(IsBalanced_Solution2(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 完全二叉树
//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
void Test1()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, pNode6, pNode7);

    Test("Test1", pNode1, true);

    DestroyTree(pNode1);
}

// 不是完全二叉树，但是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test2()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode3, nullptr, pNode6);
    ConnectTreeNodes(pNode5, pNode7, nullptr);

    Test("Test2", pNode1, true);

    DestroyTree(pNode1);
}

// 不是平衡二叉树
//             1
//         /      \
//        2        3
//       /\
//      4  5        
//        /
//       6
void Test3()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);

    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode5, pNode6, nullptr);

    Test("Test3", pNode1, false);

    DestroyTree(pNode1);
}


//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode5, nullptr);

    Test("Test4", pNode1, false);

    DestroyTree(pNode1);
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
void Test5()
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

    Test("Test5", pNode1, false);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test6()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test6", pNode1, true);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test7()
{
    Test("Test7", nullptr, true);
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
