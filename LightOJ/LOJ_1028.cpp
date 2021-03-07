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
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (int i = a; i < b; i++)
#define lf(i, a, b) for (int i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(), x.end())

#define sz 1000009
bool if_p[sz];

void sieve()
{
    if_p[0] = true;
    if_p[1] = true;
    for (ll i = 4; i <= sz; i += 2)
        if_p[i] = true;
    ll i, j;
    for (i = 3; i * i <= sz; i += 2)
    {
        for (j = 2; i * j <= sz; j++)
        {
            if_p[i * j] = true;
        }
    }
}
ll num_div(ll n)
{
    ll nod = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        if (!if_p[i] && n % i == 0)
        {
            ll t = 0;
            // cout<<"n: "<<n<<"   div: "<<i<<nl;
            while (n % i == 0)
            {
                t++;
                n = n / i;
            }
            nod = nod * (t + 1);
        }
    }
    //cout<<"n : "<<n<<nl;
    if (n > 1)
    {
        nod *= 2;
    }
    return nod;
}
int main()
{
    //FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    sieve();
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; k++)
    {
        ll n;
        scanf("%lld", &n);
        ll ans = num_div(n);
        ans--;
        printf("Case %d: %lld\n", k, ans);
    }
    return 0;
}
