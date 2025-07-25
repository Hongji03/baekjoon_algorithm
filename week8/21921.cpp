#include <iostream>
using namespace std;

int N, X, max_vis;  // N: 블로그 운영 전체 일수 | X: 연속 날짜 수 | max_vis: 최대 방문자 수 저장 변수
int visited[250001];  // visited: 하루 방문자 수를 저장할 배열

int main() {
    cin >> N >> X;
    for(int i = 0; i < N; i++) {  // 방문자 수 입력 받기
        cin >> visited[i];
    }

    int current_sum = 0;
    for (int i = 0; i < X; i++) {  // 첫 X일 간의 방문자 수 합 계산
        current_sum += visited[i];
    }
    max_vis = current_sum;  // 현재 합을 최대 합으로 초기 설정
    int cnt = 1;  // 최대값을 설정해주었으므로 1로 설정

    for (int i = X; i < N; i++) {  // 슬라이딩 윈도우 적용해 X일 간의 합 갱신
        current_sum = current_sum - visited[i - X] + visited[i];  // 맨 앞 값을 빼고, 새로운 값을 더함
        if (current_sum > max_vis) {  // 현재 합 > 최대 합이라면 최대 합 갱신
            max_vis = current_sum;
            cnt = 1;  // 새로운 최대값 발견하였으므로 cnt 초기화
        } else if (current_sum == max_vis) {
            cnt++;  // 기존 최대값과 같다면 cnt 증가
        }
    }

    if (max_vis == 0) {  // 최대 방문자 수가 0이면 "SAD" 출력
        cout << "SAD" << '\n';
    } else {
        cout << max_vis << '\n' << cnt << '\n';
    }
    
    return 0;
}