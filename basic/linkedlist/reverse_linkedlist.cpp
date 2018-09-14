/*
* 反转链表
*/

ListNode* reverse_linkedlist(ListNode* root) {
    ListNode* prev = root;
    ListNode* cur = root->next;
    ListNode* temp;
    while(cur) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    root->next = nullptr;
    return prev;
}