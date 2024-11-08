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
typedef vector<int> vi;

const int mod = 1e9+7, maxn = 1e6+5;
const int maxLL = LLONG_MAX;

int dist[1000005], visited[1000005];
vi st(6), en(6);


vi rR(vi &a){
  vi ans(6);
  ans[0] = a[0];
  ans[1] = a[4];
  ans[2] = a[1];
  ans[3] = a[3];
  ans[4] = a[5];
  ans[5] = a[2];
  return ans;
}

vi rL(vi &a){
  vi ans(6);
  ans[0] = a[3];
  ans[1] = a[0];
  ans[2] = a[2];
  ans[3] = a[4];
  ans[4] = a[1];
  ans[5] = a[5];
  return ans;
}

int convertToNum(vi &x) {
  int ans = 0;
  for(int i = 0; i < x.size(); i++)
    ans = ans*10 + x[i];
  return ans;
}

void BFS(){
  memset(visited, 0, sizeof(visited));
  queue<vi>Q;
  Q.push(st);
  visited[convertToNum(st)] = 1;
  dist[convertToNum(st)] = 0;

  while (!Q.empty()){
    vi t = Q.front();
    Q.pop();
    if (t == en) break;
    vi tmp = rR(t);
    if (visited[convertToNum(tmp)] == 0){
      Q.push(tmp);
      visited[convertToNum(tmp)] = 1;
      dist[convertToNum(tmp)] = dist[convertToNum(t)] + 1;
    }
    tmp = rL(t);
    if (visited[convertToNum(tmp)] == 0){
      Q.push(tmp);
      visited[convertToNum(tmp)] = 1;
      dist[convertToNum(tmp)] = dist[convertToNum(t)] + 1;
    }
  }
  cout << dist[convertToNum(en)] << '\n';
}

void sol(){
  for (int &i:st) cin >> i;
  for (int &i:en) cin >> i;
  BFS();
}

signed main() {
  fastIO
  // run
    sol();
  
}