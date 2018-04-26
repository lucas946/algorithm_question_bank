#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
	int data;
	ListNode *next;
};

void creatlist(struct ListNode * &head, int n){
	// 创建节点
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = n;
	p->next = NULL;
	if(head == NULL){
		head = p;
		return;
	}
	p->next = head;
	head = p;
}

void printlist(struct ListNode *head){
	ListNode *p = head;
	while(p != NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

ListNode *longest_common_string(ListNode *head1, ListNode *head2, int &common){
	if(head1 == nullptr || head2 == nullptr)
		return nullptr;
	int length1=0,length2=0,max=0;
	ListNode *flag = nullptr;
	ListNode *head = head1;
	ListNode *p = head1;
	ListNode *q = head2;
	ListNode *result = nullptr;
	while(head1){
		++length1;
		head1 = head1->next;
	}
	while(head2){
		++length2;
		head2 = head2->next;
	}
	vector<vector<int> >dp(length1+1, vector<int>(length2+1, 0));
	for(int i=1;i<=length1;++i){
		for(int j=1;j<=length2;++j){
			if(p->data == q->data)
				dp[i][j] = dp[i-1][j-1]+1;
			if(dp[i][j]>max){
				max = dp[i][j];
				flag = p;
			}
			q = q->next;
		}
		p = p->next;
	}
	int count = 0;
	common = max;
	cout<<max<<endl;
	while(head!=flag){
		++count;
		head = head->next;
	}


	return result;
}

int main(){
	ListNode *head1 = nullptr, *head2 = nullptr;
	ListNode *result = nullptr;
	int count = 0;
	for(int i=1;i<6;++i)
		creatlist(head1, i);
	for(int i=3;i<8;++i)
		creatlist(head2, i);
	result = longest_common_string(head1, head2, count);
	for(int i=count;i>0;--i){
		cout<<result->data<<" ";
		result = result->next;
	}
	cout<<endl;
	return 0;
}
