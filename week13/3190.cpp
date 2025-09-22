#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, K, L;
deque<pair<int, char>> turns;
deque<pair<int, int>> snake;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int dir = 0;

int main() {
    cin >> N;
    cin >> K;

    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        board[r - 1][c - 1] = 1;
    }

    cin >> L;
    for (int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;
        turns.push_back({X, C});
    }

    snake.push_front({0, 0});
    board[0][0] = 2;

    int time = 0;

    while (true) {
        time++;

        int nr = snake.front().first + dr[dir];
        int nc = snake.front().second + dc[dir];

        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
            cout << time << '\n';
            break;
        }

        bool eatApple = (board[nr][nc] == 1);
        pair<int, int> tail = snake.back();
        bool hit = (board[nr][nc] == 2);
        if (hit) {
            if (!(!eatApple && nr == tail.first && nc == tail.second)) {
                cout << time << '\n';
                break;
            }
        }

        snake.push_front({nr, nc});

        if (eatApple) {
            board[nr][nc] = 2;
        } else {
            board[nr][nc] = 2;
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }

        if (!turns.empty() && time == turns.front().first) {
            char t = turns.front().second;
            turns.pop_front();
            if (t == 'L') {
                dir = (dir + 3) % 4;
            } else {
                dir = (dir + 1) % 4;
            }
        }
    }

    return 0;
}