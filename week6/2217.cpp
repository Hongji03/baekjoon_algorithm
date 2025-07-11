#include <iostream>
#include <algorithm>
using namespace std;

int N;
int w[100001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {  // 각 로프가 버틸 수 있는 최대 무게 입력 받기
        cin >> w[i];
    }

    sort(w, w + N);  // 가장 약한 로프 기준으로 오름차순 정렬

    int maxWeight = 0;
    for (int i = 0; i < N; i++) {
        int weight = w[i] * (N - i);  // i번째 로프부터 N개 사용 시 들 수 있는 최대 중량 계산
        maxWeight = max(maxWeight, weight);  // 최댓값 갱신
    }

    cout << maxWeight;

    return 0;
}