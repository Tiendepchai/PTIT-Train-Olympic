#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O2")
#define int long long 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
  
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<int, int> pii;

using namespace std;

int n;
vector<int> bit;

void update(int i, int v){
  for (; i <= n; i += i & -i) bit[i] += v;
}

int get(int i){
  int ans = 0;
  for (; i > 0; i -= i & -i){
    ans += bit[i];
  }
  return ans;
}

signed main() {
  fastIO
  cin >> n;
  vector <int> a(n+1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  bit.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) update(i, a[i]);
  int q; cin >> q;
  int type, u, v;
  while (q--){
    cin >> type >> u >> v;
    if (type == 1) {
      update(u, v);
    }
    else{
      cout << get(v) - get(u-1) << '\n';
    }
  }
}
