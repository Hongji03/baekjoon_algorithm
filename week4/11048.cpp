#include <iostream>
using namespace std;

int candy[1001][1001] = {0}, dp[1001][1001] = {0};

int main() {
    int N, M;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {  // 각 칸에 있는 사탕의 개수 입력 받기
        for (int j = 1; j <= M; j++) {
            cin >> candy[i][j];
        }
    }

    for (int i = 1; i <= N; i++){  // 현재 칸까지 올 수 있는 최댓값은 위쪽(i-1,j), 왼쪽(i,j-1), 왼쪽 위 대각선(i-1,j-1) 중 가장 큰 값 + 현재 사탕 개수
		for (int j = 1; j <= M; j++){
			dp[i][j] = candy[i][j] + max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
		}
	}

	cout << dp[N][M] << endl;  // 마지막인 오른쪽 아래 칸까지 이동했을 때 얻을 수 있는 최대 사탕 수 출력

    return 0;
}