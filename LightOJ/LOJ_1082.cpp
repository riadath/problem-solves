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
#define sp " ";
#define srt(x) sort(x.begin(), x.end())
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second

bool comp(const pii &a,const pii &b){
    return a.second < b.second;
}
double dt(double x1,double y1,double x2,double y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

int n,sz,ns;
int arr[100001], mxa[500];
void pre_process()
{
    sz = sqrt(n);
    if(ns%sz != 0)ns++;
    int st = -1;
    fl(i,0,n){
        if(i%sz == 0)st++;
        mxa[st] = min(mxa[st],arr[i]);
    }
}

int mn_value(int l,int r)
{
    int mn = 1e9;
    while(l < r && l%sz != 0){
        mn = min(arr[l],mn);
        l++;
    }
    while(l+sz <= r){
        int seg = l/sz;
        mn = min(mxa[seg],mn);
        l += sz;
    }
    while(l <= r){
        mn = min(arr[l],mn);
        l++;
    }
    return mn;
}

void solve()
{
    fl(i,0,500)mxa[i] = 1e9;
    int q;
    scanf("%d %d",&n,&q);
    fl(i,0,n)scanf("%d",&arr[i]);
    pre_process();
    fl(i,0,q){
        int l,r;
        scanf("%d %d",&l,&r);
        int ans = mn_value(l-1,r-1);
        printf("%d\n",ans);
    }
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int kase = 1;
    while(T--){
        printf("Case %d:\n",kase++);
        solve();
    }
    return 0;
}

