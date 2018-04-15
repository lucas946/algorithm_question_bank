/* 题目描述：
 * 假设有1,3,5三种面值的硬币，输入一个数字，代表金额，求
 * 用这三种面值的硬币来兑换该金额至少需要多少硬币？
 *
 * 状态定义：dp[i]表示金额i至少需要多少硬币兑换
 * 状态转移方程：dp[i] = min{dp[i-coins[j]+1]}
 */
#include<iostream>
#include<climits>
using namespace std;

const int coins[] = {1,3,5};

int least_coins(int money){
	const int number = money;
	int dp[number+1];
	for(int i=0;i<=number;++i)
		dp[i] = INT_MAX;
	dp[0] = 0;
	for(int i=1;i<=number;++i)
		for(int j=0;j<3;++j){
			if(i>=coins[j]&&dp[i-coins[j]]+1<dp[i])
				dp[i] = dp[i-coins[j]]+1;
		}
	return dp[number];
}

int main(){
	int money;
	cin>>money;
	int result = least_coins(money);
	cout<<result<<endl;
	return 0;
}
