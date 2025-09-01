#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;
int N, M;
static vector<int> mdistance;
static vector<bool> visited;
static vector<vector<edge>> mlist;
static priority_queue<edge, vector<edge>, greater<edge>> q;
static vector<int> parent;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    mdistance.resize(N + 1);
    visited.resize(N + 1);
    mlist.resize(N + 1);
    parent.resize(N + 1, -1);

    fill(mdistance.begin(), mdistance.end(), INT_MAX);
    fill(visited.begin(), visited.end(), false);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        mlist[u].push_back(make_pair(v, w));
    }

    int start, end;
    cin >> start >> end;

    q.push(make_pair(0, start));
    mdistance[start] = 0;

    while (!q.empty()) {
        edge current = q.top();
        q.pop();
        int c_v = current.second;

        if (visited[c_v]) {
            continue;
        }
        visited[c_v] = true;

        for (int i = 0; i < mlist[c_v].size(); i++) {
            edge tmp = mlist[c_v][i];
            int next = tmp.first;
            int value = tmp.second;

            if (mdistance[next] > mdistance[c_v] + value) {
                mdistance[next] = mdistance[c_v] + value;
                parent[next] = c_v;
                q.push(make_pair(mdistance[next], next));
            }
        }
    }

    vector<int> path;
    for (int v = end; ; v = parent[v]) {
        path.push_back(v);
        if (v == start) {
            break;
        }
    }

    cout << mdistance[end] << "\n";
    cout << path.size() << "\n";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << "\n";

    return 0;
}