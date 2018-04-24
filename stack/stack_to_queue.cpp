/* 问题描述：
 * 用两个栈实现队列
 *
 */
template<typename T>
class CQueue{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
	
};

template<typename T>
void CQueue<T>::appendTail(const T& node){
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead(){
	if(!stack2.empty()){
		T temp = stack2.top();
		stack2.pop();
		return temp;
	}
	else{
		while(!stack1.empty()){
			T temp = stack1.top();
			stack2.push(temp);
			stack1.pop();
		}
		// 当队列为空时，不能删除元素
		if(stack2.empty())
			throw new exception("queue is empty");
		T temp = stack2.top();
		stack2.pop();
		return temp;
	}
}
