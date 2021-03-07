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
#define pdd pair<double,double>
#define pll pair<long, long>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, a, b) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(), x.end())
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll n,k;
        cin>>n>>k;
        ll cn = 0;
        while(cn < k-1)
        {
            ll t = n;
            ll mn = 1e18,mx = -1e18;
            while(t != 0)
            {
                ll temp = t%10;
                mn = min(temp,mn);
                mx = max(temp,mx);
                t = t/10;
            }
            if(mn*mx == 0)break;
            n += (mn*mx);
            cn++;
        }
        cout<<n<<nl;
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

