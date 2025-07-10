/*
 * Competitive Programming Template
 * Author: Abhinav Gupta
 * GitHub: @aabhinavvvvvvv
 * MAHAKAL KI JAI
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define per(i,a,b) for(int i=a; i>b; --i)
#define each(x,a) for(auto &x : a)
#define sz(x) (int)(x).size()
#define fastIO() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;

void _print(int t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(string t) { cerr << '"' << t << '"'; }
void _print(char t) { cerr << '\'' << t << '\''; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }

template <typename T, typename V> void _print(pair<T, V> p);
template <typename T> void _print(vector<T> v);
template <typename T> void _print(set<T> v);
template <typename T> void _print(multiset<T> v);
template <typename T, typename V> void _print(map<T, V> v);

template <typename T, typename V>
void _print(pair<T, V> p) { cerr << '{'; _print(p.first); cerr << ", "; _print(p.second); cerr << '}'; }
template <typename T>
void _print(vector<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template <typename T>
void _print(set<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template <typename T>
void _print(multiset<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template <typename T, typename V>
void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) _print(i), cerr << " "; cerr << "]"; }

/*
 * Bakchodi Mat Kar Laude
 * Chup Chap code kar
 * I will not be responsible for any damage caused by this code
 */

vector<int> segTree, lazy,arr;

void push(int node, int st, int end) {
    if (lazy[node] != 0) {
        segTree[node] += (end - st + 1) * lazy[node];
        if (st != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void build(int node, int st, int end){
    if(st == end){
        segTree[node] = arr[st];
        return;
    }
    int mid = st + (end - st)/2;
    build(node*2, st, mid);
    build(node*2 + 1, mid + 1, end);
    segTree[node] = segTree[node*2] + segTree[node*2 + 1];
}
void update(int node, int st, int end, int l, int r, ll val) {
    push(node, st, end);
    if (r < st || end < l) return;
    if (l <= st && end <= r) {
        lazy[node] += val;
        push(node, st, end);
        return;
    }
    int mid = (st + end) / 2;
    update(node * 2, st, mid, l, r, val);
    update(node * 2 + 1, mid + 1, end, l, r, val);
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

ll query(int node, int st, int end, int l, int r) {
    push(node, st, end);
    if (r < st || end < l) return INF;
    if (l <= st && end <= r) return segTree[node];
    int mid = (st + end) / 2;
    ll left = query(node * 2, st, mid, l, r);
    ll right = query(node * 2 + 1, mid + 1, end, l, r);
    return left + right;
}

void solve() {
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    segTree.assign(4 * n, 0);    
    lazy.assign(4 * n, 0);
    each ( x , arr ) cin>>x;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            update(1, 0, n - 1, l, r - 1, val);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r - 1) << "\n";
        }
    }
}

int main() {
    fastIO();

    // ✅ Always redirect stderr to Error.txt for debug
    freopen("Error.txt", "w", stderr);

#ifdef LOCAL
    // ✅ Only redirect input/output during local debugging
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
