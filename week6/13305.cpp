#include <iostream>
using namespace std;

int N;

int main() {
    cin >> N;

    long long distance[100001];  // 도시 간 거리 (N-1개)
    long long price[100001];     // 각 도시의 리터당 가격 (N개)

    for (int i = 0; i < N - 1; i++) {  // 도시 간 거리 입력
        cin >> distance[i];
    }

    for (int i = 0; i < N; i++) {  // 각 도시의 주유값 입력
        cin >> price[i];
    }

    long long total = 0;
    long long minPrice = price[0];  // 처음 도시의 주유값

    for (int i = 0; i < N - 1; i++) {  // distance의 수만큼 반복
        if (price[i] < minPrice) {
            minPrice = price[i];  // 더 싼 주유값 발견 시 주유값 갱신
        }
        total += minPrice * distance[i];  // 현재까지의 최소 가격으로 이동 거리만큼 비용 계산
    }

    cout << total << '\n';

    return 0;
}