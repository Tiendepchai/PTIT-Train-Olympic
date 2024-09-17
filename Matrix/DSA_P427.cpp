#include <iostream>
#include <vector>
using namespace std;
#define int long long

const int mod = 1e15+7;

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
    void show(){
      for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
          cout << arr[i][j] << ' ';
        }
        cout << '\n';
      }
    }
};

matrix fast_power(matrix const &aa, int n){
  if (n == 1) return aa;   
  matrix tmp = fast_power(aa, n/2);
  return (n&1?tmp*tmp*aa:tmp*tmp);
}

matrix a(3, 3), ans(3, 3), base(3, 3);

signed main()
{
  int n; cin >> n;
  a.arr[0][0] = a.arr[0][1] = a.arr[0][2] = a.arr[1][0] = a.arr[2][1] = 1;
  while (n--)
  {
    int k; cin >> k;
    cout << (fast_power(a, k).arr[0][1]%mod + fast_power(a, k+2).arr[0][1]%mod)/2 - 1 << '\n';
    
  }
  
}