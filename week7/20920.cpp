#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;  // N: 입력 단어 수 | M: 외울 수 있는 최소 길이 기준
map<string, int> m;  // 단어 등장 횟수를 저장할 map

// 정렬 기준을 정의하는 함수
bool compare(pair<string, int>& a, pair<string, int>& b) {
    if (a.second != b.second) {  // 자주 나오는 단어일수록 앞에 배치
        return a.second > b.second;
    }

    if (a.first.length() != b.first.length()) { // 해당 단어의 길이가 길수록 앞에 배치
        return a.first.length() > b.first.length();
    }

    return a.first < b.first;  // 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    string word;
    for (int i = 0; i < N; i++) {
        cin >> word;
        if (word.length() >= M) {  // 길이가 M 이상인 단어만 저장
            m[word]++;
        }
    }

    vector<pair<string, int>> v(m.begin(), m.end());  // map의 내용을 vector로 옮겨 정렬을 준비
    sort(v.begin(), v.end(), compare);  // compare를 적용한 순서 변경

    for (auto& p : v) {  // 결과 출력
        cout << p.first << '\n';
    }

    return 0;
}