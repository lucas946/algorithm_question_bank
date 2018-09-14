/*
* 给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点
*/

void DeleteNode(ListNode **head, ListNode *pToBeDeleted) {
    if(!head || !pToBeDeleted) return;
    if(pToBeDeleted->next != nullptr) { //链表有多个节点，被删除的节点是中间节点
        ListNode* node = pToBeDeleted->next;
        pToBeDeleted->data = node->data;
        pToBeDeleted->next = node->next;
        delete node;
        node->next = nullptr;
    } else if(pToBeDeleted == *head) { //链表只有一个节点
        *head = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    } else { //链表有多个节点，被删除的节点是尾节点
        ListNode* node = *head;
        while(node->next != pToBeDeleted) 
            node = node->next;
        node->next = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}