#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };  // 상하
int dy[4] = { 0, 0, -1, 1 };  // 좌우
int paintings[500][500];  // 도화지
bool visited[500][500];  // 방문 여부
int N, M;  // 도화지의 크기

int BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;  // 현재 좌표 방문 완료 표시

    int area = 1; // 현재 그림 넓이

    while (!q.empty()) {
        auto current = q.front();  // 현재 좌표
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            // 현재 좌표에서 상하좌우로 이동할 새로운 좌표 계산
            int nx = current.first + dx[dir];  // 새로운 x 좌표
            int ny = current.second + dy[dir];  // 새로운 y 좌표

            // nx, ny -> N, M 경계값 체크
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue; 
            // 이미 방문했거나 0이 나오면 패스
            if (visited[nx][ny] || paintings[nx][ny] == 0) continue;

            visited[nx][ny] = true;  // 새로운 좌표 방문 완료 표시
            q.push({nx, ny});  // 현재 좌표를 큐에 넣음
            area++;
        }
    }

    return area;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paintings[i][j];
        }
    }

    int cnt = 0;
    int maxArea = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (paintings[i][j] == 1 && !visited[i][j]) {  // 방문한 그림이 아니고 1인 곳만 탐색
                int area = BFS(i, j);
                cnt++;
                maxArea = max(maxArea, area);
            }
        }
    }

    cout << cnt << "\n" << maxArea;

    return 0;
}