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

#define sz 10000100
vector <int>  prime_list;
bool flag[10001000];

void sieve()
{
    flag[0] = true,flag[1] = true;
    for(int i = 4;i <= sz;i += 2)flag[i] = true;
    for(int i = 3;i <= sz;i += 2){
        for(int j = 2;i*j <= sz;j++){
            flag[i*j] = true;
        }
    }

    fl(i,0,sz)if(!flag[i])prime_list.pb(i);
}
int kas = 1;
void solve()
{
    int n;
    scanf("%d",&n);
    int cn = 0;
    for(int i = 0;prime_list[i] <= n/2;i++){
        int t = prime_list[i];
        if(!flag[n-t]){
            cn++;
        }
    }
    printf("Case %d: %d\n",kas++,cn);
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout)
    sieve();
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}
