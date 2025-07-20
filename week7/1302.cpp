#include <iostream>
#include <map>
#include <string>
using namespace std;

int N;  // 책의 판매 기록 개수
map<string, int> books;  // 책 제목(key), 판매 횟수(value)를 저장하는 map

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    string title;

    for (int i = 0; i < N; i++) {  // 책 제목을 입력받으며 판매 횟수 기록
        cin >> title;
        books[title]++;  // 해당 제목의 판매 횟수 1 증가
    }

    int maxCount = 0;  // 가장 많이 팔린 책의 판매 횟수
    string bestSeller = "";  // 가장 많이 팔린 책의 제목

    for (auto& pair : books) {  // 최다 판매 책 찾기
        if (pair.second > maxCount) {  // 더 많이 팔린 책 발견시 최댓값 갱신
            maxCount = pair.second;
            bestSeller = pair.first;
        }
    }

    cout << bestSeller << '\n';
    return 0;
}