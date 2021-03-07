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

///K

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

bool collinear(pii a,pii b,pii c)
{
    if((c.fi >= min(a.fi,b.fi) && c.fi <= max(a.fi,b.fi))
       &&(c.se >= min(a.se,b.se) && c.se <= max(a.se,b.se)))
        return true;
    return false;
}

int rotation(pii a,pii b,pii c)
{
    int ret = (a.fi*b.se+b.fi*c.se+c.fi*a.se)-(b.fi*a.se+c.fi*b.se+a.fi*c.se);
    if(!ret)return ret;
    if(ret > 0)return 1;
    else return 2;
}

bool exist(pi4 a,pi4 b)
{
    int r1,r2,r3,r4;
    r1 = rotation(a.fi,a.se,b.fi);
    r2 = rotation(a.fi,a.se,b.se);
    r3 = rotation(b.fi,b.se,a.fi);
    r4 = rotation(b.fi,b.se,a.se);
    if(r1 != r2 && r3 != r4)return true;
    if(r1 == 0)
    {
        bool flag = collinear(a.fi,a.se,b.fi);
        if(flag)return true;
    }
    if(r2 == 0){
        bool flag = collinear(a.fi,a.se,b.se);
        if(flag)return true;
    }
    if(r3 == 0){
        bool flag = collinear(b.fi,b.se,a.fi);
        if(flag)return true;
    }
    if(r4 == 0){
         bool flag = collinear(b.fi,b.se,a.se);
        if(flag)return true;
    }
    return false;
}

void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        pi4 ar[n];
        fl(i,0,n)
        {
            int x,y;
            cin>>x>>y;
            ar[i].fi = (mp(x,y));
            cin>>x>>y;
            ar[i].se = (mp(x,y));
        }
        int cn = 0;
        fl(i,0,n)
        {
            bool flag = true;
            pi4 p1,p2;
            p1 = ar[i];
            fl(j,0,n)
            {
                if(j == i)continue;
                p2 = ar[j];
                if(exist(p1,p2))
                {
                    flag = false;
                    break;
                }
            }
            if(flag)cn++;
        }
        cout<<cn<<nl;
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

