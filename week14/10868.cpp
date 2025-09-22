#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

typedef long long ll;

int N, M;
vector<ll> arr, seg;

ll init(int node, int s, int e) {
    if (s == e) return seg[node] = arr[s];
    int mid = (s + e) / 2;
    ll L = init(node * 2, s, mid);
    ll R = init(node * 2 + 1, mid + 1, e);
    return seg[node] = min(L, R);
}

ll query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return LLONG_MAX;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    ll L = query(node * 2, s, mid, l, r);
    ll R = query(node * 2 + 1, mid + 1, e, l, r);
    return min(L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    int height = (int)ceil(log2(N));
    int size = (1 << (height + 1));
    arr.resize(N + 1);
    seg.assign(size, LLONG_MAX);

    for (int i = 1; i <= N; ++i) cin >> arr[i];
    init(1, 1, N);

    while (M--) {
        int a, b;
        cin >> a >> b;
        
        cout << query(1, 1, N, a, b) << '\n';
    }

    return 0;
}