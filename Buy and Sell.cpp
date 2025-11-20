/*
    Problem credits: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/buy-and-sell/
    
	Solution: Fenwick tree on price
*/

#include <bits/stdc++.h>
using namespace std;
struct BIT {
	vector<int>v;
	BIT(int n) {
		v.assign(n+1, 0);
	}
	void update(int index, int val) {
		for(; index < v.size(); index += index & -index)
			v[index] += val;
	}

	int query(int index) {
		int sum = 0;
		for(; index > 0; index -= index & -index)
			sum += v[index];
		return sum;
	}
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	unordered_map<string, pair<int, int>> mp; // keeps product -> (price, quantity)
	string s;
	int cost;
	int max_price = 0;
	while(N--) {
		cin >> s >> cost;
		mp[s] = {cost, 0};
		max_price = max(max_price, cost);
	}
	int Q;
	cin >> Q;
	char op;
	int total_prod = 0;
	BIT fenwickTree(max_price);
	int sum = 0;
	while(Q--) {
		cin >> op;
		if (op == '?') {
			int val;
			cin >> val;
			cout << sum - fenwickTree.query(val) << endl;
		} else {
			string s;
			cin >> s;
			auto& [price, quantity] = mp[s]; //taking things by reference to update
			if (op == '+') {
			    sum++;
			    quantity++;
			    fenwickTree.update(price, 1);
			} else if (quantity > 0) {
			    quantity--;
			    sum--;
			    fenwickTree.update(price, -1);
			}
		}
	}
	return 0;
}