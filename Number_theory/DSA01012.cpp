#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O2")
#define int long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
  
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<int, int> pii;

void gray(int n)
{ 
  for(int i=0;i<pow(2, n);i++)
  { 
    int val=(i^(i/2)); 
    bitset <11> r(val);  
    cout << r.to_string().substr(11 - n) << " " ; 
  } 
} 

signed main() {
  fastIO
  int t;
  for (cin>>t; t--; ){
    int n; cin >> n;
    gray(n);
    cout << '\n';
  }
}
// 010110101100110 : 3