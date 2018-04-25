#include<iostream>
#include<vector>
#include<string>

using namespace std;

int longestSubstring(const string &s1, const string &s2){
	int m = s1.size();
	int n = s2.size();
	if(m == 0|| n == 0)
		return -1;
	int max = -1;
	vector<vector<int> > dp(m+1, vector<int>(n+1,0));
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j){
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = 0;
			if(max<dp[i][j])
				max = dp[i][j];
		}
	return max;
}

int main(){
	string s1 = "aghjis";
	string s2 = "bghios";
	int result = longestSubstring(s1,s2);
	cout<<result<<endl;

	return 0;
}
