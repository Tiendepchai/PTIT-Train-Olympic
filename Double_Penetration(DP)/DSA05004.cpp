#include <iostream>
#include <vector>
using namespace std;
#define int int64_t

const int mod = 1e9+7;

int mul(int a, int b){
  if (b == 0) return 0;
  if (b == 1) return a;
  int temp = mul(a, b/2);
  if (b&1) return (temp + temp + a)%mod;
  else return (temp + temp)% mod;
}

vector<int> dp(1005, 1), a(1005);

signed main(){
  int n; cin >> n;
  for (int i = 1; i <=n; i++) cin >> a[i];
  int ans = 1;
  for (int i = 1; i <= n; i++){
    for (int j = i - 1; j >= 1; j--){
      if (a[i] > a[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
      ans = max(ans, dp[i]);
    }
  }
  cout << ans;
}