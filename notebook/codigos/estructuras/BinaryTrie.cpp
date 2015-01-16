#include <bits/stdc++.h>

using namespace std;
struct BinaryTrie{
    int bs; //bitssize
    vector<bool> t;
    BinaryTrie(int _bitssize) {
	bs = _bitssize;
	t = vector<bool>(1 << (bs + 1), false);
    }
    void insert(int num) {
	int cur = 1, child;
	for (int i = bs - 1; i >= 0; i--) {
	    child = cur * 2 + ((num & (1 << i)) != 0);
	    t[child] = true;
	    cur = child;
	}
    }
    int queryMaxXOR(int num) {
	int cur = 1, op, child;
	for (int i = bs - 1; i >= 0; i--) {
	    op = ((num & (1 << i)) == 0); // tomamos el inverso, 0 <=> 1 (y viceversa)
	    child = cur * 2 + op;
	    if (!t[child]) op = !op;
	    cur = cur * 2 + op;
	}
	return (cur - (1 << bs));//Fuimos por bits que existen => solo le quitamos el 1 que usamos para la raiz
    }
    /*
      Para el erase al numero simplemente le dicionamos el bit que representa a la raiz y tendremos el nodo que representa ese numero
     */
};
int main() {
    BinaryTrie bt(3);
    bt.insert(7);
    bt.insert(2);
    cout << bt.queryMaxXOR(4) << endl;
    return 0;
}
