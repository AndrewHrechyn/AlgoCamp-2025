#include <iostream>

using namespace std;
using int64 = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n, u, d;
    cin >> n >> u >> d;

    i128 ans = 0;
    int64 i = 1;

    if(u == d){
        cout << n;
    }
    else if(u < d){
        cout << 0;
    }
    else{
      while (i <= n) {
        int64 q = (u + i) / (d + i);

        if (q == 0) {
            break;
        }
        int64 R;
        if (q == 1) {
            R = n;
        } else {
            R = (u - q * d) / (q - 1);
            if (R > n) R = n;
        }

        if (R < i) R = i; 

        ans += (i128)q * (R - i + 1);
        i = R + 1;
    }

    cout << (long long)ans << "\n";  
    }

    return 0;
}

