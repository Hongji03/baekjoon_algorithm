#include <iostream>
#include <algorithm>
using namespace std;

int coin[1001], dp[10001];

int main() {
    int N, K;

    cin >> N >> K;
    for (int i = 0; i < N; i++) {  // 동전의 크기 입력 받기
        cin >> coin[i];
    }

    for (int i = 0; i <= K; i++) {  // dp 배열을 매우 큰 값인 10001로 초기화
		dp[i] = 10001;
	}

    dp[0] = 0;  // 0원을 만들기 위해 필요한 동전 개수는 0
    for (int i = 0; i < N; i++){  // 현재 금액 j를 만들기 위해 coin[i]를 사용한 경우와 사용하지 않은 경우 중 최솟값 선택
		for (int j = coin[i]; j <= K; j++){
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[K] == 10001) {  // dp[K]가 초기값 그대로 = 만들 수 없음
        cout << -1;
    } else {
        cout << dp[K];
    }

    return 0;
}