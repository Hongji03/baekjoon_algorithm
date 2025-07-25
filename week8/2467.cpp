#include <iostream>
#include <cmath>
using namespace std;

int N;  // 전체 용액의 수
int ans_left = 0, ans_right = 0;  // 정답으로 출력할 두 수
const int INF = 2000000001;  // 처음에 탐색할 때 참이 되기 위한 충분히 큰 값
int liq[100001];  // 용액 특성값 저장 배열

int main() {
    cin >> N;  // 전체 용액의 수 입력 받기

    for (int i = 0; i < N; i++) {  // 특성값 입력 받기
        cin >> liq[i];
    }

    int left = 0;  // 왼쪽 포인터: 맨 앞에서 시작
    int right = N - 1;  // 오른쪽 포인터: 맨 뒤에서 시작

    int best_sum = INF;  // 0에 가장 가까운 합

    while (left < right) {  // 투 포인터 탐색
        int sum = liq[left] + liq[right];  // 현재 두 특성값의 합

        if (abs(sum) < best_sum) {  // 현재 두 용액의 합이 이전까지의 최소 차이보다 0에 더 가까운 경우
            best_sum = abs(sum);  // 최소 차이 갱신
            ans_left = liq[left];  // 정답 후보 왼쪽 값 저장
            ans_right = liq[right];  // 정답 후보 오른쪽 값 저장
        }

        if (sum < 0) {  // 두 용액 특성값의 합이 0보다 작은 경우
            left++;  // 더 큰 수가 필요하므로 왼쪽 포인터를 오른쪽으로 옮기기
        } else {  // 두 용액 특성값의 합이 0보다 크거나 같은 경우
            right--;  // 더 작은 수가 필요하므로 오른쪽 포인터를 왼쪽으로 옮기기
        }
    }

    cout << ans_left << " " << ans_right << '\n';
    
    return 0;
}