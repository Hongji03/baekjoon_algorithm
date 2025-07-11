#include <iostream>
using namespace std;

int N, K;  // N: 동전의 개수 | K: 목표 금액
int A[10];  // 동전의 가치를 저장할 배열

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {  // 동전의 가치 입력 받기
        cin >> A[i];
    }

    int cnt = 0;  // 사용할 동전의 개수를 저장
    for (int i = N - 1; i >= 0; i--) {  // 동전의 가치 중 가장 큰 값부터 비교하기 위해 인덱스를 N-1부터 1씩 내려오게 설정
        if (A[i] <= K) {  // 동전의 가치와 K를 비교해서 K원을 넘지 않는 동전의 가치의 최댓값일 때
            cnt += (K / A[i]);  // K를 해당 동전의 가치로 나눈 몫을 cnt에 더하고
            K = K % A[i];  // 나누고 남은 나머지 값을 새로 K에 저장
        }

        if (K == 0) {  // K가 0이될 때 for문을 나감
            break;
        }
    }

    cout << cnt;

    return 0;
}