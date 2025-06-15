#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> lectures;

bool is_possible(int capacity) {
    int count = 1;
    int sum = 0;

    for (int length : lectures) {
        if (sum + length > capacity) {
            count++;
            sum = 0;
        }
        sum += length;
    }

    return count <= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    lectures.resize(N);

    int total = 0;
    int max_length = 0;
    for (int i = 0; i < N; i++) {
        cin >> lectures[i];
        total += lectures[i];
        max_length = max(max_length, lectures[i]);
    }

    int low = max_length;
    int high = total;
    int result = total;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (is_possible(mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result << '\n';
    return 0;
}