/*
    Problem credits: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/counting-in-byteland/


    Solution: Used 3D fenwick tree

    #3DFenwickTree
*/

#include <bits/stdc++.h>
using namespace std;
struct BIT {
    static const int MAX_SIZE = 102;
    long BIA[MAX_SIZE][MAX_SIZE][MAX_SIZE] = {{{0}}};
    
    void update(int x, int y, int z, int val) {
        for (int i = x; i < MAX_SIZE; i += i & -i)
            for (int j = y; j < MAX_SIZE; j += j & -j)
                for (int k = z; k < MAX_SIZE; k += k & -k)
                    BIA[i][j][k] += val;
    }
    
    long query(int x, int y, int z) {
        long sum = 0;
        for(int i = x; i > 0; i -= i & -i)
            for(int j = y; j > 0; j -= j & -j)
                for(int k = z; k > 0; k -= k & -k)
                    sum += BIA[i][j][k];
        return sum;
    }
    
    long range_query(int x1, int y1, int z1, int x2, int y2, int z2) {
        return  query(x2, y2, z2)
            - query(x1 - 1, y2, z2)
            - query(x2, y1 -1, z2)
            - query(x2, y2, z1 -1)
            + query(x1 -1, y1 - 1, z2)
            + query(x2, y1 - 1, z1 - 1)
            + query(x1 - 1, y2, z1 -1)
            - query(x1 -1, y1 -1, z1 -1);
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	BIT fenwickTree;
	int q;
	long sum =0;
	while(Q--) {
		cin >> q;
		if (q == 1) {
			int x, y, z, val;
            cin >> x >> y >> z >> val;
            x++, y++, z++;
            sum += val;
            fenwickTree.update(x, y, z, val);
		} else {
			int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            x1++, y1++, z1++, x2++, y2++, z2++;
            cout << sum - fenwickTree.range_query(x1, y1, z1, x2, y2, z2) << endl;
		}
	}
}