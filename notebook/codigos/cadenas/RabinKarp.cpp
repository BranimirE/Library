void RabinKarp(string t, string s) {
  const int p = 31;//si tambien hay mayusculas usar 53
  vector<long long> p_pow (max (s.length(), t.length()));
  p_pow[0] = 1;
  for (int i = 1; i < p_pow.size(); ++i)
    p_pow[i] = p_pow[i-1] * p;

  vector<long long> h (t.length());
  for (int i = 0; i < t.length(); ++i) {
    h[i] = (t[i] - 'a' + 1) * p_pow[i];//Cuidado con Mayusculas
    if (i)  h[i] += h[i-1];
  }
  
  long long h_s = 0;
  for (int i = 0; i < s.length(); ++i)
    h_s += (s[i] - 'a' + 1) * p_pow[i];//Cuidado con Mayusculas

  for (int i = 0; i + s.length() - 1 < t.length(); ++i) {
    long long cur_h = h[i+s.length()-1];
    if (i)  cur_h -= h[i-1];
    
    if (cur_h == h_s * p_pow[i])
      cout << "Match : " << i << endl;
  }
}
