/* 题目描述：
 * 输入一个链表的头节点，从尾到头反过来打印出每个节点的值
 * 
 * 注意： 不能采取先反转链表结构再打印链表的方式，因为不能改变链表结构
 *
 * 实现方式： 栈
 *
 */
#include<iostream>
#include<stack>

using namespace std;

struct listnode{
	int data;
	listnode *next;	
};

stack<int> reverse_print_list(listnode *head){
	stack<int> temp;

	while(head != NULL){
		temp.push(head->data);
		head = head->next;
	}

	return temp;
}

void create_list(listnode *&head, int num){
	listnode *tmp = new listnode;
	tmp->data = num;
	tmp->next = NULL;
	if(head == NULL){
		head = tmp;
		return;
	}
	tmp->next = head;
	head = tmp;
}


int main(){
	// head一定要初始化为NULL，否则变为野指针
	listnode *head = NULL;
	for(int i=1;i<=10;++i)
		create_list(head,i);
	listnode *tmp1 = head;
	listnode *tmp2 = head;
	while(tmp1){
		cout<<tmp1->data<<" ";
		tmp1 = tmp1->next;
	}
	cout<<endl;
	stack<int> result = reverse_print_list(tmp2);
	while(!result.empty()){
		cout<<result.top()<<" ";
		result.pop();
	}
	cout<<endl;
	return 0;
}
