#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[200001];

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool sameparent(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return true;
    else return false;
}

int main() {
    while(true) {
        int n, m;
        cin >> m >> n;
        if (m == 0 && n == 0) {
            break;
        }

        int result = 0;
        int maxAmount = 0;
        vector<pair<int, pair<int, int>>>v; 
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            maxAmount += z;

            v.push_back({z, {x, y}});
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < v.size(); i++) {
            if(!sameparent(v[i].second.first, v[i].second.second)) {
                uni(v[i].second.first, v[i].second.second);
                result += v[i].first;
            }
        }

        cout << maxAmount - result << '\n';
    }

    return 0;
}