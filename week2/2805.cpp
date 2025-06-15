#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    int low = 0;
    int high = *max_element(trees.begin(), trees.end());
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        long long sum = 0;

        for (int height : trees) {
            if (height > mid) {
                sum += (height - mid);
            }
        }

        if (sum >= M) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << '\n';
    return 0;
}