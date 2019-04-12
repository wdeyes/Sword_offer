#include<iostream>
using namespace std;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

BinaryTreeNode* CreatBinaryTreeNode(int value){
	BinaryTreeNode* pNode=new BinaryTreeNode();
	pNode->m_nValue=value;
	pNode->m_pRight= nullptr;
	pNode->m_pLeft=nullptr;
	pNode->m_pParent=nullptr;
	return pNode;	
}

void ConnectTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight){
	if(pParent!=nullptr){
		pParent->m_pRight=pRight;
		pParent->m_pLeft=pLeft;
		if(pRight!=nullptr)
			pRight->m_pParent=pParent;
		if(pLeft!=nullptr)
			pLeft->m_pParent=pParent;
	}
}

void PrintTreeNode(BinaryTreeNode* pNode){
	if(pNode!=nullptr){
		cout << "########" << endl << "value: " << pNode->m_nValue << endl;
		if(pNode->m_pLeft!=nullptr)
			cout << "My left:" << pNode->m_pLeft->m_nValue << endl;
		else
			cout << "My lsft is null " << endl;
		if(pNode->m_pRight!=nullptr)
			cout << "My right: " << pNode->m_pRight->m_nValue << endl;
		else 
			cout << "My right is null " << endl;
	}
	else
		cout << "this pNode is null" << endl;
}

void PrintTree(BinaryTreeNode* pRoot){
	PrintTreeNode(pRoot);
	if(pRoot!=nullptr){
		if(pRoot->m_pLeft!=nullptr)
			PrintTree(pRoot->m_pLeft);
		if(pRoot->m_pRight!=nullptr)
			PrintTree(pRoot->m_pRight);
	}
}

void DestroyTree(BinaryTreeNode* pRoot){
	if(pRoot!=nullptr){
		BinaryTreeNode* pLeft=pRoot->m_pLeft;
		BinaryTreeNode* pRight=pRoot->m_pRight;
		delete pRoot;
		pRoot=nullptr;
	    DestroyTree(pLeft);
   		DestroyTree(pRight);		
	}
}

BinaryTreeNode* solve(BinaryTreeNode* pNode){
	if(pNode==nullptr){
		cout << "This is null node" << endl;
		return nullptr;
	}
	BinaryTreeNode* ret=nullptr;
	BinaryTreeNode* pTemp=pNode;
	if(pTemp->m_pRight!=nullptr){
		pTemp=pTemp->m_pRight;
		while(pTemp->m_pLeft!=nullptr)
			pTemp=pTemp->m_pLeft;
		cout << "Next node is: " << pTemp->m_nValue << endl;
		ret= pTemp;
	}
	else if(pTemp->m_pParent!=nullptr){
		while(pTemp->m_pParent!=nullptr && pTemp->m_pParent->m_pLeft!=pTemp)
			pTemp=pTemp->m_pParent;
		if(pTemp->m_pParent==nullptr){
			cout << "Next node is null." << endl;	
		}
		else{
			cout << "Next node is: " << pTemp->m_pParent->m_nValue << endl;
			ret = pTemp->m_pParent;
		}
	}
	return ret;
}

int main(){
	BinaryTreeNode* pNode1 = CreatBinaryTreeNode(1);	
	BinaryTreeNode* pNode2 = CreatBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreatBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreatBinaryTreeNode(4);	
	BinaryTreeNode* pNode5 = CreatBinaryTreeNode(5);	
	BinaryTreeNode* pNode6 = CreatBinaryTreeNode(6);	
	BinaryTreeNode* pNode7 = CreatBinaryTreeNode(7);	
	BinaryTreeNode* pNode8 = CreatBinaryTreeNode(8);	
	BinaryTreeNode* pNode9 = CreatBinaryTreeNode(9);
	ConnectTreeNode(pNode1, pNode2, pNode3);
	ConnectTreeNode(pNode2, pNode4, pNode5);
	ConnectTreeNode(pNode3, pNode6, pNode7);
	ConnectTreeNode(pNode5, pNode8, pNode9);
	PrintTree(pNode1);
	
	cout << endl<<" Ans: "<<endl << "Root node is 4."<< endl;
	BinaryTreeNode* pNode=pNode4;
	while(pNode!=nullptr){
		pNode = solve(pNode);
	}

	pNode=nullptr;
	DestroyTree(pNode1);

	return 0;
}














