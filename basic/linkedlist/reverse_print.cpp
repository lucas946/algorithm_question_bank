/* 
* 描述：反转打印链表节点的值
*/

// 非递归打印
void non_recursion_reverse_print(ListNode* root) {
    if(!root) return;
    ListNode* p = root;
    stack<ListNode*> stk;
    while(p) {
        stk.push(p);
        p = p->next;
    }
    while(!stk.empty()) {
        p = stk.top();
        cout<<tmp->data<<endl;
        stk.pop();
    }
}

// 递归打印
void recursion_reverse_print(ListNode* root) {
    if(root != nullptr) {
        if(root->next != nullptr) {
            recursion_reverse_print(root->next);
        }
        cout<<root->data<<endl;
    }
}