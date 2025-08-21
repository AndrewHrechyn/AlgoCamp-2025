#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

vector<int> depth;
vector<vector<int>> parent;
int LOG = 20;

void connect(int a) {
    int new_node = depth.size();
    depth.push_back(depth[a] + 1);
    parent.push_back(vector<int>(LOG, 0));
    
    parent[new_node][0] = a;
    for (int i = 1; i < LOG; i++) {
        parent[new_node][i] = parent[parent[new_node][i-1]][i-1];
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    
    int dist = 0;
    
    int diff = depth[a] - depth[b];
    dist += diff;
    
    for (int i = 0; i < LOG; i++) {
        if ((diff >> i) & 1) {
            a = parent[a][i];
        }
    }
    
    if (a == b) {
        return dist;
    }
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
            dist += 2 * (1 << i);
        }
    }
    
    dist += 2;
    
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;
    
    depth.push_back(0);
    parent.push_back(vector<int>(LOG, 0));
    
    int x = 0;
    
    while (q--) {
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            int a;
            cin >> a;
            a ^= x;
            connect(a - 1); 
        }
        else {
            int a, b;
            cin >> a >> b;
            a ^= x;
            b ^= x;
            x = lca(a - 1, b - 1); 
            cout << x << "\n";
        }
    }
    
    return 0;
}
