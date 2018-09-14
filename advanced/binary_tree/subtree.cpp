/*
* 输入两颗二叉树A和B，判断B是不是A的子结构
* 方法步骤：
* 1. 在树A中找到和树B的根节点的值一样的节点R；
* 2. 判断树A中以R为根节点的子树是不是包含和树B一样的结构
*/
bool hasSubTree(TreeNode* root1, TreeNode* root2) {
    bool result = false;
    if(root1 != nullptr && root2 != nullptr) {
        if(equal(root1->data == root2->data))
            result = doseTree1HaveTree2(root1, root2);
        if(!result)
            hasSubTree(root1->lchild, root2);
        if(!result)
            hasSubTree(root1->rchild, root2);
    }
    return result;
}

bool doseTree1HaveTree2(TreeNode* root1, TreeNode* root2) {
    if(!root1)
        return false;
    if(!root2)
        return false;
    if(!equal(root1->data, root2->data))
        return false;
    return doseTree1HaveTree2(root1->lchild, root2->lchild) &&
        doseTree1HaveTree2(root1->rchild, root2->rchild); 
}