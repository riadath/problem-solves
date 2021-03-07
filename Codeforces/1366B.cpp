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
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>


bool comp(const pair<db,pair<pdd,pdd>> &a,const pair<db,pair<pdd,pdd>> &b)
{
    return a.fi <= b.fi;
}
double dt(pii a,pii b)
{
    int x1 = a.fi,y1 = a.se;
    int x2 = b.fi,y2 = b.se;
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

db tra(pdd a,pdd b,pdd c)
{
    db temp = 0;
    temp += a.fi*b.se+b.fi*c.se+c.fi*a.se;
    temp -= b.fi*a.se+c.fi*b.se+a.fi*c.se;
    temp = abs(temp);
    temp /= 2.0;
    return temp;
}

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll n,x,m;
        cin>>n>>x>>m;
        pll rn = mp(x,x);
        pll cr = mp(x,x);
        fl(i,0,m){
            ll p,q;
            cin>>p>>q;
            if(p > cr.se || q < cr.fi){}
            else{
                if(cr.fi < p)p = cr.fi;
                if(cr.se > q)q = cr.se;
                cr = mp(p,q);
            }
        }
        cout<<(cr.se - cr.fi + 1)<<nl;
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

