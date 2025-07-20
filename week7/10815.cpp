#include <iostream>
#include <map>
using namespace std;

int N, M;  // N: 숫자카드에 있는 수의 개수 | M: 검사할 수의 개수
map<int, bool> m;  // 숫자를 key로 저장하고, 존재 여부를 value(true)로 나타냄

int main() {
    ios::sync_with_stdio(false);  // C 입출력과의 동기화 해제
    cin.tie(NULL);                // cin과 cout의 연결 해제
    
    cin >> N;

    int num;
    for (int i = 0; i < N; i++) {  // 숫자카드에 있는 숫자들을 map에 저장
        cin >> num;
        m[num] = true;  // 해당 숫자 존재 표시
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> num;
        if (m[num] == true) {  // 숫자카드에 해당 숫자가 존재하면 1, 아니면 0 출력
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }

    return 0;
}