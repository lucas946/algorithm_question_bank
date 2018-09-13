/*问题描述：
 * 一个台阶总共有n级，如果一次可以跳1级，也可以跳2级，
 * 求总共有多少种跳法？
 */
#include<iostream>

using namespace std;

int step(int n){
	if(n == 1) return 1;
	else if(n == 2) return 2;
	else return step(n-1)+step(n-2);
}

int main(int argc, char *argv[]){
	int n,count;
	cin>>n;//输入台阶数
	count = step(n);
	cout<<count<<endl;
	return 0;
}
