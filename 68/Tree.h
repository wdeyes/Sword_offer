#pragma once 
#include <vector>
using namespace std;


struct TreeNode
{
	int m_nValue;
	vector<TreeNode*> m_vChild;
};

//creat
TreeNode*  CreateTreeNode(int value);
//connect
void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild);
//destroy Tree
void DestroyTree(TreeNode* pRoot);
