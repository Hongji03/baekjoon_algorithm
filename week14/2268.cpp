#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int N, M;
vector<ll> arr, seg;

ll init(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];
    int mid = (s + e) / 2;
    return seg[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

ll Sum(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    return Sum(node * 2, s, mid, l, r) + Sum(node * 2 + 1, mid + 1, e, l, r);
}

void Modify(int node, int s, int e, int idx, ll diff) {
    if (idx < s || idx > e) return;
    seg[node] += diff;
    if (s == e) return;
    int mid = (s + e) / 2;
    Modify(node * 2, s, mid, idx, diff);
    Modify(node * 2 + 1, mid + 1, e, idx, diff);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    int height = (int)ceil(log2(N));
    int size = (1 << (height + 1));
    arr.assign(N + 1, 0);
    seg.assign(size, 0);

    while (M--) {
        int a;
        ll b, c;
        cin >> a >> b >> c;

        if (a == 0) {
            if (b > c) swap(b, c);
            cout << Sum(1, 1, N, (int)b, (int)c) << '\n';
        } else {
            ll diff = c - arr[(int)b];
            arr[(int)b] = c;
            Modify(1, 1, N, (int)b, diff);
        }
    }
    return 0;
}