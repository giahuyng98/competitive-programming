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

using namespace std;
using ll = long long;

class Trie {
  static const size_t ALPHA_SIZE = 26;

  struct Node {
    vector<unique_ptr<Node>> child;
    bool isEnd;
    Node() {
      child.resize(ALPHA_SIZE);
      isEnd = false;
    }
  };

  unique_ptr<Node> root = make_unique<Node>();

public:
  void add(const string &s) {
    auto cur = root.get();
    for (const char &c : s) {
      int idx = c - 'a';
      if (cur->child[idx] == nullptr) {
        cur->child[idx] = make_unique<Node>();
      }
      cur = cur->child[idx].get();
    }
    cur->isEnd = true;
  }

  bool exists(const string &s) const {
    auto cur = root.get();
    for (const char &c : s) {
      int idx = c - 'a';
      if (cur->child[idx] == nullptr) {
        return false;
      }
      cur = cur->child[idx].get();
    }
    return cur->isEnd;
  }

  void dfs() const {
    auto dfs_impl = [&](auto &&ref, auto &&cur, string s) -> void {
      if (cur->isEnd) {
        cout << s << endl;
      }
      for(size_t idx = 0; idx < ALPHA_SIZE; ++idx) {
        if (cur->child[idx]) {
          ref(ref, cur->child[idx].get(), s + char('a' + idx));
        }
      }
    };
    dfs_impl(dfs_impl, root, "");
  }
};

void solve() { 
  Trie trie; 
  trie.add("nguyen");
  trie.add("gia");
  trie.add("huy");

  debug(trie.exists("nguyen"));
  debug(trie.exists("gia"));
  debug(trie.exists("bao"));

  trie.dfs();
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
