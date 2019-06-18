struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* CreatListNode(int value);
void DestroyList(ListNode* pHead);
void ConnextListNode(ListNode* pCurrent, ListNode* pNext);
void PrintList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);