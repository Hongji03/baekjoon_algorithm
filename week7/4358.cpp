#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

map<string, int> trees;  // 나무 이름, 등장 횟수 저장할 map
string name;  // 나무 이름
int total = 0;  // 나무의 총 개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (getline(cin, name)) {  // 입력이 끝날 때까지 한 줄씩 나무 이름 입력받기
        trees[name]++;  // 해당 이름의 나무 등징 횟수 증가
        total++;  // 나무의 총 개수 증가
    }

    cout << fixed << setprecision(4);  // 소수점 4자리까지 출력
    for (auto& pair : trees) {
        double percent = (double)pair.second / total * 100;  // 각 나무의 비율 계산
        cout << pair.first << " " << percent << '\n';  // 나무 이름 및 비율 사전순 출력
    }

    return 0;
}