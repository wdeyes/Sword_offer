#include <iostream>
#include <list>
#include "Tree.h"
using namespace std;


bool FindPath(const TreeNode* pRoot, const TreeNode* pNode1, list<const TreeNode*> &MyList){
	if(pRoot==nullptr)
		return false;

	if(pRoot == pNode1)
		return true;

	MyList.push_back(pRoot);

	vector<TreeNode*>::const_iterator it;
	bool ret=false;
	for(it=pRoot->m_vChild.begin(); it!=pRoot->m_vChild.end(); ++it){
		ret = FindPath(*it, pNode1, MyList);
		if(ret)
			break;
	}
	if(!ret)
		MyList.pop_back();
	return ret;
}



const TreeNode* FindLastCommonNode(list<const TreeNode*> &MyList1, list<const TreeNode*> &MyList2){
	list<const TreeNode*>::const_iterator it1=MyList1.begin();
	list<const TreeNode*>::const_iterator it2=MyList2.begin();
	const TreeNode* ret=nullptr;
	while(*it1==*it2 && it1!=MyList1.end() && it1!=MyList2.end() ){
		ret=*it1;
		++it1;
		++it2;
	}
	//cout << ret->m_nValue << endl;
	return ret;
}


const TreeNode* GetLastCommonParent(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2){
	if(pRoot==nullptr || pNode1==nullptr || pNode2==nullptr)
		return nullptr;

	list<const TreeNode*> MyList1, MyList2;
	bool HasNode = FindPath(pRoot, pNode1, MyList1) && FindPath(pRoot, pNode2, MyList2);
	const TreeNode* ret=nullptr;
	if(HasNode)
		ret=FindLastCommonNode(MyList1, MyList2);

	return ret;
}




// ====================测试代码====================
void Test(const char* testName, const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2, TreeNode* pExpected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    const TreeNode* pResult = GetLastCommonParent(pRoot, pNode1, pNode2);

    if((pExpected == nullptr && pResult == nullptr) || 
        (pExpected != nullptr && pResult != nullptr && pResult->m_nValue == pExpected->m_nValue))
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void Test1()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode10 = CreateTreeNode(10);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode1, pNode3);

    ConnectTreeNodes(pNode2, pNode4);
    ConnectTreeNodes(pNode2, pNode5);

    ConnectTreeNodes(pNode4, pNode6);
    ConnectTreeNodes(pNode4, pNode7);

    ConnectTreeNodes(pNode5, pNode8);
    ConnectTreeNodes(pNode5, pNode9);
    ConnectTreeNodes(pNode5, pNode10);

    Test("Test1", pNode1, pNode6, pNode8, pNode2);
}

// 树退化成一个链表
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    Test("Test2", pNode1, pNode5, pNode4, pNode3);
}

// 树退化成一个链表，一个结点不在树中
//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test3()
{
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode5 = CreateTreeNode(5);

    ConnectTreeNodes(pNode1, pNode2);
    ConnectTreeNodes(pNode2, pNode3);
    ConnectTreeNodes(pNode3, pNode4);
    ConnectTreeNodes(pNode4, pNode5);

    TreeNode* pNode6 = CreateTreeNode(6);

    Test("Test3", pNode1, pNode5, pNode6, nullptr);
}

// 输入nullptr
void Test4()
{
    Test("Test4", nullptr, nullptr, nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

 //    TreeNode* pNode1 = CreateTreeNode(1);
 //    TreeNode* pNode2 = CreateTreeNode(2);
 //    TreeNode* pNode3 = CreateTreeNode(3);
 //    TreeNode* pNode4 = CreateTreeNode(4);
 //    TreeNode* pNode5 = CreateTreeNode(5);
 //    TreeNode* pNode6 = CreateTreeNode(6);
 //    TreeNode* pNode7 = CreateTreeNode(7);
 //    TreeNode* pNode8 = CreateTreeNode(8);
 //    TreeNode* pNode9 = CreateTreeNode(9);
 //    TreeNode* pNode10 = CreateTreeNode(10);

 //    ConnectTreeNodes(pNode1, pNode2);
 //    ConnectTreeNodes(pNode1, pNode3);

 //    ConnectTreeNodes(pNode2, pNode4);
 //    ConnectTreeNodes(pNode2, pNode5);

 //    ConnectTreeNodes(pNode4, pNode6);
 //    ConnectTreeNodes(pNode4, pNode7);

 //    ConnectTreeNodes(pNode5, pNode8);
 //    ConnectTreeNodes(pNode5, pNode9);
 //    ConnectTreeNodes(pNode5, pNode10);


 //    list<TreeNode*> MyList;
 //    if(FindPath(pNode1, pNode8, MyList)){
	//     list<TreeNode*>::iterator it;
	//     for(it=MyList.begin(); it!=MyList.end(); ++it)
	//     	cout << (*it)->m_nValue << " ";
	//     cout << endl;
	// }
	// else
	// 	cout << "No path." << endl;

 //    return 0;
}
