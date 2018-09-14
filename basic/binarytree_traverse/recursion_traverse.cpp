/*
* 树的三种递归遍历：前序、中序、后序
*/
void pre_order_traverse(TreeNode* node) {
    if(node == nullptr) return;
    cout<<root->data<<endl;
    pre_order_traverse(node->lchild);
    pre_order_traverse(node->rchild);
}

void in_order_traverse(TreeNode* node) {
    if(node == nullptr) return;
    in_order_traverse(node->lchild);   
    cout<<root->data<<endl;
    in_order_traverse(node->rchild); 
}

void post_order_traverse(TreeNode* node) {
    if(node == nullptr) return;
    post_order_traverse(node->lchild);
    post_order_traverse(node->rchild);
    cout<<node->data<<endl;
}