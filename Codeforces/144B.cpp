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

double d(int x1,int y1,int x2,int y2)
{
    double ddis = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    return ddis;
}

void solve()
{
    int x1,y1,x2,y2,n;
    cin>>x1>>y1>>x2>>y2>>n;
    if(x2 < x1)swap(x1,x2);
    if(y2 < y1)swap(y1,y2);
    vector <pii> r;
    double rd[n];
    fl(i,0,n)
    {
        int x,y,z;
        cin>>x>>y>>z;
        r.pb(mp(x,y));
        rd[i] = z;
    }
    int cn = 0;
    for(int i = y1; i <= y2; i++)
    {
        int x = x1,y = i;
        bool flag = true;
        fl(j,0,n)
        {
            double dist = d(x,y,r[j].first,r[j].second);
            if(dist <= (double)rd[j])
            {
                flag = false;
                break;
            }
        }
        if(flag){
           // cout<<x<<" "<<y<<nl;
            cn++;
        }
    }
    for(int i = y1; i <= y2; i++)
    {
        int x = x2,y = i;
        bool flag = true;
        fl(j,0,n)
        {
            double dist = d(x,y,r[j].first,r[j].second);
            if(dist <= (double)rd[j])
            {
                flag = false;
                break;
            }
        }
        if(flag){
            //cout<<x<<" "<<y<<nl;
            cn++;
        }
    }
    for(int i = x1+1; i < x2; i++)
    {
        int x = i,y = y1;
        bool flag = true;
        fl(j,0,n)
        {
            double dist = d(x,y,r[j].first,r[j].second);
            if(dist <= (double)rd[j])
            {
                flag = false;
                break;
            }
        }
       if(flag){
           // cout<<x<<" "<<y<<nl;
            cn++;
        }
    }
    for(int i = x1+1; i < x2; i++)
    {
        int x = i,y = y2;
        bool flag = true;
        fl(j,0,n)
        {
            double dist = d(x,y,r[j].first,r[j].second);
            if(dist <= (double)rd[j])
            {
                flag = false;
                break;
            }
        }
        if(flag){
            //cout<<x<<" "<<y<<nl;
            cn++;
        }
    }
    cout<<cn<<nl;
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

