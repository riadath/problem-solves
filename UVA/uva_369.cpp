#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(ll i = a;i < b;i++)
#define lf(i,a,b) for(ll i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(),x.end())

void solve()
{
    ll n,m,p1,p2;
    while(cin>>n>>m && (n||m))
    {
        p1 = n,p2 = m;
        long double res = n;
        ll div = 2.0;
        if(n == m)
            res = 1;
        else
        {
            fl(i,0,m-1)
            {
                res *= (n-1);
                res /= div;
                n--;
                div++;
            }
        }
        cout<<p1<<" things taken "<<p2<<" at a time is "<<(ll)round(res)<<" exactly."<<nl;
    }
}

int main()
{
    FIO;
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    solve();
    return 0;
}

