#include <iostream>
#include <algorithm>
using namespace std;

string S;
char a;
int q, l, r;
int A[300001];
int prefix[26][200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S;
    cin >> q; 

    for (int i = 1; i <= S.size(); i++) {
        int c = S[i-1] - 'a';

        for (int j = 0; j < 26; j++) {
            prefix[j][i] = prefix[j][i-1];
        }

        prefix[c][i]++;
    }

    int answer = 0;
    for (int k = 0; k < q; k++) {
        cin >> a >> l >> r;
        int idx = a - 'a';
        answer = prefix[idx][r+1] - prefix[idx][l];
        
        cout << answer << '\n';
    }

    return 0;
}