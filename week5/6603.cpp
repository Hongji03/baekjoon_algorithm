#include <iostream>
#include <algorithm>
using namespace std;

int k;  // 입력 받는 수의 개수
int nums[13];  // 입력 받은 숫자들을 저장하는 배열
int selected[6];  // 선택된 조합을 저장하는 배열

// 백트래킹 함수
void DFS(int d, int s) {  // d는 깊이, s는 시작 인덱스
    if (d == 6) {  // 6개의 숫자를 모두 선택했으면 출력
        for (int i = 0; i < 6; i++) {  // 숫자 출력
            cout << selected[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = s; i < k; i++) {  // s부터 시작해서 nums 배열의 숫자를 하나씩 선택
        selected[d] = nums[i];  // 현재 깊이의 숫자 선택
        DFS(d + 1, i + 1);  // 다음 깊이로 재귀 호출, 다음 숫자는 i+1 이후 부터
    }
}

int main() {
    while(true) {
        cin >> k;  // 태스트 케이스 입력
        if (k == 0) break;  // k가 0이면 종료

        for (int i = 0; i < k; i ++) {
            cin >> nums[i];
        }

        sort(nums, nums + k);  // 오름차순 정렬
        DFS(0, 0);  // 깊이 0, 시작 인덱스 0부터 시작
        cout << '\n';
    }

    return 0;
}