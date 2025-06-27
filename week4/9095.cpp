#include <iostream>
using namespace std;

int main() {
    int T, N;
    int dp[12];  // N을 1, 2, 3의 합으로 나타내는 방법의 수

    dp[1] = 1;  // N이 1인 경우
    dp[2] = 2;  // N이 2인 경우
    dp[3] = 4;  // N이 3인 경우
    for (int i = 4; i < 12; i++) {  // dp값 미리 다 구해놓기
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << dp[N] << endl;
    }

    return 0;
}