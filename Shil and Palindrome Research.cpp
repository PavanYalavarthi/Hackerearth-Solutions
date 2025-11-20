/*

	Problem credits : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-palindrome-research/
	
	Solution:

    To figure out L to R is palindrome, we needed all the character freqecy between them,

    So, had 26 fenwick trees, each storing the frequencies of the respective character.

    #fenwickTree
*/
#include <bits/stdc++.h>
using namespace std;
struct BIT {
	vector<int>BIA;
	void init(int n) {
		BIA.assign(n+1, 0);
	}
	void update(int index, int val) {
		for(; index < BIA.size(); index += index & -index)
			BIA[index] += val;
	}
	int query(int index) {
		int sum = 0;
		for(; index > 0; index -= index & -index)
			sum += BIA[index];
		return sum;
	}
};

struct BITArray {
	vector<BIT>bit_array{26};
	string s;
	BITArray(string s) {
		int n = s.size();
		this->s = s;
		for(int i = 0; i < 26; i++) {
			bit_array[i].init(n);
		}
        // Updating current string state in fenwick trees.
		for(int i = 0;i < n; i++) {
		    bit_array[s[i] - 'a'].update(i + 1, 1);
		}
	}
	void update(int L, char X) {
		char cur_char = s[L - 1];
		bit_array[cur_char - 'a'].update(L, -1);
		s[L - 1] = X;
		bit_array[X - 'a'].update(L, 1);
	}

	string isPalindromePossible(int L, int R) {
		bool isOddPermitted = ((R - L + 1) % 2) != 0;
		for(int i = 0; i < 26; i++) {
			int count_of_chars = bit_array[i].query(R) - bit_array[i].query(L-1);
			if (count_of_chars % 2 != 0) {
				if (isOddPermitted) isOddPermitted = false;
				else return "no\n";
			}
		}
		return "yes\n";
	} 
};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	string s;
	cin >> s;
	BITArray bitArray(s);
	while(Q--) {
		int q;
		cin >> q;
		if (q == 1) {
			int L;
			char X;
			cin >> L >> X;
			bitArray.update(L, X);
		} else {
			int L, R;
			cin >> L >> R;
			cout << bitArray.isPalindromePossible(L, R);
		}
	}	
}