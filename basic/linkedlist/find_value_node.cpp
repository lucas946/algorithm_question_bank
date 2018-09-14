/*
* 在链表中寻找特定值的节点并删除
*/
void RemoveNode(ListNode** head, int value) {
    if(!head || !*head) return;
    ListNode* p = nullptr;
    if(*head->data == value) {
        p = *head;
        *head = (*head)->next;
    } else {
        ListNode *tmp = *head;
        while(tmp->next != nullptr && tmp->next->data != value)
            tmp = tmp->next;
        if(tmp->next != nullptr && tmp->next->data == value) {
            p = tmp->next;
            tmp->next = tmp->next->next;
        }
    }
    
    if(p != nullptr) {
        delete p;
        p = nullptr;
    }
}