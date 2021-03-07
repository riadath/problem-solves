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
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>
#define all(a) a.begin(),a.end()

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        ll l,r,m;
        cin>>l>>r>>m;
        ll a,b,c;
        fl(k,l,r+1)
        {
            a = k;
            if(m%a == 0)
            {
                b = a;
                c = a;
            }
            else
            {
                ll rem = 0;
                if(m < a)
                {
                    rem = a - m;
                    c = l + rem;
                    b = l;
                }
                else
                {
                    ll base = m/a;
                    ll hei = base+1;
                    rem = min(m - a*base,a*hei - m);
                    //cout<<a<<sp<<base<<sp<<hei<<sp<<rem<<nl;
                    if(rem == m-a*base)
                    {
                        c = l;
                        b = l + rem;
                        if(b <= r && c <= r)
                        {
                            cout<<a<<sp<<b<<sp<<c<<nl;
                            break;
                        }

                    }
                    if(rem == a*hei - m)
                    {
                        b = l;
                        c = l + rem;
                        if(b <= r && c <= r)
                        {
                            cout<<a<<sp<<b<<sp<<c<<nl;
                            break;
                        }
                    }
                }
            }
            if(b <= r && c <= r)
            {
                cout<<a<<sp<<b<<sp<<c<<nl;
                break;
            }
        }
    }
    return 0;
}















