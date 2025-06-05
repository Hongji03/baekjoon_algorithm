#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

vector<vector<int>> A;
vector<int> visited;
void DFS(int v);
void BFS(int v);

int main() {
    int N, M, V, s, e;
    cin >> N >> M >> V;

    A.resize(N + 1);
    visited = vector<int>(N + 1, 0);

    for (int i = 0; i < M; i++) {  // for all edges
        cin >> s >> e;
        A[s].push_back(e);  // undirected graph
        A[e].push_back(s);
    }

    for (int i = 1; i <= N; i++) {  // for all nodes
        sort(A[i].begin(), A[i].end());
    }

    DFS(V);
    cout << endl;

    visited = vector<int>(N + 1, -1);
    BFS(V);

    return 0;
}

void DFS(int v) {
    if (visited[v]) return;  // 종결 조건
    visited[v] = true;
    cout << v << " ";
    for (int i : A[v]) {
        // 연결 노드 중 방문하지 않은 노드만 탐색
        if (visited[i] == false) {
            DFS(i);
        }
    }
}

void BFS(int v) {
    queue<int> q;
    q.push(v);
    visited[v]++;

    while (!q.empty()) {
        int newn = q.front();
        q.pop();
        cout << newn << " ";
        for (int i : A[newn]) {
            if (visited[i] == -1) {
                visited[i] = visited[newn] + 1;
                q.push(i);
            }
        }
    }
}