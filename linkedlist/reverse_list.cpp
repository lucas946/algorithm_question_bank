/* 问题描述：反转链表
 * 输入一个链表的头节点，从尾到头反过来输出每个节点的值
 */

#include<iostream>

using namespace std;

struct listnode{
	int data;
	struct listnode *next;
};

void creatlist(struct listnode * &head, int n){
	// 创建节点
	listnode *p = (listnode*)malloc(sizeof(listnode));
	p->data = n;
	p->next = NULL;
	if(head == NULL){
		head = p;
		return;
	}
	p->next = head;
	head = p;
}

void printlist(struct listnode *head){
	listnode *p = head;
	while(p != NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

// 注意该函数返回值类型
struct listnode* reverselist(struct listnode *head){
	struct listnode *prev = head;
	struct listnode *cur = head->next;
	struct listnode *temp;
	while(cur){
		temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	head->next = NULL;
	return prev;
}

int main(int argc, char *argv[]){
	struct listnode *head = NULL;
	for(int i=0;i<10;++i)
		creatlist(head,i);
	printlist(head);
	head = reverselist(head);
	printlist(head);
	return 0;
}
