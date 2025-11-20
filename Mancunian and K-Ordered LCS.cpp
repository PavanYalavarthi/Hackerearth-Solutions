/*
Problem Credits: https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/

Solution: Normal LCS with handling of K non matchings
*/
#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001][6];

int helper(vector<int> & a1, vector<int> & a2, int i, int j, int k) {
	if(i == 0 || j == 0) return 0;
	if (dp[i][j][k] != -1) return dp[i][j][k];
	if(a1[i-1] == a2[j-1]) return dp[i][j][k] = 1 + helper(a1, a2, i -1, j -1, k);
	int ans = max(helper(a1, a2, i - 1, j, k), helper(a1, a2, i, j - 1, k));
	if(k > 0) {
		ans = max(ans, 1 + helper(a1, a2, i-1, j-1, k-1));
	}
	return dp[i][j][k] = ans;
}

int main() {
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> a1(m), a2(n);
	for(int i = 0; i< m; i++) cin >> a1[i];
	for(int i = 0; i< n; i++) cin >> a2[i];
	memset(dp, -1, sizeof(dp));
	cout << helper(a1, a2, m, n, k);
	return 0;
}