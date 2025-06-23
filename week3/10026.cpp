#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };  // 상하
int dy[4] = { 0, 0, -1, 1 };  // 좌우
char noRG[100][100];     // 일반인 기준 그림
char yesRG[100][100];    // 적록색맹 기준 그림
bool visited[100][100];  // 방문 여부
int N;  // 그림의 크기

void BFS(int x, int y, char board[100][100]) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;  // 현재 좌표 방문 완료 표시

    char color = board[x][y];  // 현재 컬러값 저장

    while (!q.empty()) {
        auto current = q.front();  // 현재 좌표
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            // 현재 좌표에서 상하좌우로 이동할 새로운 좌표 계산
            int nx = current.first + dx[dir];  // 새로운 x 좌표
            int ny = current.second + dy[dir];  // 새로운 y 좌표

            // nx, ny -> N 경계값 체크
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue; 
            // 이미 방문했거나 0이 나오면 패스
            if (visited[nx][ny]) continue;
            // 같은 컬러값이 아니면 패스
            if (board[nx][ny] != color) continue;

            visited[nx][ny] = true;  // 새로운 좌표 방문 완료 표시
            q.push({nx, ny});  // 현재 좌표를 큐에 넣음
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            noRG[i][j] = line[j];

            // 적록색맹은 R과 G를 같은 색으로 인식
            if (line[j] == 'G') {
                yesRG[i][j] = 'R';
            } else {
                yesRG[i][j] = line[j];
            }
        }
    }

    int yesRGCnt = 0;  // 적록색맹 기준 구역 개수
    int noRGCnt = 0;  // 일반인 기준 구역 개수
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {  // 방문한 그림이 아닌 곳만 탐색
                BFS(i, j, noRG);
                noRGCnt++;
            }
        }
    }

    for (int i = 0; i < N; i++) {  // visited 배열 초기화
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                BFS(i, j, yesRG);
                yesRGCnt++;
            }
        }
    }

    cout << noRGCnt << " " << yesRGCnt << endl;

    return 0;
}