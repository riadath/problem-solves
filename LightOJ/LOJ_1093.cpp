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

#define MX 100009
struct data
{
    ll mn1, idx;
};
int n, d;
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
    data ret;
    ret.mn1 = max(a.mn1, b.mn1);
    ret.idx = min(a.idx, b.idx);
    return ret;
}
void build(int nd, int st, int en)
{
    if (st == en)
    {
        tree[nd] = make_data(arr[st], arr[st]);
        return;
    }
    seg_tree;
    build(left, st, mid);
    build(right, mid + 1, en);
    tree[nd] = combine(tree[left], tree[right]);
}

data query(int nd, int st, int en, int i, int j)
{
    if (st > j || en < i)
        return make_data(0, 1e10);
    if (st >= i && en <= j)
    {
        return tree[nd];
    }
    seg_tree;
    data a = query(left, st, mid, i, j);
    data b = query(right, mid + 1, en, i, j);
    return combine(a, b);
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
        scanf("%d %d", &n, &d);
        fl(i, 1, n + 1) scanf("%lld", &arr[i]);
        build(1, 1, n);
        data now;
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            int st = i;
            int en = min((ll)n, i + d - 1);
            now = query(1, 1, n, st, en);
            ans = max(ans, now.mn1 - now.idx);
        }
        printf("Case %d: %lld\n", kas++, ans);
    }
    return 0;
}
