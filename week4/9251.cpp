#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001] = {0};

int main() {
    string s1, s2;

    cin >> s1 >> s2;

    s1 = ' ' + s1;  // 1번 인덱스부터 사용하기 위해 앞에 공백을 추가
    s2 = ' ' + s2;
    for (int i = 1; i < s1.size(); i++) {  // 문자열 입력 받기
        for (int j = 1; j < s2.size(); j++) {
            if(s1[i] == s2[j]) {  // 같은 경우
                dp[i][j] = dp[i - 1][j - 1] + 1;  // 이전 문자까지 중에 가장 큰 값에 1을 추가
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //이전 문자까지 중 가장 큰 값으로 설정
            }
        }
    }

    cout << dp[s1.size() - 1][s2.size() - 1];  // 마지막 인덱스에 최장 공통 부분 수열의 길이 저장됨

    return 0;
}