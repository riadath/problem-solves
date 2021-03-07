#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args...)
// #endif

// #pragma GCC target("avx2")
// #pragma GCC optimization("O3")
// #pragma GCC optimization("unroll-loops")

long long oll = 0;
#define ll long long
#define ull unsigned long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp1(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
    return get<2>(a) < get<2>(b);
}
bool comp2(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}
vector<tuple<int, int, int>> edgeList;
int n, parent[109], tw = 2;
map<pii, int> chek;
int find_parent(int st)
{
    if (parent[st] == st)
        return st;
    else
        return find_parent(parent[st]);
}

ll kruskal()
{
    int cnt = 0;
    ll tot = 0;
    fl(i, 0, n + 1) parent[i] = i;
    for (int i = 0; i < (int)edgeList.size(); i++)
    {
        int u = get<0>(edgeList[i]);
        int v = get<1>(edgeList[i]);
        int w = get<2>(edgeList[i]);
        u = find_parent(u);
        v = find_parent(v);
        if (u != v && !chek[mp(u, v)])
        {
            // cout << "HERE: " << u << sp << v << sp << w << nl;
            tot += w;
            cnt++;
            parent[u] = v;
            chek[mp(u, v)] = true;
            if (cnt == n)
                break;
        }
    }
    chek.clear();
    return tot;
}

int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        while (true)
        {
            int u, v, x;
            scanf("%d %d %d", &u, &v, &x);
            if (!u && !v && !x)
                break;
            if (u > v)
                swap(u, v);
            edgeList.pb(make_tuple(u, v, x));
        }
        sort(all(edgeList), comp1);
        //minimum ber korbo ekhane
        // fl(i, 0, edgeList.size()) cout << "-->" << get<0>(edgeList[i]) << sp << get<1>(edgeList[i]) << sp << get<2>(edgeList[i]) << nl;
        int mn = kruskal();
        sort(all(edgeList), comp2);
        //maximum ber korbo ekhane
        // fl(i, 0, edgeList.size()) cout << "==>" << get<0>(edgeList[i]) << sp << get<1>(edgeList[i]) << sp << get<2>(edgeList[i]) << nl;
        int mx = kruskal();
        printf("Case %d: ", kas++);
        // cout << mx << sp << mn << nl;
        if ((mx + mn) % 2 == 0)
        {
            int ans = (mx + mn) / 2;
            printf("%d\n", ans);
        }
        else
        {
            int ans = mx + mn;
            printf("%d/%d\n", ans, tw);
        }
        //clear
        edgeList.clear();
    }
    return 0;
}
