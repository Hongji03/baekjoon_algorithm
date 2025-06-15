#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> request(N);
    for (int i = 0; i < N; i++) {
        cin >> request[i];
    }

    int M;
    cin >> M;

    int low = 0;
    int high = *max_element(request.begin(), request.end());
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        long long total = 0;

        for (int i = 0; i < N; i++) {
            total += min(request[i], mid);
        }

        if (total <= M) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << '\n';
    return 0;
}
