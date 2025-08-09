#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> edge;  // (누적시간, 정점)

int N, M, X;  // N: 마을 개수 | M: 도로 개수 | X: 파티가 열리는 마을 번호
vector<vector<pair<int,int>>> graph;  // 원본 그래프: u -> v (시간 w)
vector<vector<pair<int,int>>> rgraph;  // 역방향 그래프: v -> u (시간 w)

// 다익스트라 알고리즘: start에서 모든 정점까지의 최단 시간 반환
vector<int> dijkstra(const vector<vector<pair<int,int>>>& g, int start) {
    const int INF = INT_MAX;
    vector<int> dist(N + 1, INF);  // dist[i] = start에서 i까지의 최단 시간
    priority_queue<edge, vector<edge>, greater<edge>> pq; // 최소 힙 (시간 오름차순)

    dist[start] = 0;
    pq.push({0, start});  // (시간 0, 시작 정점)

    while (!pq.empty()) {
        int time = pq.top().first;  // 현재까지 걸린 시간
        int u = pq.top().second;  // 현재 정점
        pq.pop();

        if (time > dist[u]) continue;  // 더 짧은 시간이 이미 기록되어 있다면 스킵

        for (const auto& e : g[u]) {  // 현재 정점과 연결된 모든 간선 확인
            int v = e.first;  // 다음 정점
            int w = e.second;  // 이동 시간
            if (dist[v] > time + w) {  // 더 짧은 경로를 발견하면
                dist[v] = time + w;  // 갱신
                pq.push({dist[v], v});  // 우선순위 큐에 push
            }
        }
    }
    return dist;  // start에서 각 정점까지의 최단 시간
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> X;
    graph.assign(N + 1, {});  // 1~N번 마을
    rgraph.assign(N + 1, {});  // 1~N번 마을

    for (int i = 0; i < M; ++i) {  // 단방향 도로 입력 처리
        int a, b, t;  // a -> b, 소요시간 t
        cin >> a >> b >> t;
        graph[a].push_back({b, t});  // 원본 방향 저장
        rgraph[b].push_back({a, t});  // 역방향 저장
    }

    // X → i (파티 → 집) 최단 시간
    vector<int> fromX = dijkstra(graph, X);
    // i → X (집 → 파티) 최단 시간 == 역방향 그래프에서 X 시작
    vector<int> toX = dijkstra(rgraph, X);

    int answer = 0;
    for (int i = 1; i <= N; ++i) {  // 모든 마을의 왕복 시간 계산
        if (toX[i] == INT_MAX || fromX[i] == INT_MAX) continue;  // 도달 불가 시 스킵
        answer = max(answer, toX[i] + fromX[i]);  // 최대 왕복 시간 갱신
    }

    cout << answer << '\n';

    return 0;
}