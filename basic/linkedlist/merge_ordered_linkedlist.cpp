/*
* 合并两个有序链表
*/
ListNode* merge(ListNode* root1, ListNode* root2) {
    if(!root1 || !root2) return nullptr;
    ListNode* mergeList = nullptr;
    ListNode* p1 = root1;
    ListNode* p2 = root2;
    if(p1->data < p2->data) {
        mergeList = p1;
        mergeList->next = merge(p1->next, p2);
    } else {
        mergeList = p2;
        mergeList->next = merge(p1, p2->next);
    }
    return mergeLis;
}