#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nums[8];  // N의 개수
int selected[8];  // 길이가 M인 수열을 저장 = 현재까지 선택한 수열 저장
bool visited[8];  // 숫자 중복 확인 여부

// 백트래킹 함수
void DFS(int d, int s) {  // s는 시작 인덱스
    if (d == M) {  // 수열의 길이가 M이 되면 완성
        for (int i = 0; i < M; i++) {  // 완성된 수열 출력
            cout << selected[i] << ' ';
        }
        cout << '\n';  // 원래 endl 썼었는데, endl가 단순 줄바꿈이 아니라 출력 버퍼를 비우는 작업까지 포함해서 반복적으로 출력할 경우 매우 느려진다고 하네욤
        return;
    }

    for (int i = s; i < N; i++) {  // 이전보다 큰 숫자만 선택
        if (!visited[i]) {
            visited[i] = true;  // 숫자 i visited 표시
            selected[d] = nums[i];  // 현재 깊이의 숫자 선택
            DFS(d + 1, i + 1);  // 다음 깊이로 재귀 호출, 다음 숫자는 i 이후 부터
            visited[i] = false;  // 백트래킹 -> 이전에 선택한 숫자를 다시 사용 가능하도록 visited 해제
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + N);  // 오름차순 정렬

    DFS(0, 0);  // 깊이 0, 시작 인덱스 0부터 시작

    return 0;
}