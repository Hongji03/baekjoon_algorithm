#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int N, Q;
vector<ll> seg;

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

    cin >> N >> Q;

    int height = (int)ceil(log2(N));
    int size = (1 << (height + 1));
    seg.assign(size, 0);

    while (Q--) {
        int type;
        ll p, q;
        cin >> type >> p >> q;

        if (type == 1) {
            update(1, 1, N, (int)p, q);
        } else {
            cout << query(1, 1, N, (int)p, (int)q) << "\n";
        }
    }

    return 0;
}