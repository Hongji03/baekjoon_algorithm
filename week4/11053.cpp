#include <iostream>
using namespace std;

int main() {
    int N;
    int A[10001], dp[10001];

    cin >> N;
    for (int i = 0; i < N; i++) {  // 수열 입력 받기
        cin >> A[i];
    }

    int increasing = 0;  // 최장 증가 부분 수열의 길이를 저장할 변수
    for (int i = 0; i < N; i++) {
        dp[i] = 1;  // 각 위치에서 시작하는 수열의 최소 길이는 1
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {  // 이전 값보다 현재 값이 클 경우 -> 증가 수열 가능
                dp[i] = max(dp[i], dp[j]+ 1);  // 최장 길이 갱신
            }
        }
        increasing = max(increasing, dp[i]);  // 전체 최댓값 갱신
    }

    cout << increasing << endl;

    return 0;
}