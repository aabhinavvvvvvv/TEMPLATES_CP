#include <bits/stdc++.h>
using namespace std;

#define fastIO() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<int> segTree, arr;

void build(int node, int st, int end) {
    if (st == end) {
        segTree[node] = arr[st];  
        return;
    }
    int mid = (st + end) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, end);
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

void update(int node, int st, int end, int pos, int val) {
    if (st == end) {
        arr[pos] = val;
        segTree[node] = val;
        return;
    }
    int mid = (st + end) / 2;
    if (pos <= mid)
        update(2 * node, st, mid, pos, val);
    else
        update(2 * node + 1, mid + 1, end, pos, val);
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

int query(int node, int st, int end, int l, int r) {
    if (r < st || end < l)
        return 0; 
    if (l <= st && end <= r)
        return segTree[node]; 

    int mid = (st + end) / 2;
    int left = query(2 * node, st, mid, l, r);
    int right = query(2 * node + 1, mid + 1, end, l, r);
    return left + right;
}

void solve() {
    int n, q;
    cin >> n;
    arr.resize(n);
    segTree.resize(4 * n);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    build(1, 0, n - 1);

    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << "\n";
        } else if (type == 2) {
            int pos, val;
            cin >> pos >> val;
            update(1, 0, n - 1, pos, val);
        }
    }
}

int main() {
    fastIO();

    freopen("Error.txt", "w", stderr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
