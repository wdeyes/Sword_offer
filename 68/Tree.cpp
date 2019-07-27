#include <iostream>
#include "Tree.h"
using namespace std;

TreeNode* CreateTreeNode(int value){
	TreeNode* pNode = new TreeNode();
	pNode->m_nValue = value;
	return pNode;
}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pChild){
	if(pParent!=nullptr)
		pParent->m_vChild.push_back(pChild);
}


void DestroyTree(TreeNode* pRoot){
	if(pRoot!=nullptr){
		vector<TreeNode*>::iterator it;
		for(it=pRoot->m_vChild.begin(); it!=pRoot->m_vChild.end(); ++it)
			DestroyTree(*it);
		delete pRoot;
	}
}