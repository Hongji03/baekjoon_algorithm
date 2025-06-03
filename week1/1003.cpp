#include <iostream>
using namespace std;

int A[41], B[41];

int main() {
	int T;
	cin >> T;

	int N;

	for (int i = 0; i < T; i++) {
		cin >> N;

		// A는 0의 개수, B는 1의 개수
		A[0] = 1;
		B[0] = 0;
		A[1] = 0;
		B[1] = 1;
		for (int i = 2; i < 41; i++) {
			A[i] = A[i - 1] + A[i - 2];
			B[i] = B[i - 1] + B[i - 2];
		}

		cout << A[N] << " " << B[N] << endl;
	}

	return 0;
}