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
#define pll pair<long, long>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define srta(x, n) sort(x, x + n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define seg_tree int mid = (st + en) / 2, left = 2 * nd, right = left + 1
bool comp(const pii &a, const pii &b)
{
    return a.second < b.second;
}
double dt(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

#define MX 30009
struct data
{
    ll mn1, idx;
};
int n;
data tree[3 * MX];
ll arr[MX];
data make_data(ll a, ll b)
{
    data ret;
    ret.mn1 = a;
    ret.idx = b;
    return ret;
}
data combine(data a, data b)
{
    if (a.mn1 < b.mn1)
        return a;
    if (a.mn1 > b.mn1)
        return b;
    else
    {
        if (a.idx < b.idx)
            return a;
        else
            return b;
    }
}
void build(int nd, int st, int en)
{
    if (st == en)
    {
        tree[nd] = make_data(arr[st], st);
        return;
    }
    int mid = (st + en) / 2, left = 2 * nd, right = left + 1;
    build(left, st, mid);
    build(right, mid + 1, en);
    tree[nd] = combine(tree[left], tree[right]);
}

data query(int nd, int st, int en, int i, int j)
{
    if (st > j || en < i)
        return make_data(1e15, 1e15);
    if (st >= i && en <= j)
    {
        return tree[nd];
    }
    int mid = (st + en) / 2;
    int left = 2 * nd, right = left + 1;
    data a = query(left, st, mid, i, j);
    data b = query(right, mid + 1, en, i, j);
    return combine(a, b);
}

ll mxArea(int st, int en)
{
    if (st > en)
        return 0;
    data ret = query(1, 1, n, st, en);
    return max((en - st + 1) * ret.mn1, max(mxArea(st, ret.idx - 1), mxArea(ret.idx + 1, en)));
}

int main()
{
    //FIO;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        fl(i, 1, n + 1) scanf("%d", &arr[i]);
        build(1, 1, n);
        printf("Case %d: %lld\n", kas++, mxArea(1, n));
    }
    return 0;
}
