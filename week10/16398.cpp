#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[1001];
long long cost[1001][1001];

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
    int N;
    cin >> N;

    long long result = 0;
	vector<pair<long long, pair<int, int>>>v; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v.push_back({cost[i][j], {i, j}});
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < v.size(); i++) {
        if(!sameparent(v[i].second.first, v[i].second.second)) {
            uni(v[i].second.first, v[i].second.second);
            result += v[i].first;
        }
    }

    cout << result << '\n';

    return 0;
}