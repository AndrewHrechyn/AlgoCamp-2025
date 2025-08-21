#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;

    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> dp(n, 0);

    dp[0] = a[0];

    for(int i = 0; i < n; i++){

    }



   return 0;
}
