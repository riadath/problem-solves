#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

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

bool comp(const pii &a, const pii &b)
{
    return a.fi < b.fi;
}

#define MX 101000
int n;
pii tree[4 * MX];

void build(int nd, int st, int en)
{
    if (st == en)
    {
        tree[nd].fi = 0;
        tree[nd].se = st;
        return;
    }
    int left = 2 * nd, right = left + 1;
    int mid = (st + en) / 2;
    build(left, st, mid);
    build(right, mid + 1, en);
    // tree[nd] = max(tree[left], tree[right]);
    tree[nd].fi = 0;
    if (tree[left].se < tree[right].se)
        tree[nd] = tree[left];
    else
        tree[nd] = tree[right];
}

void update(int nd, int st, int en, int i, int x)
{
    if (i < st || i > en)
        return;
    if (st == en)
    {
        tree[nd].fi += x;
        return;
    }
    int mid = (st + en) / 2;
    int left = 2 * nd, right = left + 1;
    if (i <= mid)
        update(left, st, mid, i, x);
    else
        update(right, mid + 1, en, i, x);
    tree[nd] = max(tree[left], tree[right]);
    if (tree[left].fi > tree[right].fi)
    {
        tree[nd] = tree[left];
    }
    else if (tree[left].fi < tree[right].fi)
    {
        tree[nd] = tree[right];
    }
    else if (tree[left].se < tree[right].se)
        tree[nd] = tree[left];
    else
        tree[nd] = tree[right];
}

pii query(int nd, int st, int en, int i, int j)
{
    if (j < st || i > en)
        return mp(-1e8, 0);
    if (st >= i && en <= j)
        return tree[nd];
    int left = 2 * nd;
    int right = left + 1;
    int mid = (st + en) / 2;
    pii a = query(left, st, mid, i, j);
    pii b = query(right, mid + 1, en, i, j);
    if (a.fi > b.fi)
        return a;
    else if (a.fi < b.fi)
        return b;
    else
    {
        if (a.se < b.se)
            return a;
        else
            return b;
    }
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int q, cur_win = 1, st = 0;
        cin >> n >> q;
        build(1, 1, n);
        fl(ev, 1, q + 1)
        {
            int x, p;
            cin >> x >> p;
            update(1, 1, n, x, p);
            pii winn = query(1, 1, n, 1, n);
            winn.se == cur_win ? st++ : (cur_win = winn.se, st = 0);
        }
        cout << q - st << nl;
        MEM(tree, 0);
    }
    return 0;
}
