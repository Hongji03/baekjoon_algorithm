#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int N, M, K;
vector<ll> arr, seg;

ll init(int node, int s, int e) {
    if (s == e) return seg[node] = (arr[s] % MOD);
    int mid = (s + e) / 2;
    return seg[node] = (init(node * 2, s, mid) * init(node * 2 + 1, mid + 1, e)) % MOD;
}

ll query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 1;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    return (query(node * 2, s, mid, l, r) * query(node * 2 + 1, mid + 1, e, l, r)) % MOD;
}

ll update(int node, int s, int e, int idx, ll val) {
    if (idx < s || idx > e) return seg[node];
    if (s == e) {
        arr[idx] = val % MOD;
        return seg[node] = arr[idx];
    }
    int mid = (s + e) / 2;
    ll left = update(node * 2, s, mid, idx, val);
    ll right = update(node * 2 + 1, mid + 1, e, idx, val);
    return seg[node] = (left * right) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    int height = (int)ceil(log2(N));
    int size = (1 << (height + 1));
    arr.resize(N + 1);
    seg.assign(size, 1);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] %= MOD;
    }
    init(1, 1, N);

    for (int i = 0; i < M + K; i++) {
        int a;
        ll b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            update(1, 1, N, (int)b, c % MOD);
        } else {
            int l = (int)min(b, c);
            int r = (int)max(b, c);
            cout << query(1, 1, N, l, r) % MOD << "\n";
        }
    }
    return 0;
}