#include <iostream>
using namespace std;

int N;  // 숫자의 자리수

bool isPrime(int num) {
    if (num < 2) return false;  // 0, 1은 소수 X
    for (int i = 2; i * i <= num; i++ ) {  // 2부터 sqrt(num)까지 반복
        if (num % i == 0) return false;  // 나누어 떨어지면 소수 X
    }
    return true;  // 위의 조건들을 모두 통과하면 소수 O
}

void DFS(int d, int num) {  // d: 현재 자리수, num: 지금까지 만든 숫자
    if (d == N) {  // 숫자의 자리수가 N이 됐을 때
        cout << num << '\n';  // 해당 숫자 출력
        return;
    }

    for (int i = 1; i <= 9; i++) {  // 현재 자리수 뒤에 1부터 9까지 붙여가며 소수 판별
        int next = num * 10 + i;  // 기존 숫자 뒤에 i(1~9)를 붙여 다음 숫자를 생성
        if (isPrime(next)) {  // 생성한 숫자가 소수라면 다음 자리수로 탐색
            DFS(d + 1, next);
        }
    }
}

int main() {
    cin >> N;

    // 2, 3, 5, 7로 시작하는 숫자부터 시작
    DFS(1, 2);
    DFS(1, 3);
    DFS(1, 5);
    DFS(1, 7);

    return 0;
}