#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge; // 간선 정보 (비용, 도착도시)
int N, M;  // N: 도시의 개수 | M: 버스(간선)의 개수
vector<vector<edge>> graph;  // 인접 리스트: graph[u] = { (v, w), ... }
vector<int> dist;  // 시작 도시로부터의 최소 비용 저장 배열

int dijkstra(int start, int end) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;  // 최소 힙 (비용이 작은 순으로 우선)
    dist[start] = 0;  // 시작 도시는 비용 0
    pq.push({0, start});  // (비용, 도시) 형태로 pq에 push

    while (!pq.empty()) {  // pq가 비어있지 않은 경우만 반복
        int curr_cost = pq.top().first;  // 현재까지의 비용
        int curr = pq.top().second;  // 현재 도시
        pq.pop();

        if (dist[curr] < curr_cost) continue;  // 이미 더 짧은 경로로 방문된 경우 pass

        for (auto& e : graph[curr]) {  // 현재 도시와 연결된 모든 인접 도시 탐색
            int next = e.first;  // 다음 도시
            int cost = e.second;  // 현재 도시에서 다음 도시까지의 비용

            if (dist[next] > dist[curr] + cost) {  // 더 짧은 경로를 찾은 경우 갱신
                dist[next] = dist[curr] + cost;
                pq.push({dist[next], next});
            }
        }
    }
    return dist[end];  // 도착 도시까지의 최소 비용 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    graph.resize(N + 1);   // 도시 번호가 1부터 시작하므로 N+1 크기로 초기화
    dist.assign(N + 1, INT_MAX);  // 모든 거리를 무한대(INT_MAX)로 초기화

    for (int i = 0; i < M; i++) {  // 버스(간선) 정보 입력
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start, end;
    cin >> start >> end;  // 출발 도시와 도착 도시 입력

    cout << dijkstra(start, end) << "\n";  // 최소 비용 출력
    return 0;
}