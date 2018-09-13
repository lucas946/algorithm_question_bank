/*
** 生成镜像二叉树
*/

// 递归方式实现
void BTreeMirror(BTreeNode* node) {
    if(node == nullptr)
        return;
    BTreeNode* tmp = node->left;
    node->left = node->right;
    node->right = tmp;

    BTreeMirror(node->left);
    BTreeMirror(node->right);
}

// 非递归方式实现
/*
（层次遍历的思想）
首先，将根节点pRoot入队；
第一步：当队列未空时，获取当前层次的节点总数，即当前队列的长度；执行第二步；
第二步：按照当前层的节点总数，出队进行遍历节点，在遍历时，交换左右节点，如果左右节点存在，
则入队；当遍历完当前所有节点时，遍历下一层，执行第一步；
*/
void BTreeMirror(BTreeNode* node) {
    if(node == nullptr)
        return;
    queue<BTreeNode*> que;
    que.push(node);
    int curLevelNodeTotal = 0;
    while(!que.empty()) {
        curLevelNodeTotal = que.size();
        int cnt = 0;
        while(cnt < curLevelNodeTotal) {
            ++cnt;
            node = que.front();
            que.pop();
            BTreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;

            if(node->left != nullptr)
                que.push(node->left);
            if(node->right != nullptr)
                que.push(node->right);
        }
    }
    return;
}