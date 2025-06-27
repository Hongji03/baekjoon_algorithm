#include <iostream>
using namespace std;

int main() {
    int T, N;
    int dp[12];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 12; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << dp[N] << endl;
    }

    return 0;
}