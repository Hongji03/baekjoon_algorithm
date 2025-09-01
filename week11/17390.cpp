#include <iostream>
#include <algorithm>
using namespace std;

int N, Q, L, R;
int A[300001];
int prefix[300001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(A+1, A+N+1);

    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i-1] + A[i];
    }

    int answer = 0;
    for (int k = 0; k < Q; k++) {
        cin >> L >> R;

        answer = prefix[R] - prefix[L-1];
        
        cout << answer << '\n';
    }

    return 0;
}