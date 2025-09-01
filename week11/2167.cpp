#include <iostream>
using namespace std;

int N, M, K, i,j, x, y;
int table[301][301];
long long prefix[301][301];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> table[i][j];

            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + table[i][j];
        }
    }

    cin >> K;
    long long answer = 0;
    for (int k = 0; k < K; k++) {
        cin >> i >> j >> x >> y;

        answer = prefix[x][y] - prefix[i-1][y] - prefix[x][j-1] + prefix[i-1][j-1];

        cout << answer << '\n';
    }

    return 0;
}