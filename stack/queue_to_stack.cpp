/* 问题描述：
 * 用队列实现栈
 */
template<typename T>
class CStack
{
public:
	CStack(void);
	~CStack(void);

	void appendStack(const T& node);
	T deleteStack();
private:
	queue<T> queue1;
	queue<T> queue2;
};

template<typename T>
void CStack<T>::appendStack(const T& node){
	if(queue1.empty()&&queue2.empty()){
		queue1.push(node);
		return;
	}
	if(queue1.empty()){
		queue2.push(node);
		return;
	}
	if(queue2.empty()){
		queue1.push(node);
		return;
	}
}

template<typename T>
T deleteStack(){
	if(queue1.empty()&&queue2.empty())
		throw new exception("stack is empty");
	if(!queue1.empty()){
		while(queue1.size()>1){
			T temp = queue1.front();
			queue1.pop();
			queue2.push(temp);
		}
		T temp = queue1.front();
		return temp;
	}
	if(!queue2.empty()){
		while(queue2.size()>1){
			T temp = queue2.front();
			queue2.pop();
			queue1.push(temp);
		}
		T temp = queue2.front();
		return temp;
	}
}
