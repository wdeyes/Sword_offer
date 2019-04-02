#include<iostream>
#include"BinaryTree.h"
using namespace std;

BinaryTreeNode* core(int* preorder_s, int* preorder_e, int* inorder_s, int* inorder_e){
	BinaryTreeNode* root = CreateBinaryTreeNode(*preorder_s);
	int* p_root = inorder_s;
	
	if(preorder_s==preorder_e){
		if(inorder_s==inorder_e && *preorder_s==*inorder_s){
			return root;
		}
		else{
			cout << "ERROR" << endl;
			return nullptr;
		}
	}
	while(p_root<=inorder_e && *p_root!=*preorder_s)
		p_root++;

	if(p_root==inorder_e && *inorder_e!=*preorder_s){
		cout << "ERROR" << endl;
		return nullptr;
	}
	int leftlength=p_root-inorder_s;
	if(leftlength>0){
		root->m_pLeft=core(preorder_s+1, preorder_s+leftlength, inorder_s, p_root-1);
	}
	int rightlength=inorder_e-p_root;
	if(rightlength>0){
		root->m_pRight=core(preorder_s+leftlength+1, preorder_e, p_root+1, inorder_e);
	}
	return root;		
}

BinaryTreeNode* solve(int* preorder, int* inorder, int length){
	if(preorder==nullptr || inorder==nullptr || length<=0)
		return nullptr;
	
	return core(preorder, preorder+length-1, inorder, inorder+length-1); 
}

int main(int argc, char* argv[]){
	const int length = 8;
	int preorder[length]={1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

	cout << "preorder: " << endl;
	for(int i=0; i<length; ++i)
		cout << preorder[i] << " " ;
	cout << endl;
	for(int i=0; i<length; ++i)
		cout << inorder[i] << " ";
	cout << endl;

	BinaryTreeNode* root = solve(preorder, inorder, length);
	cout << "******* print answer ******" << endl;
	PrintTree(root);
	DestroyTree(root);
	return 0;
}
