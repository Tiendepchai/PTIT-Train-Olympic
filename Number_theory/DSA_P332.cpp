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
const int maxLL = LLONG_MAX;
const int pr = 1e6;

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
  int n, k, ans = maxLL; cin >> n >> k;
  map<int, int> mK;
  for(int i=0; i < primes.size() && primes[i]*primes[i]<=k;i++){
    if(k%primes[i]==0){
      while(k%primes[i]==0){
        mK[primes[i]]++;
        k/=primes[i];
      }
    }
  }
  if(k>1)mK[k]++;
  for (auto &[x, y]:mK) {
    int nn = n;
    int cnt = 0;
    while(nn >= x){
      nn /= x;
      cnt += nn;
    }
    ans = min(ans, cnt/y);
  }
  // for (auto &[x, y]:mK) cout << x << ' ' << y << '\n';
  cout << ans << '\n';
}

signed main() {
  init();
  fastIO
  run
    sol();
  
}