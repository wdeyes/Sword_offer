struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* CreateListNode(int value);
void DestroyList(ListNode* pHead);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);