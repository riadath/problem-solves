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
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, a, b) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(), x.end())

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll n,k;
        cin>>n>>k;
        if(n%2 == 0)
        {
            n += (k*2);
            cout<<n<<nl;
        }else{
            ll div = -1;
            for(ll i = 3;i <= n/2;i += 2){
                if(n%i == 0){
                    div = i;
                    break;
                }
            }
            if(div != -1){
                n += div;
                n += (k-1)*2;
            }else{
                n += n;
                n += (k-1)*2;
            }
            cout<<n<<nl;
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

