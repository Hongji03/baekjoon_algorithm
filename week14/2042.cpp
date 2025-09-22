#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int N, M, K;
vector<ll> arr, seg;

ll init(int node, int s, int e) {
    if (s == e) {
        return seg[node] = arr[s];
    }

    int mid = (s + e) / 2;
    return seg[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

ll query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

void update(int node, int s, int e, int idx, ll diff) {
    if (idx < s || idx > e) return;
    seg[node] += diff;
    if (s == e) return;
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, diff);
    update(node * 2 + 1, mid + 1, e, idx, diff);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    int height = (int)ceil(log2(N));
    int size = (1 << (height + 1));
    arr.resize(N + 1);
    seg.resize(size);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init(1, 1, N);

    for (int i = 0; i < M + K; i++) {
        int a;
        ll b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            ll diff = c - arr[b];
            arr[b] = c;
            update(1, 1, N, b, diff);
        } else {
            cout << query(1, 1, N, b, c) << "\n";
        }
    }

    return 0;
}