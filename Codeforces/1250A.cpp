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
    return a.second > b.second;
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    int a[m + 10];
    fl(i, 0, m) cin >> a[i];
    int pos_lo[n + 10], pos_hi[n + 10];
    int pos[n + 10], pos2[n + 10];
    fl(i, 1, n + 1)
    {
        pos[i] = i;
        pos2[i] = i;
        pos_lo[i] = i;
        pos_hi[i] = i;
    }
    fl(i, 0, m)
    {
        // fl(j, 1, n + 1) cout << pos[j] << sp;
        // cout << nl;
        if (pos[a[i]] != 1)
        {
            int el = pos2[pos[a[i]] - 1];
            // cout << "BEFORE : \n";
            // cout << "->" << a[i] << "=" << pos[a[i]] << sp << el << "=" << pos[el] << nl;
            swap(pos2[pos[a[i]]], pos2[pos[el]]);
            swap(pos[a[i]], pos[el]);
            pos_lo[a[i]] = min(pos_lo[a[i]], pos[a[i]]);
            pos_hi[a[i]] = max(pos_hi[a[i]], pos[a[i]]);
            pos_lo[el] = min(pos_lo[el], pos[el]);
            pos_hi[el] = max(pos_hi[el], pos[el]);
            // cout << "->" << a[i] << "=" << pos[a[i]] << sp << el << "=" << pos[el] << nl;
            // fl(i, 1, n + 1) cout << pos2[i] << sp;
            // cout << nl;
        }
    }
    fl(i, 1, n + 1)
    {
        cout << pos_lo[i] << sp << pos_hi[i] << nl;
    }

    return 0;
}