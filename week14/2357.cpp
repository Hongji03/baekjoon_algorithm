#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

typedef long long ll;

int N, M;
vector<ll> arr;
vector<pair<ll, ll>> seg;

pair<ll, ll> init(int node, int s, int e) {
    if (s == e) {
        return seg[node] = {arr[s], arr[s]};
    }
    int mid = (s + e) / 2;
    auto L = init(node * 2, s, mid);
    auto R = init(node * 2 + 1, mid + 1, e);
    return seg[node] = { min(L.first, R.first), max(L.second, R.second) };
}

pair<ll, ll> query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return {LLONG_MAX, LLONG_MIN};
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    auto L = query(node * 2, s, mid, l, r);
    auto R = query(node * 2 + 1, mid + 1, e, l, r);
    return { min(L.first, R.first), max(L.second, R.second) };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    int height = (int)ceil(log2(N));
    int size = (1 << (height + 1));
    arr.resize(N + 1);
    seg.assign(size, {LLONG_MAX, LLONG_MIN});

    for (int i = 1; i <= N; ++i) cin >> arr[i];
    init(1, 1, N);

    while (M--) {
        int a, b;
        cin >> a >> b;
        auto ans = query(1, 1, N, a, b);
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}