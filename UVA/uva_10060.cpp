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
    int n;
    while(cin>>n && n){
        db total_area = 0;
        fl(k,0,n){
            db t;
            cin>>t;
            vector <double> x,y;
            double x1,y1;
            cin>>x1>>y1;
            x.pb(x1),y.pb(y1);
            while(true){
                cin>>x1>>y1;
                if(x1 == x[0] && y1 == y[0]){
                    x.pb(x1),y.pb(y1);
                    break;
                }
                x.pb(x1),y.pb(y1);
            }
            db area = 0;
            int len = x.size();
            fl(i,0,len-1)area += x[i] * y[i+1];
            fl(i,1,len)area -= x[i]*y[i-1];
            area = abs(area);
            area /= 2.0;
            area *= t;
            total_area += area;
        }
        db r,th;
        cin>>r>>th;
        db mar = pi*r*r*th;
        //cout<<total_area<<sp<<mar<<nl;
        ll num = total_area/mar;
        cout<<num<<nl;
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

