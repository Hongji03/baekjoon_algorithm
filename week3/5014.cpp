#include <iostream>
#include <queue>
using namespace std;

int visited[1000001] = {};  // 방문 여부
int F, S, G, U, D;  // 건물의 층
// F: 건물의 총 높이 | S: 강호가 있는 층 | G: 스타트링크가 있는 층 | U: 위로 U층 이동 | D: 아래로 D층 이동

int BFS() {
    queue<int> q;
    visited[S] = 1;  // 시작 층 방문 표시
    q.push(S);

    while (!q.empty()) {
        int current = q.front();  // 현재 층
        q.pop();
        if (current == G) {  // G층에 도달한 경우 현재까지 누른 버튼 횟수 반환
            return visited[G];
        }

        int up = current + U;
        int down = current - D;

        if (up <= F && !visited[up]) {  // 위로 이동 가능하고 방문하지 않은 층인 경우
            visited[up] = visited[current] + 1;  // 버튼 횟수 저장
            q.push(up);
        }

        if (down > 0 && !visited[down]) {  // 아래로 이동 가능하고 방문하지 않은 층인 경우
            visited[down] = visited[current] + 1;  // 버튼 횟수 저장
            q.push(down);
        }
    }

    // 스타트링크가 있는 층으로 이동할 수 없을 때
    return -1;
}

int main() {
    cin >> F >> S >> G >> U >> D;

    int minCnt = BFS();

    if (minCnt == -1) {
        cout << "use the stairs";
    } else {
        cout << minCnt - 1;  // 시작할 때 버튼 횟수를 1로 초기화 했기 때문에 최종 버튼 횟수는 하나를 빼줘야 함
    }

    return 0;
}