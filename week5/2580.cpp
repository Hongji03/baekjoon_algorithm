#include <iostream>
using namespace std;

int sudoku[9][9];  // 스도쿠

bool checkRow(int y, int num) {  // 가로 행 확인
    for (int i = 0; i < 9; i++) {
        if (sudoku[y][i] == num) return false;  // 이미 사용된 값이면 건너뛰기
    }
    return true;  // 중복 없으면 true
}

bool checkCol(int x, int num) {  // 세로 열 확인
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][x] == num) return false;  // 이미 사용된 값이면 건너뛰기
    }
    return true;  // 중복 없으면 true
}

bool checkBox(int y, int x, int curNum) {  // 정사각형 확인
    // 현재 좌표가 속한 3*3 박스의 시작점 계산
    x = (x / 3) * 3;
    y = (y / 3) * 3;

    for (int i = 0; i < 3; i++) {  // 현재 좌표가 속한 3*3 박스 안에 curNum이 이미 있는지 확인
        for (int j = 0; j < 3; j++) {
            int ny = y + i;  // 박스 내 행 인덱스
            int nx = x + j;  // 박스 내 열 인덱스
            if (sudoku[ny][nx] == curNum) return false;  // 이미 사용된 값이면 건너뛰기
        }
    }
    return true;  // 중복 없으면 true
}

void DFS(int d) {
    if (d == 81) {  // 81칸 모두 채운 경우
        for (int i = 0; i < 9; i++) {  // 정답 스도쿠 출력
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);  // 첫 정답 출력 후 종료
    }

    // d라는 1차원 인덱스를 2차원 좌표로 변환하기 위해 x, y 계산
    int x = d % 9;  // 현재 d번째 칸의 열
    int y = d / 9;  // 현재 d번째 칸의 행

    if (sudoku[y][x]) {  // 이미 값이 존재한 경우엔 DFS로 다음 칸 진행
        DFS(d + 1);
        return;
    }

    for (int i = 1; i <= 9; i++) {  // 1~9 숫자 중 정답 탐색
        if (checkBox(y, x, i) && checkCol(x, i) && checkRow(y, i)) {  // 스도쿠 규칙을 지킨 경우 = 가로, 세로, 정사각형에 중복되는 숫자가 없는 경우
            sudoku[y][x] = i;  // 숫자 채움
            DFS(d + 1);  // 다음 칸으로 이동
            sudoku[y][x] = 0;  // 백트래킹 - 실패하면 이전 상태로 되돌리기 위해 초기화
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }

    DFS(0);  // 제일 처음부터 시작

    return 0;
}