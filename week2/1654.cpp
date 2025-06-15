#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;

    vector<long long> cables(K);
    for (int i = 0; i < K; i++) {
        cin >> cables[i];
    }

    long long low = 1;
    long long high = *max_element(cables.begin(), cables.end());
    long long result = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long count = 0;

        for (int i = 0; i < K; i++) {
            count += cables[i] / mid;
        }

        if (count >= N) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << '\n';
    return 0;
}
