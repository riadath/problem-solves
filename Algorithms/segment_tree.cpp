/*
    Segment tree code for sum(can be used for min,max)
    only a single element can be updated with this code
*/

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

#define MX 100010
int n;
int arr[MX], tree[3 * MX];

void build(int nd, int st, int en)
{
    if (st == en)
    {
        tree[nd] = arr[st];
        return;
    }
    int left = 2 * nd, right = left + 1;
    int mid = (st + en) / 2;
    build(left, st, mid);
    build(right, mid + 1, en);
    tree[nd] = max(tree[left], tree[right]);
}

void update(int nd, int st, int en, int i, int x)
{
    if (i < st || i > en)
        return;
    if (st == en)
    {
        tree[nd] = x;
        return;
    }
    int mid = (st + en) / 2;
    int left = 2 * nd, right = left + 1;
    if (i <= mid)
        update(left, st, mid, i, x);
    else
        update(right, mid + 1, en, i, x);
    tree[nd] = max(tree[left], tree[right]);
}

int query(int nd, int st, int en, int i, int j)
{
    if (j < st || i > en)
        return 0;
    if (st >= i && en <= j)
        return tree[nd];
    int left = 2 * nd;
    int right = left + 1;
    int mid = (st + en) / 2;
    int a = query(left, st, mid, i, j);
    int b = query(right, mid + 1, en, i, j);
    return a + b;
}

void solve()
{
    int T;
    scanf("%d", &T);
    fl(kas, 1, T + 1)
    {
        int q;
        scanf("%d %d", &n, &q);
        fl(i, 1, n + 1) scanf("%d", &arr[i]);
        build(1, 1, n);
        printf("Case %d:\n", kas);
        fl(i, 0, q)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            int ans = query(1, 1, n, x, y);
            printf("%d\n", ans);
        }
    }
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
