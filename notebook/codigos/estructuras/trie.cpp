int trie[10000000][26];
int sig;
int root = 0;

void reset() {
    sig = -1;
    addNode();//Root
}

void addNode() {   
    sig++;
    memset(trie[sig], -1, sizeof(trie[sig]));
}

void insert(const string &s) {
    int cur = root;
    for (int i = 0; i < sz(s); i++) {
		int c = s[i] - 'a';
		if (trie[cur][c] == -1) {
		    addNode();
		    trie[cur][c] = sig;
		}
		cur = trie[cur][c];
    }
}