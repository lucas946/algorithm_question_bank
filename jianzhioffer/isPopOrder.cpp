/*
题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出序列。
假设压入栈的所有数字均不相等。例如序列1、2、3、4、5是某栈的压栈序列，序列4、5、3、2、1
是该压栈序列对应的一个弹出序列，但4、3、5、1、2就不可能是该压栈的弹出序列；

解题思路：（需要使用辅助栈）
1. 如果下一个弹出的数字刚好是栈顶元素，那么直接弹出；
2. 如果下一个弹出的数字不在栈顶，则把压栈序列中还没有入栈的数字压入辅助栈，直到把下一个需要
   弹出的数字压入栈顶即可；
3. 如果所有的数字都压入栈了仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列
*/

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    if(pushV.empty() || popV.empty())
        return false;
    stack<int> tmp;
    int count = 0, num = 0;
    while(count < pushV.size()) {
        tmp.push(pushV[count]);
        while(num < popV.size() && !tmp.size() && tmp.top() == popV[num]) {
            tmp.pop();
            ++num;
        }
        ++count;
    }
    return tmp.empty();
}