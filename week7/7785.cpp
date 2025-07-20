#include <iostream>
#include <map>
#include <string>
using namespace std;

int N;  // 출입 기록의 수
map<string, bool, greater<string>> names;  // 이름, 출퇴근 상태를 저장할 map | 사전 역순 정렬을 위한 greater<string>
string name, cmd;  // 이름 및 출퇴근 상태 입력값 저장 변수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> name >> cmd;  // 이름과 상태 입력
        if (cmd == "enter") {  // 출근 기록
            names[name] = true;
        } else if (cmd == "leave") {  // 퇴근 기록
            names[name] = false;
        }
    }
    
    for (auto& pair : names) {  // 사전 역순으로 자동 정렬된 map 중 출근 상태(true)인 이름만 출력
        if (pair.second == true) {
            cout << pair.first << '\n';
        }
    }

    return 0;
}