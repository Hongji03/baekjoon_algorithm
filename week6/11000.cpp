#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;  // N: 수업(강의)의 개수

int main () {
    cin >> N;

    vector<pair<int, int>> time(N);
    for (int i = 0; i < N; i++) {  // 강의의 시간을 저장
        cin >> time[i].first >> time[i].second;
    }

    sort(time.begin(), time.end());  // 시작 시간 기준 정렬

    priority_queue<int, vector<int>, greater<int>> pq;  // 우선순위 큐: 현재 강의실들 중 가장 빨리 끝나는 수업 시간을 top에 저장

    pq.push(time[0].second);  // 첫 수업은 무조건 하나의 강의실에 배정후 끝나는 시간을 큐에 삽입

    for (int i = 1; i < N; i++) {
        if (pq.top() <= time[i].first) {  // 이전에 끝난 수업이 현재 수업 시작 전이면 -> 같은 강의실 사용
            pq.pop();  // 해당 강의실 제거 -> 강의실 재사용
        }
        pq.push(time[i].second);  // 현재 수업의 종료 시간을 큐에 삽입
    }

    cout << pq.size();  // 필요한 최소 강의실 수

    return 0;
}