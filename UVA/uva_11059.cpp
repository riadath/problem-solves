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
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, kas = 1;
    ll arr[200];
    while (scanf("%d", &n) != EOF)
    {
        ll temp, mxp = -1e10;
        bool flag = false;
        fl(i, 0, n)
        {
            scanf("%lld", &arr[i]);
        }

        // fl(i, 0, n) cout << arr[i] << sp;
        // cout << nl;

        fl(i, 0, n)
        {
            fl(sz, 0, n)
            {
                temp = 1;
                fl(k, i, min((ll)n, i + sz + 1))
                {
                    temp *= arr[k];
                }
                if (temp >= 0)
                    flag = true;
                if (temp > mxp)
                {
                    mxp = temp;
                }
            }
        }
        printf("Case #%d: ", kas++);
        if (!flag)
            printf("The maximum product is 0.\n\n");
        else
            printf("The maximum product is %lld.\n\n", mxp);
    }
    return 0;
}
