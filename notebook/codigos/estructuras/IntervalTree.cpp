#include <bits/stdc++.h>

using namespace std;
//La hojas tienen indices [n, 2n)

struct IntervalTree {
	vector<int> t;
	int N;
	IntervalTree(vector<int> &vec) {
		int n = vec.size();
		N = 1 << (32 - __builtin_clz(n));
		t = vector<int>(N, 0);
	}
};
int main() {
	

	return 0;
}