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
///M
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
    scanf("%d",&T);
    int kas = 1;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        vector <ll> x,y;
        double BP = 0;
        int fx,fy;
        fl(i,0,n){
            int p,q;
            scanf("%d %d",&p,&q);
            if(i == 0){
                fx = p,fy = q;
            }
            x.pb(p);
            y.pb(q);
        }
        x.pb(fx),y.pb(fy);
        double area = 0,temp1 = 0,temp2 = 0;
        fl(i,0,x.size()-1){
            temp1 += x[i] * y[i+1];
        }
        fl(i,1,x.size()){
            temp2 += x[i] * y[i-1];
        }
        area = 0.5 * abs(temp1 - temp2);
        if(x[0] == x[n-1]){
            BP += abs(y[0] - y[n-1]) - 1;
        }
        else if(y[0] == y[n-1]){
            BP += abs(x[0] - x[n-1]) -1 ;
        }
        else{
            BP += __gcd(abs((x[0]-x[n-1])),abs(y[0]-y[n-1])) - 1;
        }
        fl(i,0,n-1){
            int x1 = x[i],y1 = y[i];
            int p = x[i+1],q = y[i+1];
            if(x1 == p){
                BP += abs(y1-q) - 1;
            }else if(y1 == q){
                BP += abs(x1-p) - 1;
            }
            else{
                BP += __gcd(abs(x1-p),abs(y1-q)) - 1;
            }
        }
        BP += n*1.0;
        BP /= 2.0;
        //cout<<">> "<<area<<sp<<BP<<nl;
        ll ans = area + 1 - BP;
        printf("Case %d: %lld\n",kas++,ans);
    }
}

int main()
{
     //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

