#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O2")
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define run int t; for (cin>>t; t--; )

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<int, int> pii;

// n! % pow(k, m) == 0

const int mod = 1e9+7;
const int pr = 1e7;

vector<bool> prime(pr + 1, 1);
vector<int> primes;

void init(int n = pr){
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == 1){
      primes.push_back(p);
      for (int i = p * p; i <= n; i += p)
      prime[i] = 0;
    }
  }
}

void sol(){
  int n, k; cin >> n >> k;
  map<int, int> mA, mB;
  vector<int> A(n), B(n), div;
  for (int &i:A) cin >> i;
  for (int &x:A) {
    int tmp = x;
    for (int i = 2; i*i <= tmp; i++){
      while (tmp % i == 0 && prime[i])
      {
        mA[i]++;
        tmp /= i;
      }
    }
    if (tmp != 1) mA[tmp]++;
  }
  int c = 1;
  while (c <= k)
  {
    mB.clear();
    for (int &i:B) cin >> i;
    for (int &x:B) {
      int tmp = x;
      for (int i = 2; i*i <= tmp; i++){
        while (tmp % i == 0 && prime[i])
        {
          mB[i]++;
          tmp /= i;
        }
      }
      if (tmp != 1) mB[tmp]++;
    }
    bool flg = 1;
    for (auto &[x, y]:mB){
      if (mA[x] < y) flg = 0;
    }
    if (flg) div.push_back(c);
    c++;
  }
  cout << div.size() << '\n';
  for (auto x:div) cout << x << ' ' ;
}

signed main() {
  init();
  fastIO
  // run
    sol();
}