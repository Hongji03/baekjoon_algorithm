#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;

        int lower = lower_bound(A.begin(), A.end(), target) - A.begin();
        int upper = upper_bound(A.begin(), A.end(), target) - A.begin();

        cout << upper - lower << ' ';
    }

    return 0;
}