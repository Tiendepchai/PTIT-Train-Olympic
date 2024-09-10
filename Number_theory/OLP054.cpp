#include <iostream>
#include <vector>
#include <algorithm>
#define int long long 

using namespace std;

void smallestNumber(int P) {
    if (P ==1 ) { cout << P << '\n'; return ;} 

    vector<int> digits;
    for (int d = 9; d > 1; --d) {
        while (P % d == 0) {
            P /= d;
            digits.push_back(d);
        }
    }

    if (P != 1) { cout << "-1\n"; return ;}
    sort(digits.begin(), digits.end());

    int result = 0;
    for (int digit : digits) {
      cout <<  digit;
    }
    cout << '\n';
}

signed main() {
    int T;
    // cout << "Nhap so luong bo test T: ";
    cin >> T;
    while (T--) {
        long long P;
        cin >> P;
        smallestNumber(P);
        cout << '\n';
    }
    return 0;
}
