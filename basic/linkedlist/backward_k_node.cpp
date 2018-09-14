/*
* 输入一个链表，输出该链表倒数第k个节点
*/

ListNode* FindKthToTail(ListNode* root, int k) {
    if(!root || k <= 0) return nullptr;
    ListNode* p1 = root;
    for(int i = 0; i < k-1; ++i) {
        p1 = p1->next;
        if(p1 == nullptr) 
            return nullptr;
    }
    ListNode* p2 = root;
    while(p1->next != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}