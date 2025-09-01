#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N, K;
string s, answer;
stack<char> S;

int main() {
    cin >> N >> K;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        while (K > 0 && !S.empty() && S.top() < c) {
            S.pop();
            K--;
        }
        
        S.push(c);
    }

    while (K > 0 && !S.empty()) {
        S.pop();
        K--;
    }

    while (!S.empty()) {
        answer.push_back(S.top());
        S.pop();
    }

    reverse(answer.begin(), answer.end());

    cout << answer;

    return 0;
}