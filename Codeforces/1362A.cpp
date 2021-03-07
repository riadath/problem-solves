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
    while(T--)
    {
        ll a,b;
        cin>>a>>b;
        if(a == b)cout<<0<<nl;
        else if(a%2 == 1 && b < a)cout<<-1<<nl;
        else if(a%2 == 1 && b%2 == 1)cout<<-1<<nl;
        else if(b < a && a/2 < b)cout<<-1<<nl;
        else if(b > a && b%a != 0)cout<<-1<<nl;
        else if(b < a && a%b != 0)cout<<-1<<nl;
        else
        {
            if(b > a)
            {
                ll tt = b/a;
                ll cn = 0;
                while(tt%8 == 0)
                {
                    tt = tt/8;
                    cn++;
                }
                while(tt%4==0)
                {
                    tt = tt/4;
                    cn++;
                }
                while(tt%2 == 0)
                {
                    tt = tt/2;
                    cn++;
                }
                if(tt == 1)cout<<cn<<nl;
                else cout<<-1<<nl;
            }
            else
            {
                ll tt = a/b;
                ll cn = 0;
                while(tt%8 == 0)
                {
                    tt = tt/8;
                    cn++;
                }
                while(tt%4==0)
                {
                    tt = tt/4;
                    cn++;
                }
                while(tt%2 == 0)
                {
                    tt = tt/2;
                    cn++;
                }
                if(tt == 1)cout<<cn<<nl;
                else cout<<-1<<nl;
            }
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
