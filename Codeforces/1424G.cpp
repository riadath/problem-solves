#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args...)
// #endif

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

struct detum
{
    bool flag;
    ll sum, cmd, idx;
};
ll n;
detum tree[1000009];
detum make_data(int s, int c, bool f)
{
    detum ret;
    ret.cmd = c;
    ret.sum = s;
    ret.flag = f;
    ret.idx = -1;
    return ret;
}
detum combine(detum a, detum b)
{
    detum ret;
    ret.sum = max(a.sum, b.sum);
    if (a.sum == b.sum)
    {
        ret.idx = min(a.idx, b.idx);
    }
    else if (ret.sum == a.sum)
    {
        ret.idx = a.idx;
    }
    else
        ret.idx = b.idx;

    ret.flag = 0;
    ret.cmd = 0;
    return ret;
}
void build(int nd, int st, int en)
{
    if (st == en)
    {
        // cout << "----->" << st << nl;
        tree[nd].sum = 0;
        tree[nd].idx = st;
        return;
    }
    int mid = (st + en) / 2, left = 2 * nd, right = left + 1;
    build(left, st, mid);
    build(right, mid + 1, en);
    tree[nd] = combine(tree[left], tree[right]);
}

void nd_update(int nd, int st, int en, int cm)
{

    tree[nd].sum += cm;
    tree[nd].cmd += cm;
    tree[nd].flag = true;
}
void lz_update(int nd, int st, int en)
{
    int mid = (st + en) / 2;
    int left = 2 * nd, right = left + 1;

    nd_update(left, st, mid, tree[nd].cmd);
    nd_update(right, mid + 1, en, tree[nd].cmd);
    tree[nd].cmd = 0;
    tree[nd].flag = false;
}
void update(int nd, int st, int en, int i, int j, int cm)
{
    if (st > j || en < i)
        return;
    if (st >= i && en <= j)
    {
        nd_update(nd, st, en, cm);
        return;
    }
    int mid = (st + en) / 2;
    int left = 2 * nd, right = left + 1;
    if (tree[nd].flag)
        lz_update(nd, st, en);
    update(left, st, mid, i, j, cm);
    update(right, mid + 1, en, i, j, cm);
    tree[nd] = combine(tree[left], tree[right]);
}
detum query(int nd, int st, int en, int i, int j)
{
    if (st > j || en < i)
        return make_data(0, 0, 0);
    if (st >= i && en <= j)
    {
        return tree[nd];
    }
    int mid = (st + en) / 2;
    int left = 2 * nd, right = left + 1;
    if (tree[nd].flag)
        lz_update(nd, st, en);
    detum a = query(left, st, mid, i, j);
    detum b = query(right, mid + 1, en, i, j);
    return combine(a, b);
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll cnt;
    cin >> cnt;
    map<ll, bool> check;
    map<ll, ll> mping, revmpa;
    vector<ll> all_num;
    vector<pll> ranges;
    fl(i, 0, cnt)
    {
        int x, y;
        cin >> x >> y;
        ranges.pb(mp(x, y));
        if (!check[x])
        {
            check[x] = true;
            all_num.pb(x);
        }
        if (!check[y])
        {
            check[y] = true;
            all_num.pb(y);
        }
    }
    sort(all(all_num));
    fl(i, 0, all_num.size())
    {
        mping[all_num[i]] = i + 1;
        revmpa[i + 1] = all_num[i];
    }

    n = all_num.size();
    build(1, 1, n);
    fl(i, 0, cnt)
    {
        // cout << "->" << ranges[i].fi << sp << ranges[i].se << nl;
        ll x = mping[ranges[i].fi];
        ll y = mping[ranges[i].se];
        // cout << x << sp << y << nl;
        update(1, 1, n, x, y - 1, 1);
    }
    detum ans = query(1, 1, n, 1, n);
    cout << revmpa[ans.idx] << sp << ans.sum << nl;
    return 0;
}
