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

int rot(pii a,pii b,pii c)
{
    int ret = (a.fi*b.se+b.fi*c.se+c.fi*a.se)-(b.fi*a.se+c.fi*b.se+a.fi*c.se);
    if(ret == 0)return 0;
    if(ret > 0)return 1;
    if(ret < 0)return -1;
}
int dot(pii a,pii b,pii c,pii d)
{
    pii x = mp(a.fi - b.fi,a.se - b.se);
    pii y = mp(c.fi - d.fi,c.se - d.se);
    int ans = x.fi*y.fi + x.se*y.se;
    if(ans == 0)return true;
    return false;
}
int cross(pii a,pii b,pii c,pii d){
    pii x = mp(a.fi - b.fi,a.se - b.se);
    pii y = mp(c.fi - d.fi,c.se - d.se);
    int ans = x.fi*y.se - x.se*y.fi;
    if(ans == 0)return true;
    return false;
}

void solve()
{
    int T;
    cin>>T;
    int kas = 1;
    while(T--)
    {
        pii a,b,c,d;
        cin>>a.fi>>a.se>>b.fi>>b.se;
        cin>>c.fi>>c.se>>d.fi>>d.se;
        int kk = 40;
        if(rot(a,b,c) < 0)swap(b,c);
        if(rot(a,c,d) < 0)swap(c,d);
        if(rot(a,b,d) < 0)swap(b,d);
        if(rot(b,c,d) < 0)swap(c,d);
        if(rot(b,c,a) < 0)swap(c,a);
        if(rot(b,d,a) < 0)swap(d,a);
        if(rot(c,d,a) < 0)swap(d,a);
        if(rot(c,b,d) > 0)swap(b,d);
        if(rot(c,a,b) < 0)swap(a,b);
        if(rot(d,a,b) < 0)swap(a,b);
        if(rot(d,a,c) < 0)swap(a,c);
        if(rot(d,b,c) < 0)swap(b,c);

       /* cout<<"("<<a.fi<<sp<<a.se<<")"<<sp;
        cout<<"("<<b.fi<<sp<<b.se<<")"<<sp;
        cout<<"("<<c.fi<<sp<<c.se<<")"<<sp;
        cout<<"("<<d.fi<<sp<<d.se<<")"<<nl;*/
        db AB = dt(a,b);
        db BC = dt(b,c);
        db CD = dt(c,d);
        db DA = dt(d,a);
        cout<<"Case "<<kas++<<": ";
        if(AB == BC && BC == CD && CD == DA && DA == AB){
            if(dot(a,b,b,c)){
                cout<<"Square"<<nl;
                continue;
            }
            cout<<"Rhombus"<<nl;
            continue;
        }
        if(AB == CD && BC == DA){
            if(dot(a,b,b,c)){
                cout<<"Rectangle"<<nl;
                continue;
            }
            cout<<"Parallelogram"<<nl;
            continue;
        }
        if(cross(a,b,d,c) || cross(b,c,a,d)){
            cout<<"Trapezium"<<nl;
            continue;
        }
        cout<<"Ordinary Quadrilateral"<<nl;
    }

}

int main()
{
    FIO;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    solve();
    return 0;
}

