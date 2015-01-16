#include <bits/stdc++.h>

using namespace std;
struct fenwick {
	vector<int> op;
	int siz;

	// arbol para el intervalo (0,n)
	fenwick(int n) {
		op = vector<int>(n,0);
		siz = 0;
	}

	int leq(int key) {
		int res = 0;
		for (int i = key; i > 0; i -= i & (-i)) res += op[i];
		return res;
	}

	int eq(int key) { //Te dice cuantos elementos hay del key
		return leq(key) - leq(key-1);
	}

	void insert(int key, int ncopies = 1) {
		for (int i = key; i < op.size(); i += i & (-i)) op[i] += ncopies;
		siz += ncopies;
	}

	int size() { return siz; }

	int nth(int pos) {//Los elementos estan indexados desde 1
		if (pos < 1 || pos > siz) return -1;
		int res = 0, mask = 1LL << (31 - __builtin_clz(op.size())), p = pos;
		while (mask) {
			if (op[res| mask] < p) {
				res |= mask;
				p -= op[res];
			}
			mask >>= 1;
		}
		return res + 1;
	}
};

int main(int argc, char const *argv[]) {
	fenwick tree(1000000);
	tree.insert(3, 2);
	tree.insert(5);
	tree.insert(11, 5);
	tree.insert(13);
	tree.insert(7, 2);
	tree.insert(23);
	//cout << tree.nth(2) << endl;
	cout << tree.eq(4) << endl;
	return 0;
}