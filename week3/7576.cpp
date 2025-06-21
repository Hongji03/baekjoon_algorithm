#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };  // 상하
int dy[4] = { 0, 0, -1, 1 };  // 좌우
int box[1000][1000];  // 상자
int M, N;  // 상자의 가로, 세로 길이
queue<pair<int, int>> q;

void BFS() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;  // 상자 범위 안인지 확인
            if (box[nx][ny] == 0) {
                box[nx][ny] = box[x][y] + 1;  // 날짜 증가
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push({i, j});  // 익은 토마토는 BFS 시작점으로 미리 넣기
            }
        }
    }

    BFS();
    
    int day = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            day = max(day, box[i][j]);
        }
    }

    cout << day - 1 << '\n';  // 처음에 1부터 시작했으므로 -1

    return 0;
}