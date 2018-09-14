/*
* 树的三种非递归遍历：前序、中序、后序
*/
void non_recursion_pre_traverse(TreeNode *root) {
    if(node == nullptr)
        return;
    TreeNode* p = root;
    stack<TreeNode*> stk;
    while(p != nullptr || !stk.empty()) {
        while(p != nullptr) {
            cout<<p->data<<endl;
            stk.push(p);
            p = p->lchild;
        }
        if(!stk.empty()) {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
}

void non_recursion_in_traverse(TreeNode* root) {
    if(root == nullptr)
        return;
    TreeNode* p = root;
    stack<TreeNode*> stk;
    while( p != nullptr || !stk.empty()) {
        while(p != nullptr) {
            stk.push(p);
            p = p->lchild;
        }
        if(!stk.empty()) {
            p = stk.top();
            stk.pop();
            cout<<p->data<<endl;
            p = p->rchild;
        }
    }
}

void non_recursion_post_traverse(TreeNode* root) {
    if(root == nullptr)
        return;
    TreeNode* p = root;
    pair<TreeNode*, bool> temp;
    stack<pair<TreeNode*, bool> > stk;
    while(p != nullptr || !stk.empty()) {
        while(p != nullptr) {
            temp = make_pair(p, true);
            stk.push(temp);
            p = p->lchild;
        }
        if(!stk.empty()) {
            if(stk.top().second == true) {
                stk.top().second = false;
                p = stk.top().first->rchild;
            } else {
                cout<<stk.top().first->data<<endl;
                stk.pop();
            }
        }
    }
}