/* 题目描述：
 * 给定一个序列，求该序列的最长非降子序列的长度
 *
 * 状态定义：dp[i]以i结尾的最长非降子序列的长度>=1
 * 状态转移方程：dp[i]=max{dp[j]+1}，其中，j<i,seq[j]>seq[i]
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LIS(vector<int> &sequences){
	int length = sequences.size();
	int dp[length];
	int result = 1;
	for(int i=0;i<length;++i)
		dp[i] = 1;
	for(int i=1;i<length;++i){
		int max = 0;
		for(int j=0;j<=i-1;++j){
			if(j<i&&sequences[j]<=sequences[i]&&dp[j]>max){
				max = dp[j];
				dp[i] = dp[j]+1;
			}
		}
		if(dp[i]>result) result = dp[i];
	}
	return result;
}

int main(){
	int numbers[] = {6,5,4,3,2,1};
	vector<int> seq(numbers,numbers+6);
	int result = LIS(seq);
	cout<<result<<endl;

	return 0;
}
