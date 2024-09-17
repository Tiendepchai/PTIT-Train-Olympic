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

vector<int> dp(51);

signed main(){
  int t, n;
  dp[1] = 1; dp[2] = 2; dp[3] = 4; 
  for (cin >>t; t--;){
    cin >> n;
    for (int i = 4; i <= n; i++){
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    cout << dp[n] << '\n';
  }
}