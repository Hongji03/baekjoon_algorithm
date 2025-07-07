#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> tree[10001];  // 인접 노드, 거리
bool visited[10001];  // 방문 여부

int maxDist = 0;  // 최대 거리 저장
int farNode = 0;  // 가장 멀리 있는 노드

// DFS로 가장 먼 노드와 거리 찾기
void DFS(int node, int dist) {
    visited[node] = true;

    if (dist > maxDist) {  // 가장 먼 거리 갱신
        maxDist = dist;
        farNode = node;
    }

    for (auto edge : tree[node]) {  // 현재 노드와 연결된 모든 간선을 탐색하면서 next 노드와 거리 weight를 꺼냄
        int next = edge.first;
        int weight = edge.second;
        if (!visited[next]) {  // 방문하지 않은 노드일 때만!
            DFS(next, dist + weight);  // 누적 거리르 계산해서 DFS 실행
        }
    }
}

int main() {
    int n;
    cin >> n;

    // 트리 입력 받기
    for (int i = 0; i < n - 1; i++) {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].push_back({child, weight});
        tree[child].push_back({parent, weight});  // 양방향 연결
    }

    // 루트 노드에서 시작해서 가장 먼 노드 찾기
    DFS(1, 0);

    // 찾은 노드(farNode)에서 다시 DFS 수행
    memset(visited, false, sizeof(visited));  // 방문 초기화
    maxDist = 0;
    DFS(farNode, 0);

    cout << maxDist << '\n';  // 트리의 지름 출력
    return 0;
}