/*
* 重建二叉树
* 输入某二叉树的前序遍历的结果和中序遍历的结果，请重建该二叉树。
* 假设输入的前序遍历和中序遍历的结果中都不包含重复的数字
*/

TreeNode* reconstruct(vector<int> &pre, vector<int> &in) {
    if(pre.empty() || in.empty() || pre.size() != in.size())
        return nullptr;
    TreeNode* root = new TreeNode;
    root->data = pre[0];
    root->lchild = root->rchild = nullptr;
    vector<int> left_pre, left_in, right_pre, right_in;
    int index;
    for(int i = 0; i < in.size(); ++i) {
        if(in[i] == pre[0])
            index = i;
    }
    for(int i = 1; i <= index; ++i)
        left_pre.push_back(pre[i]);
    for(int i = 0; i < index; ++i)
        left_in.push_back(in[i]);
    for(int i = index+1; i < in.size(); ++i) {
        right_pre.push_back(pre[i]);
        right_in.push_back(in[i]);
    }
    root->lchild = reconstruct(left_pre, left_in);
    root->rchild = reconstruct(right_pre, right_in);
    return root;
}