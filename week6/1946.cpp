#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;  // T: 테스트 케이스의 개수

int main () {
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;

        cin >> N;
        vector<pair<int, int>> applicants(N);
        for (int i = 0; i < N; i++) {
            cin >> applicants[i].first >> applicants[i].second;
        }

        sort(applicants.begin(), applicants.end());  // 서류 순위 기준 오름차순 정렬

        int cnt = 1;  // 서류 성적이 제일 좋으므로 첫 번째 지원자는 항상 선발
        int minInterview = applicants[0].second;  // 가장 작은 면접 순위

        for (int i = 1; i < N; i++) {
            if (applicants[i].second < minInterview) {  // 면접 성적이 이전까지 중 가장 좋은 애보다 더 좋을 경우
                cnt++;  // 선발
                minInterview = applicants[i].second;  // 면접 최고 순위 갱신
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}