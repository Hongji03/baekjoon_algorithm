#include <iostream>
#include <climits>
using namespace std;

int N, S;  // N: 수열 길이 | S: 목표 부분합
int arr[100001];  // 수열 저장 배열

int main() {
    cin >> N >> S;

    for (int i = 0; i < N; i++) {  // 수열의 각 원소 입력
        cin >> arr[i];
    }

    int left = 0;  // 왼쪽 포인터: 맨 앞에서 시작
    int right = 0;  // 오른쪽 포인터도 앞에서 시작, 이후 윈도우의 끝으로 확장
    int sum = 0;  // 현재 윈도우의 합
    int min_len = INT_MAX;  // 조건을 만족하는 최소 길이, 초기 값은 매우 큰 값으로 초기화

    while (true) {
        if (sum >= S) {  // 현재 합이 S 이상인 경우
            min_len = min(min_len, right - left);  // 더 짧은 구간이 있는지 확인하기 위해 길이 조정
            sum -= arr[left++];  // 왼쪽 값을 빼고 윈도우를 줄이기
        } else if (right == N) {  // 오른쪽 포인터가 끝까지 도달한 경우
            break;  // 오른쪽 포인터의 이동이 불가하므로 종료
        } else {  // 합이 S보다 작고, 오른쪽 포인터 이동이 가능한 경우
            sum += arr[right++];  // 오른쪽 값을 더하면서 수열의 구간 확장하기
        }
    }

    if (min_len == INT_MAX) {  // 조건을 만족하는 수열이 존재하지 않는 경우
        cout << 0 << '\n';  // 0 출력
    } else {  // 조건을 만족하는 경우
        cout << min_len << '\n';  // 최소 길이 출력
    }

    return 0;
}