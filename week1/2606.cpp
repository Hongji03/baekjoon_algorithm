#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int infected = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                infected++;
                q.push(next);
            }
        }
    }

    return infected;
}

int main() {
    int com, pair;
    cin >> com;
    cin >> pair;

    graph.resize(com + 1);
    visited.resize(com + 1, false);

    for (int i = 0; i < pair; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= com; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    cout << BFS(1) << endl;
    
    return 0;
}