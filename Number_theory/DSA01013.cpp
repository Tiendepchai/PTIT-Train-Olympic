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
const int pr = 1e3;

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

char flip(char c) {
  return (c == '0') ? '1' : '0';
}

string grayToBinary(string gray) {
  string binary = "";
  binary += gray[0]; // The first bit is the same

  // Process the rest of the bits
  for (int i = 1; i < gray.length(); i++) {
    if (gray[i] == '0') {
        binary += binary[i - 1];
    } else {
        binary += flip(binary[i - 1]);
    }
  }
  return binary;
}

void sol(){
  string s; cin >> s;
  cout << grayToBinary(s) << '\n';
}

signed main() {
  // init();
  fastIO
  run
    sol();
  
}