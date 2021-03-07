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

bool comp(const pii &a, const pii &b)
{
    if (a.fi == b.fi)
        return a.se < b.se;
    return a.fi < b.fi;
}
int dirx[] = {1, -1, -1, 1};
int diry[] = {1, 1, -1, -1};

int n;
vector<ll> prs;
bool ext[2001][2001];

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> n;
    int mx = 0;
    fl(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        ext[x][y] = true;
        mx = max(mx, max(x, y));
    }
    mx++;
    fl(i, 1, mx + 1)
    {
        ll cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        if (ext[1][i])
        {
            cnt1++;
            cnt2++;
        }
        if (ext[i + 1][1])
        {
            cnt3++;
        }
        if (ext[i + 1][mx])
        {
            cnt4++;
        }
        fl(k, 1, mx + 1)
        {
            int x, y;

            x = 1 + k;
            y = i + k;
            if (x >= 0 && y >= 0)
                if (ext[x][y])
                    cnt1++;

            x = 1 + k;
            y = i - k;
            if (x >= 0 && y >= 0)
                if (ext[x][y])
                    cnt2++;

            x = (i + 1) + k;
            y = 1 + k;
            if (x >= 0 && y >= 0)
                if (ext[x][y])
                    cnt3++;

            x = (i + 1) + k;
            y = (mx)-k;
            if (x >= 0 && y >= 0)
                if (ext[x][y])
                    cnt4++;
        }

        if (cnt1 > 1)
            prs.pb(cnt1);
        if (cnt2 > 1)
            prs.pb(cnt2);
        if (cnt3 > 1)
            prs.pb(cnt3);
        if (cnt4 > 1)
            prs.pb(cnt4);
    }
    ll tot = 0;
    fl(i, 0, prs.size())
    {
        tot += (prs[i] * (prs[i] - 1)) / 2;
    }
    cout << tot << nl;

    return 0;
}
