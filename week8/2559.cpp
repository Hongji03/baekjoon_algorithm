#include <iostream>
using namespace std;

int N, K, max_sum;  // N: 전체 날짜 수 | K: 연속 날짜 수 | max_sum: 최대 합 저장 변수
int temp[100001];  // temp: 온도 값을 저장할 배열

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {  // 각 날짜의 온도 입력받기
        cin >> temp[i];
    }

    int current_sum = 0;
    for (int i = 0; i < K; i++) {  // 첫 K일 간의 온도 합 계산
        current_sum += temp[i];
    }
    max_sum = current_sum;  // 현재 합을 최대 합으로 초기 설정

    for (int i = K; i < N; i++) {  // 슬라이딩 윈도우 적용해 K일 간의 합 갱신
        current_sum = current_sum - temp[i - K] + temp[i];  // 맨 앞 값을 빼고, 새로운 값을 더함
        if (current_sum > max_sum) {  // 현재 합 > 최대 합이라면 최대 합 갱신
            max_sum = current_sum;
        }
    }

    cout << max_sum << '\n';

    return 0;
}