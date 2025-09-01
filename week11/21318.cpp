#include <iostream>
using namespace std;

int N, Q, x, y;
int level[100001];
int prefix[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> level[i];

        if (i == 1) {
            prefix[i] = 0;
        } else if (level[i] < level[i-1]) {
            prefix[i] = prefix[i-1] + 1;
        } else {
            prefix[i] = prefix[i-1];
        }
    }

    cin >> Q;
    int answer = 0;
    for (int k = 0; k < Q; k++) {
        cin >> x >> y;

        answer = prefix[y] - prefix[x];
        
        cout << answer << '\n';
    }

    return 0;
}