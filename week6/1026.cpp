#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[51], B[51];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    sort(A, A + N);  // A는 오름차순 정렬
    sort(B, B + N, greater<int>());  // B는 내림차순 정렬

    int S = 0;
    for (int i = 0; i < N; i++) {
        S += A[i] * B[i];
    }

    cout << S;

    return 0;
}