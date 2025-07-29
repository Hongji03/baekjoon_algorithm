#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair<int, int> edge;  // (정점 번호, 가중치) pair로 묶은 edge
static int V, E, K;  // V: 정점 수 | E: 간선 수 | K: 시작 정점
static vector<int> mdistance;  // 시작 정점으로부터의 최단 거리 저장 배열
static vector<bool> visited;  // 방문 여부 확인 배열
static vector<vector<edge>> mlist;  // 인접리스트: mlist[u] = (v, w) 리스트
static priority_queue<edge, vector<edge>, greater<edge>> q;  // 최소 힙 - 거리 기준 오름차순

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> K;

    // 정점 번호가 1부터 시작하므로 각 벡터들의 크기를 V+1로 조정
    mdistance.resize(V + 1);
    visited.resize(V + 1);
    mlist.resize(V + 1);

    fill(mdistance.begin(), mdistance.end(), INT_MAX);  // 벡터의 모든 요소를 INT_MAX로 채우기
    fill(visited.begin(), visited.end(), false);  // 다 미방문 처리

    for (int i = 0; i < E; i++) {  // 가중치가 있는 인접리스트 초기화
        int u, v, w;
        cin >> u >> v >> w;
        mlist[u].push_back(make_pair(v, w));  // 간선 정보 입력 받아 벡터에 값 저장
    }

    q.push(make_pair(0, K));  // (거리, 정점) 형식으로 시작 정점을 큐에 삽입
    mdistance[K] = 0;  // 시작 정점의 거리는 0

    while (!q.empty()) {
        edge current = q.top();
        q.pop();
        int c_v = current.second;  // 현재 방문할 정점 번호

        if (visited[c_v]) {  // 이미 방문한 노드는 다시 큐에 넣지 않음
            continue;
        }
        visited[c_v] = true;

        for (int i = 0; i < mlist[c_v].size(); i++) {  // 현재 정점과 연결된 인접 정점들을 확인
            edge tmp = mlist[c_v][i];
            int next = tmp.first;  // 다음 정점
            int value = tmp.second;  // 간선 가중치

            if (mdistance[next] > mdistance[c_v] + value) {  // 현재까지의 최소 거리보다 더 짧은 경로가 나오면 업데이트
                mdistance[next] = value + mdistance[c_v];
                q.push(make_pair(mdistance[next], next));  // 갱신된 거리와 함께 우선순위 큐에 삽입
            }
        }
    }

    for (int i = 1; i <= V; i++) {  // 거리 배열 출력
        if (visited[i]) {  // 방문한 정점이면 최단 거리 출력
            cout << mdistance[i] << "\n";
        } else {
            cout << "INF" << "\n";
        }
    }
}