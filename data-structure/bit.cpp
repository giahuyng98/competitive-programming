#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define REP(i, a) for (int i(0); i < (a); ++i)
#define FOR(i, a, b) for (int i(a); i <= (b); ++i)

#ifdef LOCAL
#include <mydebug.h>
#else
#define debug(...)
#endif

struct BIT {
  int size;
  vector<int> bit;

  BIT(int size) : size(size) {
    bit.resize(size + 1);
  }

  void add(int idx, int val) {
    for(; idx <= size; idx += idx & -idx) {
      bit[idx] += val;
    }
  }

  int get(int idx) {
    int res = 0;
    for(; idx > 0; idx -= idx & -idx) {
      res += bit[idx];
    }
    return res;
  }

  int get(int l, int r) {
    return get(r) - get(l - 1);
  }

  int lowerBound(int val) {
    static const int msb = log2(size) + 1;
    int res = 0;
    for(int l = msb; l >= 0; --l) {
      int shift = (1 << l);
      if (res + shift <= size && bit[res + shift] < val) {
        val -= bit[res + shift];
        res += shift;
      }
    }
    return ++res;
  }

};

using namespace std;
using ll = long long;

void solve() {
  vector<int> v = {0,1,2,3,4,5,6,7,8,9};
  const int n = (int)v.size() - 1;
  BIT bit(n);
  FOR(i, 1, n) {
    bit.add(i, v[i]);
  }
  FOR(i, 1, n) {
    debug(i, bit.get(i));
  }
  FOR(i, 1, 50) {
    debug(i, bit.lowerBound(i));
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}
