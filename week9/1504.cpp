#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> edge;  // (누적시간, 정점)
const int INF = INT_MAX / 2;

int N, E;  // N: 정점 개수 | E: 간선 개수
vector<vector<pair<int,int>>> graph;  // 인접 리스트: graph[u] = { (v, 가중치) }

// 다익스트라 알고리즘: start에서 모든 정점까지의 최단 거리 계산
vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF);  // dist[i] = start에서 i까지의 최단 시간
    priority_queue<edge, vector<edge>, greater<edge>> pq;  // 최소 힙

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int time = pq.top().first;  // 현재까지 걸린 시간
        int u    = pq.top().second;  // 현재 정점
        pq.pop();

        if (time > dist[u]) continue;  // 이미 더 짧은 경로로 방문한 적이 있으면 스킵

        // 현재 정점과 연결된 모든 간선 확인
        for (const auto& e : graph[u]) {
            int v = e.first;  // 다음 정점
            int w = e.second;  // 가중치
            if (dist[v] > time + w) {  // 더 짧은 경로를 발견하면 갱신
                dist[v] = time + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> E;
    graph.assign(N + 1, {});  // 1~N 정점 크기로 초기화

    for (int i = 0; i < E; ++i) {  // 무방향 그래프 입력 처리
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int v1, v2;  // 반드시 거쳐야 하는 두 정점
    cin >> v1 >> v2;

    // 필요한 출발점에서 다익스트라 실행
    vector<int> d1  = dijkstra(1);  // 1번에서 시작
    vector<int> dv1 = dijkstra(v1);  // v1에서 시작
    vector<int> dv2 = dijkstra(v2);  // v2에서 시작

    // 경로 1: 1 -> v1 -> v2 -> N
    long long path1 = (long long)d1[v1] + dv1[v2] + dv2[N];
    // 경로 2: 1 -> v2 -> v1 -> N
    long long path2 = (long long)d1[v2] + dv2[v1] + dv1[N];

    long long ans = min(path1, path2);  // 두 경로 중 최소값 선택

    if (ans >= INF) {  // 어느 구간이라도 불가능하면 
        cout << -1 << '\n';  // -1 출력
    } else {
        cout << ans << '\n';  // 최단 경로 출력
    }

    return 0;
}