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

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}
void solve()
{
    int T;
    cin>>T;
    fl(kas,1,T+1)
    {
        ll n,r,p,q;
        cin>>n>>r>>p>>q;
        ll upore5 = 0,niche5 = 0,upore2 = 0,niche2 = 0,sm = 0,sm2 = 0,up = 0,temp;
        ll tt = n;
        for(ll p = 1;; p++)
        {
            temp = tt/pow(5,p);
            if(temp == 0)break;
            sm += temp;
        }
        upore5 += sm;
        tt = n;
        sm = 0;
        for(ll p = 1;; p++)
        {
            temp = tt/pow(2,p);
            if(temp == 0)break;
            sm += temp;
        }
        upore2 += sm;
        sm = 0;
        temp = p;
        while(temp%5 == 0)
        {
            sm++;
            temp /= 5;
        }
        upore5 += q*sm;
        temp = p;
        sm2 = 0;
        while(temp%2 == 0)
        {
            sm2++;
            temp /= 2;
        }
        upore2 += q*sm2;
        tt = n-r;
        sm = 0;
        for(ll p = 1;; p++)
        {
            temp = tt/pow(5,p);
            if(temp == 0)break;
            sm += temp;
        }
        niche5 += sm;
        tt = n-r;
        sm = 0;
        for(ll p = 1;; p++)
        {
            temp = tt/pow(2,p);
            if(temp == 0)break;
            sm += temp;
        }
        niche2 += sm;
        tt = r;
        sm = 0;
        for(ll p = 1;; p++)
        {
            temp = tt/pow(5,p);
            if(temp == 0)break;
            sm += temp;
        }
        niche5 += sm;
        tt = r;
        sm = 0;
        for(ll p = 1;; p++)
        {
            temp = tt/pow(2,p);
            if(temp == 0)break;
            sm += temp;
        }
        niche2 += sm;
        ll dui,pach;
        //cout<<upore5<<sp<<upore2<<sp<<niche5<<sp<<niche2<<nl;
        pach = upore5 - niche5;
        dui = upore2 - niche2;
        ll ans = min(pach,dui);
        cout<<"Case "<<kas<<": ";
        cout<<ans<<nl;
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

