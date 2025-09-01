#include <iostream>
#include <stack>
using namespace std;

int N;
int tower[1000001], answer[1000001];
stack<int> S;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tower[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        while (!S.empty() && tower[S.top()] < tower[i]) {
            answer[S.top()] = i + 1;
            S.pop();
        }

        S.push(i);
    }

    while (!S.empty()) {
        answer[S.top()] = 0;
        S.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}