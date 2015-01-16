const int MAXN = 100000 + 50;

int n;
int val[3*MAXN], flag[3*MAXN];

// node id = [l,r), query [a,b)
int _query(int id, int l, int r, int a, int b) {
	if (a >= r || l >= b) { return 0; } // empty intersection
	else if (a <= l && r <= b) // full intersection
		return flag[id] ? r-l-val[id] : val[id];
	else { //partial intersection
		// push flag
		flag[2*id] ^= flag[id]; flag[2*id + 1] ^= flag[id]; flag[id] = 0;

		//compute query
		int m = (l+r+1) / 2;
		int res = _query(2*id, l, m, a, b) + _query(2*id + 1, m, r, a, b);

		//update value
		val[id] = _query(2*id, l, m, l, m) + _query(2*id + 1, m, r, m, r);

		return res;
	}
}

int query(int a, int b) { return _query(1,1,n+1,a,b+1); }

// node id = [l,r), update [a,b)
int _update(int id, int l, int r, int a, int b) {
	if (a >= r || l >= b) { return 0; } // empty intersection
	else if (a <= l && r <= b) { // full intersection
		flag[id] ^= 1;
		return flag[id] ? r-l-val[id] : val[id];
	}
	else { // partial intersection
		// push flag
		flag[2*id] ^= flag[id]; flag[2*id + 1] ^= flag[id]; flag[id] = 0;

		//compute query
		int m = (l+r+1) / 2;
		int res = _update(2*id, l, m, a, b) + _update(2*id + 1, m, r, a, b);

		//update value
		val[id] = _query(2*id, l, m, l, m) + _query(2*id + 1, m, r, m, r);

		return res;
	}
}

void update(int a, int b) { _update(1,1,n+1,a,b+1); }


void init() {
	fill(val,val+3*n,0);
	fill(flag,flag+3*n,0);
}

int main() {
	int m;
//	cin >> n >> m;
	scanf("%d %d\n",&n,&m);
	init();
	forn(_,m) {
		int op,a,b;

		scanf("%d %d %d",&op,&a,&b); //cin >> op >> a >> b;
		a++; b++;
		if (op == 0) update(a,b);
		else printf("%d\n",query(a,b));
//			cout << query(a,b) << endl;
	}
	return 0;
}