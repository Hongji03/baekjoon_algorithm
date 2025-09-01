#include <iostream>
#include <stack>
using namespace std;

int T;

int main() {
    cin >> T;
    while (T--) {
        string s = "";
        cin >> s;

        stack<char> S;
        bool valid = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                S.push('(');
            }
            if (s[i] == ')') {
                if (S.empty()) {
                    valid = false;
                    break;
                }
                S.pop();
            }
        }

        if (valid && S.empty()) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}