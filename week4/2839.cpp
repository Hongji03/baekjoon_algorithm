#include <iostream>
using namespace std;

int d[5000];  // Nkg을 만들기 위한 최소 봉지 수를 저장하는 배열, dp 계산 결과를 d 배열에 저장

int dp(int x) {
    if (x < 0) {  // 최솟값 반환 시 이상한 값 들어오는 것 방지
        return 9999;
    }

    if (x == 3 || x == 5) {  // x가 3 or 5kg이면 1개의 봉지로 만들 수 있으므로 1을 반환
        return 1;
    }

    if (d[x] != 0) {  // 이미 계산했던 배열이라면
        return d[x];  // 해당 배열을 바로 반환하여 사용
    }

    return d[x] = min(dp(x-3) + 1, dp(x-5) + 1);  // 최솟값 구하기
}

int main() {
    d[3] = 1;
    d[5] = 1;

    int N;
    cin >> N;

    dp(N);
    
    if (d[N] >= 5001) {  // 정확히 나눠 담을 수 없다는 의미
        cout << "-1";
    } else {
        cout << d[N];
    }

    return 0;
}