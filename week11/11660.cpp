#include <iostream>
using namespace std;

int N, M, x1,y1, x2, y2;
int table[1025][1025];
int prefix[1025][1025];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> table[i][j];

            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + table[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2>> y2;

        answer = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];

        cout << answer << '\n';
    }

    return 0;
}