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
    return a.se < b.se;
}

#define MX 100009
ll arr[100009];
int n, q;
struct data
{
    bool flag;
    ll sum, cmd;
};
data tree[3 * MX];

data make_data(int s, int c, bool f)
{
    data ret;
    ret.cmd = c;
    ret.sum = s;
    ret.flag = f;
    return ret;
}
data combine(data a, data b)
{
    data ret;
    ret.sum = a.sum + b.sum; //query operation(sum,max,min etc)
    ret.flag = 0;
    ret.cmd = 0;
    return ret;
}
void build(int nd, int st, int en)
{
    if (st == en)
    {
        tree[nd].sum = arr[st];
        tree[nd].cmd = 0;
        tree[nd].flag = 0;
        return;
    }
    int mid = (st + en) / 2, left = 2 * nd, right = left + 1;
    build(left, st, mid);
    build(right, mid + 1, en);
    tree[nd] = combine(tree[left], tree[right]);
}

void nd_update(int nd, int st, int en, int cm)
{
    tree[nd].sum += (en - st + 1) * cm;
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

data query(int nd, int st, int en, int i, int j)
{
    if (st > j || en < i)
        return make_data(0, 0, 0); //make_data(inf for min,0 for max etc.);
    if (st >= i && en <= j)
    {
        return tree[nd];
    }
    int mid = (st + en) / 2;
    int left = 2 * nd, right = left + 1;
    if (tree[nd].flag)
        lz_update(nd, st, en);
    data a = query(left, st, mid, i, j);
    data b = query(right, mid + 1, en, i, j);
    return combine(a, b);
}

void solve()
{
    int T;
    cin >> T;
    int kas = 1;
    while (T--)
    {
        //enter query and numebr of elements
        cin >> n >> q;
        fl(i, 1, 1 + n) cin >> arr[i];
        build(1, 1, n);
        while (q--)
        {
            int a, b, c, v;
            cin >> a >> b >> c;
            if (a == 0)
            {
                cin >> v;
                update(1, 1, n, b, c, v);
            }
            else
            {
                cout << query(1, 1, n, b, c).sum << nl;
            }
        }
    }
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
