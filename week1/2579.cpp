#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int dp[302];  // 최대 점수 저장
    int stair[302];  // 계단 점수
    for (int i = 0; i < N; i++) {
        cin >> stair[i + 1];  // stair[1]부터 사용
    }

    for (int i = 0; i < N; i++) {
        dp[1] = stair[1];
        dp[2] = stair[1] + stair[2];
        dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
        for (int i = 4; i < N + 1; i++) {
            dp[i] = max(
                dp[i - 2] + stair[i],
                dp[i - 3] + stair[i - 1] + stair[i]
            );
        }
    }

    cout << dp[N] << endl;

    return 0;
}