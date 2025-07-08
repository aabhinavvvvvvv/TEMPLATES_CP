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
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a; i > b; --i)
#define each(x, a) for (auto &x : a)
#define sz(x) (int)(x).size()
#define fastIO()                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);

#define debug(x)         \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << endl;

void _print(int t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(string t) { cerr << '"' << t << '"'; }
void _print(char t) { cerr << '\'' << t << '\''; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }

template <typename T, typename V>
void _print(pair<T, V> p);
template <typename T>
void _print(vector<T> v);
template <typename T>
void _print(set<T> v);
template <typename T>
void _print(multiset<T> v);
template <typename T, typename V>
void _print(map<T, V> v);

template <typename T, typename V>
void _print(pair<T, V> p)
{
    cerr << '{';
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << '}';
}
template <typename T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
        _print(i), cerr << " ";
    cerr << "]";
}
template <typename T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
        _print(i), cerr << " ";
    cerr << "]";
}
template <typename T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
        _print(i), cerr << " ";
    cerr << "]";
}
template <typename T, typename V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
        _print(i), cerr << " ";
    cerr << "]";
}

/*
 * Bakchodi Mat Kar Laude
 * Chup Chap code kar
 * I will not be responsible for any damage caused by this code
 */

class Disjoint
{
public:
    int n;
    vector<int> rank, parent;
    Disjoint(int n)
    {
        this->n = n;
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i=0;i<n+1;i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        return parent[x] = findUParent(parent[x]);
    }
    void unionSet(int a, int b)
    {
        int x = findUParent(a);
        int y = findUParent(b);
        if (x == y)
            return;
        if (rank[x] < rank[y])
            parent[x] = y;
        else if (rank[y] < rank[x])
            parent[y] = x;
        else
        {
            parent[y] = x;
            rank[x]++;
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m; 

    Disjoint ds(n);
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        
        ds.unionSet(u, v);
    }

    if (ds.findUParent(1) == ds.findUParent(6))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Different" << endl;
    }
    ds.unionSet(1,6);
    if (ds.findUParent(1) == ds.findUParent(6))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Different" << endl;
    }
}

int main()
{
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
    while (t--)
        solve();
    return 0;
}
