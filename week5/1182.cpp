#include <iostream>
using namespace std;

int N, S;
int cnt = 0;  // 조건을 만족하는 부분수열의 개수 카운팅
int nums[20];  // 입력 받은 숫자들을 저장하는 배열

// 백트래킹 함수
void DFS(int d, int sum) {  // N개의 모든 원소에 대해 선택 or 선택안함 여부를 결정했을 때 종료
    if (d == N) {  // 현재까지의 합이 S와 같다면 cnt 값 증가
        if (sum == S) cnt++;
        return;
    }

    DFS(d + 1, sum + nums[d]);  // 현재 원소 nums[d]를 포함하는 경우
    DFS(d + 1, sum);  // 현재 원소를 포함하지 않는 경우
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    
    DFS(0, 0);  // 깊이 0, 현재 합 0부터 시작
    
    if (S == 0) cnt--;  // 공집합 제외

    cout << cnt << '\n';

    return 0;
}