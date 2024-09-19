#include <iostream>
#include <vector>
using namespace std;
#define int int64_t

const int mod = 1000000000019;

int mul(int a, int b){
  if (b == 0) return 0;
  if (b == 1) return a;
  int temp = mul(a, b/2);
  if (b&1) return (temp + temp + a)%mod;
  else return (temp + temp)% mod;
}

class matrix{
  public:
    int row, col;
    vector<vector<int>> arr;
    matrix(int row, int col) : row(row), col(col) {
      arr.resize(row, vector<int>(col, 0));
    }
    matrix operator * (matrix const& obj){
      matrix res(row, obj.col);
      for (int x = 0; x < row; x++){
        for (int y = 0; y < res.col; y++){
          for (int z = 0; z < res.col; z++){
            res.arr[x][y] = (res.arr[x][y]%mod + mul(arr[x][z], obj.arr[z][y])%mod)%mod;
          }
        }
      }
      return res;
    }
    matrix operator+ (matrix const& obj){
      matrix res(this->row, obj.col);
      for (int x = 0; x < row; x++){
        for (int y = 0; y < res.col; y++){
          res.arr[x][y] = (res.arr[x][y] + arr[x][y]%mod + obj.arr[x][y]%mod)%mod;
        }
      }
      return res;
    }
};

matrix a(2, 2);

matrix fast_power(matrix const &aa, int n){
  if (n == 1) return aa;   
  matrix tmp = fast_power(aa, n/2);
  return (n&1?tmp*tmp*a:tmp*tmp);
}

void sol(){
  int n; cin >> n;
  auto base = fast_power(a, n);
  cout << base.arr[0][0] << '\n';
}

signed main()
{
  int t;
  a.arr[0][0] = a.arr[0][1] = a.arr[1][0] = 1;
  for (cin >> t; t--;) sol();
}