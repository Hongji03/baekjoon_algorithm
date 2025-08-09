#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> edge;  // (누적비용, 정점)
const int INF = INT_MAX / 2;
int N;  // 동굴의 크기

// 2차원 좌표 (r, c)를 1차원 인덱스로 변환
inline int id(int r, int c, int n) { return r * n + c; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;  // 테스트케이스 번호
    while (true) {
        if (!(cin >> N)) return 0;  // 입력이 더 없으면 종료
        if (N == 0) break;  // N=0이면 반복 종료

        // 각 칸의 루피 비용 입력
        vector<vector<int>> rupee(N, vector<int>(N));
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                cin >> rupee[r][c];

        // 총 정점 수: N x N
        int V = N * N;
        vector<int> dist(V, INF);  // dist[i] = (0,0)에서 i까지의 최소 비용
        priority_queue<edge, vector<edge>, greater<edge>> pq;  // 최소 힙

        // 시작점 (0,0) 초기화: 시작 칸의 루피 비용 포함
        dist[id(0,0,N)] = rupee[0][0];
        pq.push({dist[id(0,0,N)], id(0,0,N)});

        // 4방향 이동 (상, 하, 좌, 우)
        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        // 다익스트라 탐색
        while (!pq.empty()) {
            int time = pq.top().first;  // 현재까지의 누적 비용
            int u    = pq.top().second;  // 현재 정점(1차원 인덱스)
            pq.pop();

            if (time > dist[u]) continue;  // 이미 더 짧은 경로로 방문했으면 스킵

            // 1차원 인덱스를 다시 (행, 열)로 변환
            int ur = u / N, uc = u % N;

            // 인접 4칸 확인
            for (int k = 0; k < 4; ++k) {
                int vr = ur + dr[k], vc = uc + dc[k];
                if (vr < 0 || vr >= N || vc < 0 || vc >= N) continue;  // 범위 밖이면 패스

                int v = id(vr, vc, N);  // 다음 칸의 인덱스
                int w = rupee[vr][vc];  // 다음 칸의 비용
                if (dist[v] > time + w) {  // 더 짧은 경로 발견 시 갱신
                    dist[v] = time + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // (N-1, N-1)까지의 최소 비용 출력
        cout << "Problem " << T++ << ": " << dist[id(N-1, N-1, N)] << '\n';
    }

    return 0;
}