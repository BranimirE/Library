typedef complex<double> pnt;   // stores X in real part, Y in imaginary part
struct compare_x {   // orders by X, breaking ties by Y
  bool operator()(const pnt &a, const pnt &b) const {
    if (a.real() != b.real())
      return a.real() < b.real();
    else
      return a.imag() < b.imag();
  }
};
 
struct compare_y { // orders by Y, breaking ties by X
  bool operator()(const pnt &a, const pnt &b) const {
    if (a.imag() != b.imag())
      return a.imag() < b.imag();
    else
      return a.real() < b.real();
  }
};
// Returns the closest distance between two points in S
static double closest(const vector<pnt> &S) {
  int N = S.size();
  vector<pnt> Sx = S;     // to be sorted by X coordinate
  set<pnt, compare_y> Sy; // active points, ordered by Y coordinate
  int tail = 0;           // points in Sx in the range [tail, i) are in Sy
 
  sort(Sx.begin(), Sx.end(), compare_x());
  double h = HUGE_VAL;
  for (int i = 0; i < N; i++) {
      // erase points whose X value is too small to even consider
      while (Sx[i].real() - Sx[tail].real() > h) {
	  Sy.erase(Sx[tail]);
	  tail++;
      }
      set<pnt, compare_y>::const_iterator y1, y2; // range in Sy within h of current point
      y1 = lower_bound(Sy.begin(), Sy.end(), pnt(-HUGE_VAL, Sx[i].imag() - h), compare_y());
      y2 = upper_bound(Sy.begin(), Sy.end(), pnt( HUGE_VAL, Sx[i].imag() + h), compare_y());
 
      for (set<pnt, compare_y>::const_iterator j = y1; j != y2; ++j)
	h = min(h, abs(Sx[i] - *j));
      Sy.insert(Sx[i]);  // add current point to active set
    }
  return h;
}
