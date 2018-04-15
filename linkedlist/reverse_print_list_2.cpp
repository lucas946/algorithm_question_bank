/* 题目描述：
 * 输入一个链表的头节点，从尾到头反过来打印出每个节点的值
 *
 * 注意：递归的本质就是栈，当链表长度过长时，容易导致函数调用栈溢出
 * 实现方式：递归
 *
 */
#include<iostream>
#include<stack>

using namespace std;

struct listnode{
	int data;
	listnode *next;	
};


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

void reverse_print_list(listnode *head){
	if(head != NULL){
		if(head->next != NULL){
			reverse_print_list(head->next);
		}
		cout<<head->data<<" ";
	}
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
	
	reverse_print_list(head);
	cout<<endl;
	return 0;
}
