#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};  // 나이트 X방향 이동 8가지
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};  // 나이트 Y방향 이동 8가지

int T, I;  // T: 테스트 케이스 개수 | I: 체스판의 한 변의 길이
vector<vector<int>> visit;  // (y, x) 방문 여부
vector<vector<int>> dist;  // 목표 위치까지 이동하는 데 걸린 최소 이동 횟수

void BFS(int y, int x, int goalY, int goalX) {
    dist[y][x] = 0;  // 시작 지검 거리 0 | y, x -> 행, 열
	visit[y][x] = 1;  // 시작 지점 방문 처리
	
	queue<pair<int, int>> q;
	q.push({y, x});  // 시작 좌표 큐에 넣기

	while (!q.empty()) {
		int currentY = q.front().first;
		int currentX = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {  // 나이트 이동
			int ny = currentY + dy[i];
			int nx = currentX + dx[i];

			if (ny < 0 || ny >= I || nx < 0 || nx >= I) continue;  // 체스판 범위 넘으면 continue
			if (visit[ny][nx]) continue;  // 이미 방문한 곳이면 continue

			dist[ny][nx] = dist[currentY][currentX] + 1;  // 거리 업데이터 -> 이전 거리 + 1
			visit[ny][nx] = 1;  // 방문 처리
			q.push({ny, nx});  // 큐에 추가

			if (ny == goalY && nx == goalX) return;  // 목표 도달 시 종료
		}
	}
}

int main() {
    cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> I;
		visit.resize(I, vector<int>(I));  // I의 크기가 각 테스트 케이스마다 매번 달라지기 때문에 resize로 체스판 크기 동적으로 할당
		dist.resize(I, vector<int>(I));

		int curY, curX;
		int goalY, goalX;
		cin >> curY >> curX;
		cin >> goalY >> goalX;

		BFS(curY, curX, goalY, goalX);

		cout << dist[goalY][goalX] << endl;  // 목표 지점까지의 최소 이동 횟수 출력

		visit.clear();  // 다음 테스트 케이스를 위해 초기화
		dist.clear();  // 다음 테스트 케이스를 위해 초기화
	}

    return 0;
}