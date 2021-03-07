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
#define pii pair<ll, ll>
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

bool comp(const pii &a, const pii &b)
{
    return a.second < b.second;
}
double dt(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
map<int, bool> used;
map<int, int> mapping;
void solve()
{
    int T;
    scanf("%d", &T);
    fl(kas, 1, T + 1)
    {
        int n, q, cunt = 0;
        scanf("%d %d", &n, &q);
        vector<pii> test;
        vector<int> ranges, points;

        int x, y;
        fl(i, 0, n)
        {
            scanf("%d", &x);
            points.pb(x);
            if (used[x] == 0)
            {
                used[x] = 1;
                ranges.pb(x);
                cunt++;
            }
        }
        fl(i, 0, q)
        {
            scanf("%d %d", &x, &y);
            test.pb(mp(x, y));
            if (used[x] == 0)
            {
                used[x] = 1;
                ranges.pb(x);
                cunt++;
            }
            if (used[y] == 0)
            {
                used[y] = 1;
                ranges.pb(y);
                cunt++;
            }
        }
        srt(ranges);
        int tree[cunt + 100];
        MEM(tree, 0);
        fl(i, 0, cunt)
        {
            mapping[ranges[i]] = i + 1;
        }
        fl(i, 0, n)
        {
            x = points[i];
            x = mapping[x];
            tree[x]++;
        }
        int cumsum[cunt + 100];
        MEM(cumsum, 0);
        cumsum[1] = tree[1];
        fl(i, 2, cunt + 1)
        {
            cumsum[i] = cumsum[i - 1] + tree[i];
        }
        printf("Case %d:\n", kas);
        fl(i, 0, q)
        {
            x = test[i].fi, y = test[i].se;
            x = mapping[x], y = mapping[y];
            int ans = cumsum[y] - cumsum[x - 1];
            printf("%d\n", ans);
        }
        used.clear();
        mapping.clear();
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
