/*
 * Competitive Programming Template
 * Author: Abhinav Gupta
 * GitHub: @aabhinavvvvvvv
 * MAHAKAL KI JAI
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

const int N = 2e5 + 5;
const int LOG = 20;

vector<vector<pii>> up; // {ancestor, minValueOnPath}
vector<int> depth;
vector<vector<int>> adj;
vector<int> arr; // values assigned to nodes

void dfs(int node, int parent) {
    // up[node][0] → (parent, minValue on 1 jump)
    up[node][0] = { parent, (parent == -1 ? arr[node] : min(arr[node], arr[parent])) };

    // fill binary lifting table for node
    for (int j = 1; j < LOG; j++) {
        int mid_ancestor = up[node][j - 1].first;
        if (mid_ancestor != -1) {
            up[node][j].first = up[mid_ancestor][j - 1].first;
            up[node][j].second = min(up[node][j - 1].second, up[mid_ancestor][j - 1].second);
        }
    }

    for (auto nxt : adj[node]) {
        if (nxt == parent) continue;
        depth[nxt] = depth[node] + 1;
        dfs(nxt, node);
    }
}

pii findlca_min(int u, int v) {
    int minVal = min(arr[u], arr[v]); // initial min is their own values

    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];

    for (int i = 0; i < LOG; ++i) {
        if (diff & (1 << i)) {
            minVal = min(minVal, up[u][i].second);
            u = up[u][i].first;
        }
    }

    if (u == v) return {u, minVal};

    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i].first != -1 && up[u][i].first != up[v][i].first) {
            minVal = min(minVal, up[u][i].second);
            minVal = min(minVal, up[v][i].second);
            u = up[u][i].first;
            v = up[v][i].first;
        }
    }

    // final step: check parent of u and v
    minVal = min(minVal, up[u][0].second);
    minVal = min(minVal, up[v][0].second);

    return { up[u][0].first, minVal };
}

void solve() {
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    adj.assign(n, {});
    depth.assign(n, 0);
    up.assign(n, vector<pii>(LOG, {-1, INT_MAX}));

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    while (q--) {
        int u, v; cin >> u >> v;
        --u; --v;
        pii res = findlca_min(u, v);
        int lca = res.first;
        int minVal = res.second;
        int dist = depth[u] + depth[v] - 2 * depth[lca];
        cout << dist << " " << minVal << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
