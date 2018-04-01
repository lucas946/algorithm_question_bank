/* 问题描述：
 * 将十进制转换为指定进制数
 * 输入：
 * 	n: 十进制数 m: 进制编号（如8）
 * 输出：
 * 	转换后的进制数
 */
#include<iostream>
#include<stack>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	stack<int> stk;
	if(n == 0){
		cout<<0<<endl;
		return 0;
	}
	while(n){
		stk.push(n%k);
		n /= k;
	}
	while(!stk.empty()){
		cout<<stk.top();
		stk.pop();
	}
	cout<<endl;

	return 0;
}
