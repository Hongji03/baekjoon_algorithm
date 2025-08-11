#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;  // (누적비용, 도시)
int N, M;  // N: 도시 수 | M: 버스(간선) 수
vector<vector<edge>> graph;  // 인접 리스트: graph[u] = { (v, w), ... }
vector<int> dist;  // 시작 도시로부터의 최소 비용 저장
vector<int> prev_city;  // 경로 복원용: prev_city[v] = v로 오기 직전 도시

// 다익스트라 알고리즘: start에서 end까지 최소 비용 계산
int dijkstra(int start, int end) {
    priority_queue<edge, vector<edge>, greater<edge>> pq; // 최소 힙
    dist.assign(N + 1, INT_MAX);  // 모든 거리를 무한대로 초기화
    prev_city.assign(N + 1, -1);  // 이전 도시 정보 초기화

    dist[start] = 0;
    pq.push({0, start});  // (비용 0, 시작 도시)

    while (!pq.empty()) {
        int curr_cost = pq.top().first;  // 현재까지의 비용
        int curr = pq.top().second;  // 현재 도시
        pq.pop();

        if (curr_cost > dist[curr]) continue;  // 이미 더 짧은 경로로 방문한 적이 있으면 스킵

        for (auto &e : graph[curr]) {  // 현재 도시와 연결된 모든 인접 도시 확인
            int next = e.first;  // 다음 도시
            int cost = e.second;  // 현재 도시 → 다음 도시 비용

            if (dist[next] > dist[curr] + cost) {  // 더 짧은 경로를 발견한 경우
                dist[next] = dist[curr] + cost;  // 거리 갱신
                prev_city[next] = curr;  // 경로 복원을 위해 이전 도시 기록
                pq.push({dist[next], next});
            }
        }
    }
    return dist[end];  // end까지의 최소 비용 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.assign(N + 1, {});  // 도시 번호 1부터 시작
    dist.assign(N + 1, INT_MAX);
    prev_city.assign(N + 1, -1);

    for (int i = 0; i < M; ++i) {  // 버스 정보 입력
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start, end;
    cin >> start >> end;  // 출발 도시와 도착 도시 입력

    int min_cost = dijkstra(start, end);  // 최소 비용 계산

    // 경로 복원: end에서 start까지 prev_city를 따라가며 역순 저장
    vector<int> path;
    for (int cur = end; cur != -1; cur = prev_city[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());  // start → end 순서로 변경

    cout << min_cost << '\n';  // 최소 비용 출력
    cout << path.size() << '\n';  // 경로에 포함된 도시 개수
    for (int i = 0; i < (int)path.size(); ++i) {
        cout << path[i] << (i + 1 == (int)path.size() ? '\n' : ' ');
    }

    return 0;
}