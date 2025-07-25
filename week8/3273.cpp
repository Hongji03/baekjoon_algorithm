#include <iostream>
#include <algorithm>
using namespace std;

int n, x;
int seq[100001];  // 수열

int main() {
    cin >> n;  // 수열의 크기 입력 받기

    for (int i = 0; i < n; i++) {  // 수열에 포함되는 수 입력 받기
        cin >> seq[i];
    }

    cin >> x;  // 자연수 x 입력 받기

    sort(seq, seq + n);  // 오름차순 정렬

    int left = 0;  // 왼쪽 포인터: 맨 앞에서 시작
    int right = n - 1;  // 오른쪽 포인터: 맨 뒤에서 시작
    int cnt = 0;

    while (left < right) {  // 투 포인터 탐색
        int sum = seq[left] + seq[right];  // 현재 두 수의 합

        if (sum == x) {  // 두 수의 합이 x인 경우
            cnt++;
            left++;  // 양쪽 포인터 모두 이동
            right--;
        } else if (sum < x) {  // 합이 x보다 작은 경우
            left++;  // 왼쪽 포인터를 오른쪽으로 이동
        } else {  // 합이 x보다 큰 경우
            right--;  // 오른쪽 포인터를 왼쪽으로 이동
        }
    }

    cout << cnt << '\n';
    
    return 0;
}