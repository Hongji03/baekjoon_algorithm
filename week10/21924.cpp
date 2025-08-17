#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[100001];

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
    int N, M;
    cin >> N >> M;

    long long result = 0;
    long long total = 0;
    vector<pair<long long, pair<int, int>>>v; 
    for (int i = 0; i < M; i++) {
        int x, y;
        long long z;
        cin >> x >> y >> z;
        total += z;

        v.push_back({z, {x, y}});
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if(!sameparent(v[i].second.first, v[i].second.second)) {
            uni(v[i].second.first, v[i].second.second);
            result += v[i].first;
            cnt++;
            if (cnt == N - 1) {
                break;
            }
        }
    }

    if (cnt != N - 1) {
        cout << -1 << '\n';
    } else {
        cout << total - result << '\n';
    }

    return 0;
}