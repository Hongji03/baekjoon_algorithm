#include <iostream>
#include <stack>
using namespace std;

stack<char> S;
string s;

int main() {
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' && s[i + 1] == ')') {
            cnt += S.size();
            i++;
        } else if (s[i] == '(') {
            S.push(i);
        } else if (s[i] == ')') {
            cnt++;
            S.pop();
        }
    }

    cout << cnt;

    return 0;
}