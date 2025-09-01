#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string s, bomb, answer;
stack<char> S;

int main() {
    cin >> s;
    cin >> bomb;

    for (int i = 0; i < s.length(); i++) {
        S.push(s[i]);

        if (s[i] == bomb[bomb.length() - 1] && S.size() >= bomb.length()) {
            string tmp;

            for (int i = 0; i < bomb.length(); i++) {
                tmp.push_back(S.top());
                S.pop();
            }

            reverse(tmp.begin(), tmp.end());

            if (tmp != bomb) {
                for (int i = 0; i < tmp.length(); i++) {
                    S.push(tmp[i]);
                }
            }
        }
    }

    while(!S.empty()) {
        answer.push_back(S.top());
        S.pop();
    }

    reverse(answer.begin(), answer.end());

    if (answer.empty()) {
        cout << "FRULA";
    } else {
        cout << answer;
    }

    return 0;
}