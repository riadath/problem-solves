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

bool comp(const int a,const int b)
{
    return a > b;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

int rotation(pii a,pii b,pii c)
{
    int ret = (a.fi*b.se+b.fi*c.se+c.fi*a.se)-(b.fi*a.se+c.fi*b.se+a.fi*c.se);
    if(!ret)return ret;
    if(ret > 0)return 1;
    else return 2;
}

void solve()
{
    int T;
    cin>>T;
    int kas = 1;
    cout<<"INTERSECTING LINES OUTPUT"<<nl;
    while(T--)
    {
        pi4 a,b;
        cin>>a.fi.fi>>a.fi.se>>a.se.fi>>a.se.se;
        cin>>b.fi.fi>>b.fi.se>>b.se.fi>>b.se.se;
        int r1 = rotation(a.fi,a.se,b.fi);
        int r2 = rotation(a.fi,a.se,b.se);
        if((!r1 && !r2)){
            cout<<"LINE"<<nl;
            continue;
        }
        db m1,m2;
        db tt = (a.fi.fi - a.se.fi);
        if(tt == 0)m1 = 69.420;
        else m1 = (a.fi.se - a.se.se)/tt;
        tt = b.fi.fi - b.se.fi;
        if(tt == 0)m2 = 69.420;
        else m2 = (b.fi.se - b.se.se)/tt;
        if(m1 == m2){
            cout<<"NONE"<<nl;
            continue;
        }
        db p,q;

       /* cout<<"Case :"<<kas++<<nl;
        cout<<a.fi.fi<<sp<<a.fi.se<<", "<<a.se.fi<<sp<<a.se.se<<", ";
        cout<<b.fi.fi<<sp<<b.fi.se<<", "<<b.se.fi<<sp<<b.se.se<<nl;*/

        ll temp = (a.se.se-a.fi.se)*(b.fi.fi-b.se.fi)-(a.fi.fi-a.se.fi)*(b.se.se-b.fi.se);
        ll tp = (ll)(b.fi.fi-b.se.fi)*(ll)(a.fi.fi*a.se.se-a.fi.se*a.se.fi)-(ll)(a.fi.fi-a.se.fi)*(ll)(b.fi.fi*b.se.se-b.fi.se*b.se.fi);
        ll tq = (ll)(a.se.se-a.fi.se)*(ll)(b.fi.fi*b.se.se-b.fi.se*b.se.fi)-(ll)(b.se.se-b.fi.se)*(ll)(a.fi.fi*a.se.se-a.fi.se*a.se.fi);
        p = (db)tp/(db)temp;
        q = (db)tq/(db)temp;
        cout<<"POINT ";
        printf("%0.2lf %0.2lf\n",p,q);
    }
    cout<<"END OF OUTPUT"<<nl;
}

int main()
{
    //FIO;
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}


