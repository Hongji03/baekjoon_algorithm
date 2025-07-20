#include <iostream>
#include <map>
using namespace std;

int N, M;  // N: 집합 S에 포함된 문자열 개수 | M: 검사할 문자열 개수
map<string, bool> m;  // 문자열을 key로 저장하고, 존재 여부를 value(true)로 나타냄

int main() {
    cin >> N >> M;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        m.insert(pair<string, bool>(str, true));  // N개의 문자열을 입력받아 map에 저장
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {  // M개의 문자열을 입력받아 S에 포함되어 있는지 확인
        cin >> str;
        if (m[str] == true) {  // map에 해당 문자열이 존재하고, 값이 true라면
            cnt++;  // cnt 값 1만큼 증가
        }
    }

    cout << cnt;

    return 0;
}