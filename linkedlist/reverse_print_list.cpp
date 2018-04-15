/* 题目描述：
 * 从尾到头打印节点
 * 
 * 用递归实现，因为递归本质上就是一个栈结构，但是递归有一个缺点，
 * 就是当链表过长时，容易导致函数调用栈溢出。
 *
 */
#include<iostream>

using namespace std;

struct listnode{
	int data;
	listnode *next;
};

void reverse_print_list(listnode *head){
	if(head != NULL){
		if(head->next != NULL){
			reverse_print_list(head->next);
		}
		
		cout<<head->data<<" ";
	}
	
}

void create_list(listnode *&head, int num){
	listnode *temp = new listnode;
	temp->next = NULL;
	temp->data = num;
	if(head == NULL){
		head = temp;
		return;
	}
	temp->next = head;
	head = temp;
}

int main(){
	listnode *head = NULL;
	for(int i=1;i<=10;++i)
		create_list(head, i);
	listnode *tmp = head;
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;

	reverse_print_list(tmp);
	cout<<endl;
	return 0;
}
