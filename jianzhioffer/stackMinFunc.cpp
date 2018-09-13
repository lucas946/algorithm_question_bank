/*
题目：定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数，
     时间复杂度应为O(1);
解题思路：
     构造一个辅助栈，使其栈大小与实际栈大小一致，栈顶元素即为最小值；
*/
class Solution {
public:
    void push(int value) {
        stk1.push(value);
        if(stk2.empty() || value < stk2.top()) {
            stk2.push(value);
        }
        else {
            stk2.push(stk2.top()); // 特别注意这一步
        }
    }

    void pop() {
        stk1.pop();
        stk2.pop();
    }

    int top() {
        return stk1.top();
    }

    int min() {
        return stk2.top();
    }
private:
    stack<int> stk1, stk2;
};