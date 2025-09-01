#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> edge;
const int MAX = 100000;
int N, K;
vector<int> mdistance(MAX + 1, INT_MAX);
vector<bool> visited(MAX + 1, false);
priority_queue<edge, vector<edge>, greater<edge>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    q.push({0, N});
    mdistance[N] = 0;

    while (!q.empty()) {
        edge cur = q.top(); q.pop();
        int x = cur.second;

        if (visited[x]) {
            continue;
        }
        visited[x] = true;

        int nx = x * 2;
        if (nx <= MAX && mdistance[nx] > mdistance[x]) {
            mdistance[nx] = mdistance[x];
            q.push({mdistance[nx], nx});
        }

        nx = x - 1;
        if (nx >= 0 && mdistance[nx] > mdistance[x] + 1) {
            mdistance[nx] = mdistance[x] + 1;
            q.push({mdistance[nx], nx});
        }

        nx = x + 1;
        if (nx <= MAX && mdistance[nx] > mdistance[x] + 1) {
            mdistance[nx] = mdistance[x] + 1;
            q.push({mdistance[nx], nx});
        }
    }

    cout << mdistance[K] << '\n';

    return 0;
}