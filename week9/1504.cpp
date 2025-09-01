#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> edge;
static int N, E;
static vector<vector<edge>> mlist;

vector<int> dijkstra(int start) {
    vector<int> mdistance(N + 1, INT_MAX / 2);
    vector<bool> visited(N + 1, false);
    priority_queue<edge, vector<edge>, greater<edge>> q;

    mdistance[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        edge current = q.top(); q.pop();
        int c_v = current.second;

        if (visited[c_v]) {
            continue;
        }
        visited[c_v] = true;

        for (int i = 0; i < (int)mlist[c_v].size(); i++) {
            edge tmp = mlist[c_v][i];
            int next = tmp.first;
            int value = tmp.second;

            if (mdistance[next] > mdistance[c_v] + value) {
                mdistance[next] = mdistance[c_v] + value;
                q.push({mdistance[next], next});
            }
        }
    }

    return mdistance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> E;

    mlist.assign(N + 1, {});

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        mlist[a].push_back({b, c});
        mlist[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> d1 = dijkstra(1);
    vector<int> dv1 = dijkstra(v1);
    vector<int> dv2 = dijkstra(v2);

    long long INF = (long long)INT_MAX / 2;
    long long path1 = (long long)d1[v1] + dv1[v2] + dv2[N];
    long long path2 = (long long)d1[v2] + dv2[v1] + dv1[N];
    long long answer = min(path1, path2);

    if (answer >= INF) {
        cout << -1 << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}