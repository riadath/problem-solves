#include <bits/stdc++.h>
using namespace std;
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
#define seg_tree int mid = (st + en) / 2, left = 2 * nd, right = left + 1

bool comp(const pii &a, const pii &b)
{
    return a.second > b.second;
}

ll tree[3 * 500009], valid[3 * 500009], divisor[10000009], arr[500009], n;
void build(int nd, int st, int en)
{
    if (st == en)
    {
        tree[nd] = arr[st];
        valid[nd] = 1;
        return;
    }
    seg_tree;
    build(left, st, mid);
    build(right, mid + 1, en);
    tree[nd] = tree[left] + tree[right];
    valid[nd] = valid[left] + valid[right];
}

void update(int nd, int st, int en, int i, int j)
{
    if (valid[nd] == 0)
        return;
    if (st > j || en < i)
        return;
    if (st == en)
    {
        tree[nd] = divisor[tree[nd]];
        if (tree[nd] <= 2)
            valid[nd] = 0;
        return;
    }
    seg_tree;
    update(left, st, mid, i, j);
    update(right, mid + 1, en, i, j);
    tree[nd] = tree[right] + tree[left];
    valid[nd] = valid[right] + valid[left];
}

ll query(int nd, int st, int en, int i, int j)
{
    if (st > j || en < i)
        return 0;
    if (st >= i && en <= j)
    {
        return tree[nd];
    }
    seg_tree;
    ll a = query(left, st, mid, i, j);
    ll b = query(right, mid + 1, en, i, j);
    return a + b;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    for (ll i = 1; i <= 1000009; i++)
    {
        for (ll j = i; j <= 1000009; j += i)
            divisor[j]++;
    }

    int m;
    cin >> n >> m;
    fl(i, 1, n + 1) cin >> arr[i];
    build(1, 1, n);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(1, 1, n, b, c);
        }
        else
        {
            cout << query(1, 1, n, b, c) << nl;
        }
    }
    return 0;
}