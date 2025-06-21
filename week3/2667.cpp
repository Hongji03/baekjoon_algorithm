#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };  // 상하
int dy[4] = { 0, 0, -1, 1 };  // 좌우
int village[25][25];  // 마을
bool visited[25][25];  // 방문 여부
int N;  // 마을의 크기

int BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;  // 현재 좌표 방문 완료 표시

    int area = 1; // 현재 집의 개수

    while (!q.empty()) {
        auto current = q.front();  // 현재 좌표
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            // 현재 좌표에서 상하좌우로 이동할 새로운 좌표 계산
            int nx = current.first + dx[dir];  // 새로운 x 좌표
            int ny = current.second + dy[dir];  // 새로운 y 좌표

            // nx, ny -> N, M 경계값 체크
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue; 
            // 이미 방문했거나 0이 나오면 패스
            if (visited[nx][ny] || village[nx][ny] == 0) continue;

            visited[nx][ny] = true;  // 새로운 좌표 방문 완료 표시
            q.push({nx, ny});  // 현재 좌표를 큐에 넣음
            area++;
        }
    }

    return area;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string line;  // 공백 입력이 아니기 때문에 문자열로 받아서 문제로 변환 후 숫자로 바꿔주어야 함
        cin >> line;
        for (int j = 0; j < N; j++) {
            village[i][j] = line[j] - '0';  // 문자를 숫자로 변환
        }
    }

    int cnt = 0;
    vector<int> aptComplex;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (village[i][j] == 1 && !visited[i][j]) {  // 방문한 그림이 아니고 1인 곳만 탐색
                int area = BFS(i, j);
                cnt++;
                aptComplex.push_back(area);  // 단지의 크기 저장
            }
        }
    }

    sort(aptComplex.begin(), aptComplex.end());  // 단지의 넓이 오름차순 정렬

    cout << cnt << endl;
    for (int i = 0; i < aptComplex.size(); i++) {  // 각 단지의 넓이 출력
        cout << aptComplex[i] << endl;
    }

    return 0;
}