#include <iostream>
using namespace std;

int board[5][5];
int visited[5][5] = {0};
int bingo;
int number;

int check() {
    int line = 0;

    for (int i = 0; i < 5; i++) {
        bool ok = true;
        for (int j = 0; j < 5; j++) {
            if (!visited[i][j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            line++;
        }
    }

    for (int j = 0; j < 5; j++) {
        bool ok = true;
        for (int i = 0; i < 5; i++) {
            if (!visited[i][j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            line++;
        }
    }

    if (visited[0][0] && visited[1][1] && visited[2][2] && visited[3][3] && visited[4][4]) {
        bool ok = true;
        line++;
    }

    if (visited[0][4] && visited[1][3] && visited[2][2] && visited[3][1] && visited[4][0]) {
        bool ok = true;
        line++;
    }

    return line;
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for (int k = 0; k < 25; k++) {
        cin >> number;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == number) {
                    visited[i][j] = 1;
                    break;
                }
            }
        }

        bingo = check();
        if (bingo >= 3) {
            cout << k + 1 << '\n';
            return 0;
        }
    }

    return 0;
}