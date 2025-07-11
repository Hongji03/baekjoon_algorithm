#include <iostream>
#include <algorithm>
using namespace std;

int N;  // 회의의 개수
pair<int, int> I[100001];  // 각 회의 정보

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {  // 회의 정보 입력
        cin >> I[i].first >> I[i].second;
    }

    sort(I, I + N, [](pair<int, int> a, pair<int, int> b) {  // 끝나는 시간을 기준으로 오름차순 정렬
        if (a.second == b.second) return a.first < b.first;  // 끝나는 시간 같으면 시작 시간 빠른 순
        return a.second < b.second;
    });

    int cnt = 0;
    int endTime = 0;  // 0시부터 시작 (0시에 끝났다고 가정)
    for (int i = 0; i < N ; i++) {
        if (endTime <= I[i].first) {  // 마지막 회의의 끝나는 시간 <= 현재 탐색 중인 회의의 시작 시간
            cnt++;
            endTime = I[i].second;  // 마지막 회의 끝나는 시간 갱신
        }
    }

    cout << cnt;

    return 0;
}