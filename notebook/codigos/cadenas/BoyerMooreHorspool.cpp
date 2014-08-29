//Mejor caso(O(N/M)): Si el alfabeto y el patron son grandes
//Peor caso(O(NM)): Como fuerza bruta, no es recomendable si no cumple el mejor caso
void BoyerMooreHorspool(const string &T, const string &P) {
  int N = T.size();
  int M = P.size();
  int sig[257];
  fill(sig, sig + 257, M);
  forn (i, M) sig[P[i]] = M - 1 - i;
  int i = M - 1;
  int j = M - 1;    
  while (i < N && j >= 0) {
    if (T[i] == P[j])
      i--, j--;
    else {
      i += sig[T[i]];
      j = M - 1;
    }
    if (j < 0) {
      cout << "Match : " << (i + 1) << endl;
      i += M + 1;
      j = M - 1;
    }
  }
}