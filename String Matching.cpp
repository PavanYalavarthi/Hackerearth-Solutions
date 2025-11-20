/*
Problem credits: https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/string-matching-google-3dc355a5/

Solution:

nextIndex[i][d] = next position >= i where digit d occurs ( If digit does not occur - store sz (out of bounds) ). Build this from right to left

Needed keeps track of chars that are needed to be part of substring

As we need all chars present in needed, We need to pick the last index which contains given char
Let that max is j, #substring possible is (sz -j) as those chars are optinally picked


*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    string s;
    cin >> s;
    int n, sz = s.size();
    cin >> n;
    vector<vector<int>>nextIndex(sz + 1, vector<int>(10, sz)); 
    for(int i = sz - 1; i >=0; i--) {
        nextIndex[i] = nextIndex[i+1];
        nextIndex[i][s[i] - '0'] = i;
    }
    vector<bool> needed(10, false);
    for(int i = 0, tmp; i< n; i++) {
        cin >> tmp;
        needed[tmp] = true;
    }
    long ans = 0;
    for(int i = 0; i < sz; i++) {
        int j = i;
        for(int k =0; k < 10; k++) {
            if(needed[k]) {
                j = max(j, nextIndex[i][k]);
            }
        }
        ans += (sz - j);
    }
    cout << ans;
    return 0;
}