#include <iostream>
#include <string>
using namespace std;

int T;  // 테스트 케이스의 개수

// 회문 여부를 확인하는 함수
bool is_palindrome(const string& s, int left, int right) {  // s: 전체 문자열 | left ~ right: 검사할 구간
    while (left < right) {
        if (s[left] != s[right]) return false;  // 다른 문자가 있으면 회문 아님
        left++;  // 같으면 다음으로 넘어가기 위해 left와 right의 값 변경
        right--;
    }

    return true;  // 끝까지 다 같았다면 회문
}

// 문자열을 검사하여 life 값을 반환
int check_life(const string& s) {
    int left = 0;  // 왼쪽 포인터: 문자열 맨 앞
    int right = s.length() - 1;  // 오른쪽 포인터: 문자열 맨 끝
    int life = 0;  // 문자 삭제 횟수

    while (left < right) {
        if (s[left] == s[right]) {  // 양쪽 문자가 같은 경우
            left++;  // 그대로 포인터를 이동하여 검사 계속 진행
            right--;
        } else {  // 양쪽 문자가 다른 경우
            // 유사회문 가능성 검사
            bool skip_left = is_palindrome(s, left + 1, right);  // 왼쪽 문자 제거
            bool skip_right = is_palindrome(s, left, right - 1);  // 오른쪽 문자 제거

            if (skip_left || skip_right) {  // 둘 중 하나라도 true이면
                life++;  // 유사회문이므로 life를 1 증가시킴
            } else {
                life += 2;  // 회문도 유사회문도 아니므로 2 증가시킴
            }
            
            break;  // 판별 완료되었으므로 더 비교하지 않음
        }
    }

    return life;  // 모든 판별이 완료된 후 life의 값 return
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    while (T--) {  // 테스트 케이스의 개수만큼 반복
        string s;
        cin >> s;

        cout << check_life(s) << '\n';  // life: 0 (회문), 1 (유사회문), 2 (일반 문자열)
    }

    return 0;
}