#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> edge;
int N, M, X;
vector<vector<edge>> mlist, rlist;

vector<int> dijkstra(const vector<vector<edge>>& g, int start) {
    vector<int> mdistance(N + 1, INT_MAX);
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

        for (int i = 0; i < (int)g[c_v].size(); i++) {
            edge tmp = g[c_v][i];
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

    cin >> N >> M >> X;

    mlist.assign(N + 1, {});
    rlist.assign(N + 1, {});

    for (int i = 0; i < M; ++i) {
        int a, b, t;
        cin >> a >> b >> t;

        mlist[a].push_back({b, t});
        rlist[b].push_back({a, t});
    }

    vector<int> fromX = dijkstra(mlist, X);
    vector<int> toX = dijkstra(rlist, X);

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        if (toX[i] == INT_MAX || fromX[i] == INT_MAX) {
            continue;
        }
        answer = max(answer, toX[i] + fromX[i]);
    }
    
    cout << answer << '\n';

    return 0;
}