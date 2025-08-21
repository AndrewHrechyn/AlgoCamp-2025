#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

vector<int> manacher(const string &s) {
    string t = "#";
    for (char c : s) {
        t.push_back(c);
        t.push_back('#');
    }
    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;

    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;
        if (i < right)
            p[i] = min(right - i, p[mirror]);

        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
               t[i - p[i] - 1] == t[i + p[i] + 1]) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> p = manacher(s);

    string t = "#";
    for (char c : s) {
        t.push_back(c);
        t.push_back('#');
    }
    int m = t.size();

    int pref = 0, suff = 0;
    for (int i = 0; i < m; i++) {
        int rad = p[i];
        int L = i - rad, R = i + rad;
        if (L == 0) {
            pref = max(pref, (R - L) / 2);
        }
        if (R == m - 1) {
            suff = max(suff, (R - L) / 2);
        }
    }

    int ans = n - max(pref, suff);
    cout << ans << "\n";
    return 0;
}
