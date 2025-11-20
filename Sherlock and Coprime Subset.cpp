/*
Problem description: https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/sherlock-and-coprime-subset/

Solution: 

Dp solution where it can be skipped or included(when mask adds the current element mask)
*/
#include<bits/stdc++.h>
using namespace std;
int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int helper(vector<int>& arr, int index, int mask, vector<vector<int>> & dp) {
    if(index == arr.size()) return 0;
    int & ans = dp[index][mask];
    if(ans != -1) return ans;
    ans = helper(arr, index + 1, mask, dp);
    if ((arr[index] & mask) == 0) { // If & is zero only when primes are differnt i.e., co-prime
        ans = max(ans, 1 + helper(arr, index + 1, mask | arr[index], dp));
    }
    return ans;
    
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0, temp, val; i< n; i++) {
            cin >> temp;
            val = 0;
            for(int j = 0; j < 15; j++) {
                if(temp % primes[j] == 0) { 
                    val |= (1 << j);
                }
            }
            arr[i] = val;
        }
        vector<vector<int>>dp(n, vector<int>(1 << 15, -1));
        cout << helper(arr, 0, 0, dp) << endl;
    }
    return 0;
}