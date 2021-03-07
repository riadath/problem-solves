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
        ll n;
        cin>>n;
        if(n == 1)
        {
            cout<<0<<nl;
            continue;
        }
       /* else if(n == 3)
        {
            cout<<2<<nl;
            continue;
        }*/

        int cn = 0;
        while(n%6 == 0)
        {
            n /= 6;
            cn++;
        }
        //cout<<"--->"<<n<<nl;
        if(n == 1)
        {
            cout<<cn<<nl;
        }
        else if(n%3 == 0)
        {
            int pp = 0;
            while(n%3 == 0)
            {
                n /= 3;
                pp++;
            }
            if(n != 1)cout<<-1<<nl;
            else
            {
                cout<<cn+2*pp<<nl;
            }
        }
        else{
            cout<<-1<<nl;
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



