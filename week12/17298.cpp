#include <iostream>
#include <stack>
using namespace std;

int N;
int A[1000001], answer[1000001];
stack<int> S;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        while (!S.empty() && A[S.top()] < A[i]) {
            answer[S.top()] = A[i];
            S.pop();
        }

        S.push(i);
    }

    while (!S.empty()) {
        answer[S.top()] = -1;
        S.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}