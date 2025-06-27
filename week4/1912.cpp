#include <iostream>
using namespace std;

int main() {
    int N;
    int a[100001], dp[100001];

    cin >> N;
    for (int i = 0; i < N; i++) {  // 수열 입력 받기
        cin >> a[i];
    }

    int ans = a[0];      // 정답 초기값은 첫 번째 원소로 설정
    dp[0] = a[0];         // dp[0]을 첫 번째 원소로 초기화
    for (int i = 0; i < N; i++) {  // i번째까지의 최대 연속합 = (i-1번째까지의 최대 연속합 + 현재값)과 (현재값) 중 큰 값
        dp[i] = max(a[i], dp[i-1] + a[i]);
        ans = max(ans, dp[i]);  // 연속합의 최대값을 ans에 저장
    }

    cout << ans;

    return 0;
}