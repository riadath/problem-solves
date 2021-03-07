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
#define pid pair<int,double>
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

bool comp(const pid &a,const pid &b)
{
    if(a.se == b.se)return a.fi < b.fi;
    return a.se > b.se;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

void solve()
{
    int n,t1,t2;
    double k;
    cin>>n>>t1>>t2>>k;
    k = k/100.00;
    vector <pid>table;
    fl(i,0,n){
        int x,y;
        cin>>x>>y;
        double ans1,ans2;
        ans1 = t1*(x - x*k) + t2 * y;
        ans2 = t1*(y - y*k) + t2 * x;
        double ans = max(ans1,ans2);
        table.pb(mp(i+1,ans));
    }
    sort(table.begin(),table.end(),comp);
    fl(i,0,table.size()){
        printf("%d %0.2lf\n",table[i].fi,table[i].se);
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

