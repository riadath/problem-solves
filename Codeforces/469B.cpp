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
    int p,q,l,r;
    cin>>p>>q>>l>>r;
    map <int,bool> lx;
    vector <pii> lz;
    fl(i,0,p)
    {
        int x,y;
        cin>>x>>y;
        fl(j,x,y+1)lx[j] = true;
    }
    fl(i,0,q){
        int x,y;
        cin>>x>>y;
        lz.pb(mp(x,y));
    }
    int cn = 0;
    fl(i,l,r+1){
        fl(j,0,q){
            bool flag = false;
            int x = lz[j].fi,y = lz[j].se;
            fl(p,x,y+1){
                if(lx[p+i]){
                    cn++;
                    flag = true;
                    break;
                }
            }
            if(flag)break;
        }
    }
    cout<<cn<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

