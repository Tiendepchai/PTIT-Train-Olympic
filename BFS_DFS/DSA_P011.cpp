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

vector<vector<int>> visited(8, vector<int>(8));
int n, m, ans = 0; 
vector<string> a;
vector<pii> save;

vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

void DFS(int X, int Y){
  visited[X][Y] = 1;
  // cout << X << ' ' <<  Y << '\n';
  for (int k = 0; k < 4; k++){
    int x_1 = X + dx[k], y_1 = Y + dy[k];
    if (x_1 >= 0 && x_1 < n && y_1 >= 0 && y_1 < m && !visited[x_1][y_1] && a[x_1][y_1] == '#'){
      DFS(x_1, y_1);
    }
  }
}

void BFS(int stX, int stY){
  queue<pii> Q;
  visited[stX][stY] = 1;
  Q.push({stX, stY});


  while(!Q.empty()){
    int x = Q.front().first, y = Q.front().second;
    Q.pop();
    int nX = x, nY = y+1;
    if (nX < n && nY < m && nX >= 0 && nY >= 0 && a[nX][nY] == '#' && visited[nX][nY] == 0 ){
      visited[nX][nY] = 1;
      Q.push({nX, nY});
    }
     nX = x, nY = y-1;
    if (nX < n && nY < m && nX >= 0 && nY >= 0 && a[nX][nY] == '#' && visited[nX][nY] == 0 ){
      visited[nX][nY] = 1;
      Q.push({nX, nY});
    }
     nX = x+1, nY = y;
    if (nX < n && nY < m && nX >= 0 && nY >= 0 && a[nX][nY] == '#' && visited[nX][nY] == 0 ){
      visited[nX][nY] = 1;
      Q.push({nX, nY});
    }
     nX = x-1, nY = y;
    if (nX < n && nY < m && nX >= 0 && nY >= 0 && a[nX][nY] == '#' && visited[nX][nY] == 0 ){
      visited[nX][nY] = 1;
      Q.push({nX, nY});
    }
  }
}

void sol(){
  cin >> n >> m;
  a = vector<string> (n);
  for (auto &i:a) cin >> i;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (a[i][j] == '#' && visited[i][j] == 0) {
        DFS(i, j);
        ans++;
      }
    }
  }
  cout << ans ;
  for (auto &[x, y]:save) cout << x << ' ' << y << '\n';

}

signed main() {
  // init();
  fastIO
  // run
    sol();
  
}