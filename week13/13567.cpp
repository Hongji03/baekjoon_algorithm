#include <iostream>
using namespace std;

int M, n, number;
string command;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int dir = 0;

int main() {
    cin >> M >> n;

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        cin >> command >> number;

        if (command == "MOVE") {
            for (int i = 0; i < number; i++) {
                x += dx[dir];
                y += dy[dir];
            }
            if (x < 0 || x > M || y < 0 || y > M) {
                cout << -1 << '\n';
                return 0;
            }
        }

        if (command == "TURN") {
            if (number == 0) {
                dir = (dir + 3) % 4;
            } else {
                dir = (dir + 1) % 4;
            }
        }
    }

    cout << x << " " << y << '\n';

    return 0;
}