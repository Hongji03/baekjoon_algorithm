#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[100001];
int lanCable[52][52];

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

    int total = 0;
    int result = 0;
    vector<pair<int, pair<int, int>>>v; 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char s;
            cin >> s;
            
            int cost = 0;
            if ('a' <= s && s <= 'z') {
                cost = s - 'a' + 1;
            } else if ('A' <= s && s <= 'Z') {
                cost = s - 'A' + 27;
            }

            total += cost;
            if (cost > 0 && i != j) {
                v.push_back({cost, {i, j}});
            }
        }
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