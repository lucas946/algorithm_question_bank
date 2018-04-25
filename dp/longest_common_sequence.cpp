#include<iostream>
#include<vector>

using namespace std;

int LCS(vector<int> &nums1, vector<int> &nums2){
	int m = nums1.size();
	int n = nums2.size();
	if(m==0||n==0) 
		return -1;
	vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j){
			if(nums1[i-1] == nums2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}

	return dp[m][n];
}

int main(){
	int tmp1[] = {1,4,6,7,8};
	int tmp2[] = {1,6,8,7};
	vector<int> nums1(tmp1, tmp1+5);
	vector<int> nums2(tmp2, tmp2+4);
	int result = LCS(nums1, nums2);
	cout<<result<<endl;

	return 0;
}
