#include <iostream>
using namespace std;

int N, M, i, j;
int A[100001];
int prefix[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        prefix[i] = prefix[i-1] + A[i];
    }

    cin >> M;
    int answer = 0;
    for (int k = 0; k < M; k++) {
        cin >> i >> j;

        answer = prefix[j] - prefix[i-1];
        
        cout << answer << '\n';
    }

    return 0;
}