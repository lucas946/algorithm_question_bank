/*
* 往链表末尾添加一个节点
* 注意：下面函数中的第一个参数是指向指针的指针。
*/
void AddToTail(ListNode **head, int value) {
    if(head == nullptr) return;
    ListNode* node = new ListNode;
    node->data = value;
    node->next = nullptr;
    if(*head == nullptr) {
        *head = node;
    } else {
        ListNode *p = *head;
        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = node;
    }
}