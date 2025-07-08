/*
 * Competitive Programming Template
 * Author: Abhinav Gupta
 * GitHub: @aabhinavvvvvvv
 * MAHAKAL KI JAI
 */

#include <bits/stdc++.h>
using namespace std;

#define fastIO()                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);



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
    for(int i=0;i<m;i++)
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