#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };  // 상하
int dy[4] = { 0, 0, -1, 1 };  // 좌우
int area[100][100];  // 지역
bool visited[100][100];  // 방문 여부
int N;  // 지역의 크기
int maxAreaH = 0;  // 지역의 최대 높이
int safezone = 0;  // 최대 안전 영역의 개수

void BFS(int x, int y, int h) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;  // 현재 좌표 방문 완료 표시

    while (!q.empty()) {
        auto current = q.front();  // 현재 좌표
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            // 현재 좌표에서 상하좌우로 이동할 새로운 좌표 계산
            int nx = current.first + dx[dir];  // 새로운 x 좌표
            int ny = current.second + dy[dir];  // 새로운 y 좌표

            // nx, ny -> 경계값 체크
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            // h값 넘기지 않으면 패스 = 침수된 지역이면 패스
            if (area[nx][ny] <= h) continue;
            // 이미 방문했으면 패스
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;  // 새로운 좌표 방문 완료 표시
            q.push({nx, ny});  // 현재 좌표를 큐에 넣음
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> area[i][j];
            if (maxAreaH < area[i][j]) {  // 현재까지의 지역 중 최대 높이를 maxAreaH에 저장
                maxAreaH = area[i][j];
            }
        }
    }

    for (int h = 0; h < maxAreaH; h++) {  // h를 0부터 지역 최대 높이까지 1씩 증가시키며 탐색
        memset(visited, false, sizeof(visited));  // 높이 증가할 때마다 visited 초기화

        int cnt = 0;  // 현재 침수 높이 h에서의 안전 영역 개수
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;  // 방문한 곳이 아닌 곳만 탐색
                if (area[i][j] <= h) continue;  // h보다 값이 큰 곳만 탐색
                BFS(i, j, h);  // 새로운 안전 영역 탐색
                cnt++;
            }
        }
        safezone = max(safezone, cnt);  // 최대값 저장
    }

    cout << safezone;

    return 0;
}