#include <iostream>
using namespace std;

int N, M;
string s;
int length = 0;
int S[51][51];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            S[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cnt = 0;

            for (int k = 1; ; k++) {
                if ((j + k) >= M || (i + k) >= N) {
                    break;
                }

                if (S[i][j] == S[i][j + k] && S[i][j] == S[i + k][j] && S[i][j] == S[i + k][j + k]) {
                    if (cnt < k) {
                        cnt = k;
                    }
                }
            }

            if (length < (cnt + 1)) {
                length = cnt + 1;
            }
        }
    }

    cout << length * length << '\n';

    return 0;
}