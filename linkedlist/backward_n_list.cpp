/* 问题描述：
 * 寻找链表倒数第N个元素
 */
#include<iostream>

using namespace std;

struct Listnode{
	int data;
	Listnode *next;
};

void create_list(Listnode * &head, int n){
	Listnode *p = (Listnode *)malloc(sizeof(Listnode));
	p->data = n;
	p->next = NULL;
	if(head == NULL){
		head = p;
		return;
	}
	p->next = head;
	head = p;
}

void print_list(Listnode *head){
	Listnode *p = head;
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

Listnode *backward_n_list(Listnode *head, int n){
	if(head == NULL|| n<=0)
		return NULL;
	Listnode *p1 = head;
	for(int i=0;i<n-1;++i){
		if(p1->next == NULL)
			return NULL;
		else{
			p1 = p1->next;
		}
	}
	Listnode *p2 = head;
	while(p1->next != NULL){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

int main(){
	Listnode *head = NULL;
	for(int i=0;i<10;++i)
		create_list(head,i);
	print_list(head);
	Listnode *found = NULL;
	found = backward_n_list(head, 11);
	if(found != NULL)
		cout<<found->data<<endl;
	else
		cout<<"ERROR"<<endl;	
	return 0;
}
