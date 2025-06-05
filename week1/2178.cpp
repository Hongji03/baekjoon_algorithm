#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M;
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1, 1 };
int Map[101][101];  // 미로
bool visited[101][101];

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 범위 확인 + 갈 수 있는 칸 + 방문 안 했는지
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && Map[nx][ny] == 1 && !visited[nx][ny]) {
                q.push({ nx, ny });
                visited[nx][ny] = true;
                Map[nx][ny] = Map[cx][cy] + 1;  // 누적 거리 저장
            }
        }
    }
}

int main() {
    cin >> N >> M;
    
    for (int i = 1; i < N + 1; i++) {
        string line;
        cin >> line;
        for (int j = 1; j < M + 1; j++) {
            Map[i][j] = line[j - 1] - '0';  // '1' → 1, '0' → 0
        }
    }
    BFS(1, 1);
    cout << Map[N][M] << endl;  // 도착 지점의 거리 출력

    return 0;
}