#include <iostream>
using namespace std;

int T, M, N, K;
int field[50][50];
bool visited[50][50];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if (field[ny][nx] == 1 && !visited[ny][nx]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;

        for (int i = 0; i < N; i++) {
            fill(field[i], field[i] + M, 0);
            fill(visited[i], visited[i] + M, false);
        }

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        int count = 0;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (field[y][x] == 1 && !visited[y][x]) {
                    dfs(x, y);
                    count++;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}