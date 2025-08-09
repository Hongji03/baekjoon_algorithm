#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int MAX = 100000;
int N, K;  // N: 시작 위치 | K: 목표 위치
vector<int> dist(MAX + 1, INT_MAX);  // dist[i] = 시작점 N에서 i까지의 최소 시간
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;  // 최소 힙 (비용이 작은 순서로 pop) : pair<누적시간, 위치>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    dist[N] = 0;  // 시작 위치 초기화
    pq.push({0, N});  // 시간 0, 시작 위치 N

    while (!pq.empty()) {  // pq가 빌 때까지 반복
        int cost = pq.top().first;  // 현재까지의 누적 시간
        int x = pq.top().second;  // 현재 위치
        pq.pop();

        if (cost > dist[x]) continue;  // 이미 더 짧은 시간에 도달한 적이 있으면 스킵

        if (x == K) break;  // x가 목표 지점인 경우 최단 거리가 확정이므로 break

        // 0초 이동(순간이동(x -> 2x))
        int nx = x * 2;
        if (nx <= MAX && dist[nx] > cost) {
            dist[nx] = cost;  // 현재 시간 그대로 저장
            pq.push({dist[nx], nx});
        }

        // 1초 이동(뒤로 이동(x -> x-1))
        nx = x - 1;
        if (nx >= 0 && dist[nx] > cost + 1) {
            dist[nx] = cost + 1;
            pq.push({dist[nx], nx});
        }

        // 1초 이동(앞으로 이동(x -> x+1))
        nx = x + 1;
        if (nx <= MAX && dist[nx] > cost + 1) {
            dist[nx] = cost + 1;
            pq.push({dist[nx], nx});
        }
    }

    cout << dist[K] << '\n';

    return 0;
}