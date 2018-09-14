/*
* 求二叉树的深度
*/
int depthOfTree(TreeNode* root) {
    if(root == nullptr) 
        return 0;
    int left = depthOfTree(root->lchild);
    int right = depthOfTree(root->rchild);

    return (left>right)?(left+1):(right+1);
}