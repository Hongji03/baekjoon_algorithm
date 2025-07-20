#include <iostream>
#include <map>
#include <string>
using namespace std;

int T, N;  // T: 테스트 케이스의 개수 | N: 의상의 개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> N;

        map<string, int> clothes;  // 의상 종류를 key, 해당 종류의 개수를 value로 저장

        for (int i = 0; i < N; i++) {
            string name, type;
            cin >> name >> type;  // 의상 이름과 종류 입력
            clothes[type]++;   // 해당 종류의 의상 개수 증가
        }

        int result = 1;
        for (auto& pair : clothes) { // 의상 조합 계산 - 각 종류마다 경우의 수는 (개수 + 1)
            result *= (pair.second + 1);  // 각 의상의 경우의 수를 계속 곱함
        }

        result -= 1;  // 모든 의상을 선택하지 않는 경우 즉, 알몸인 경우는 제외

        cout << result << '\n';
    }

    return 0;
}