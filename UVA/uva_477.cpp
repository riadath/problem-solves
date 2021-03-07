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

struct data
{
    string what;
    db a,b,c,d,e,f;
};
bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(db x1,db y1,db x2,db y2)
{
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
    vector <data> shps;
    string tt;
    while(true)
    {
        cin>>tt;
        if(tt[0] == '*')break;
        if(tt[0] == 'r')
        {
            db x,y,p,q;
            cin>>x>>y>>p>>q;
            data temp;
            temp.what = tt;
            temp.a = min(x,p);
            temp.b = max(x,p);
            temp.c = min(y,q);
            temp.d = max(y,q);
            shps.pb(temp);
        }
        if(tt[0] == 'c')
        {
            db x,y,r;
            cin>>x>>y>>r;
            data temp;
            temp.what = tt;
            temp.a = x;
            temp.b = y;
            temp.c = r;
            shps.pb(temp);
        }
    }
    double x,y;
    int pc = 1;
    while(cin>>x>>y)
    {
        if(x == 9999.9 && y == 9999.9)break;
        bool flag = true;
        fl(i,0,shps.size()){
            if(shps[i].what[0] == 'c')
            {
                db ds = dt(shps[i].a,shps[i].b,x,y);
                if(ds < shps[i].c)
                {
                    flag = false;
                    printf("Point %d is contained in figure %d\n",pc,i+1);
                }
            }
            if(shps[i].what[0] == 'r'){
                if(x > shps[i].a && x < shps[i].b)
                if(y > shps[i].c && y < shps[i].d){
                    flag = false;
                    printf("Point %d is contained in figure %d\n",pc,i+1);
                }
            }
        }
        if(flag)
        {
            printf("Point %d is not contained in any figure\n",pc);
        }
        pc++;
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

