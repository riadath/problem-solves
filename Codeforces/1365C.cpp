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
int a[500000],b[500000];
pii idxd[500000];
void solve()
{
    int n;
    cin>>n;
    fl(i,0,n){
        int x;
        cin>>x;
        a[x] = i+1;
    }
    fl(i,0,n){
        int x;
        cin>>x;
        b[x] = i+1;
    }
    fl(i,1,n+1){
       if(a[i] == b[i])idxd[i] = mp(0,0);
       else if(a[i] > b[i]){
            idxd[i].fi = a[i] - b[i];
            idxd[i].se = -1 * (n - a[i] + b[i]);
       }
       else{
            idxd[i].fi = n - b[i] + a[i];
            idxd[i].se = -1 * (b[i]-a[i]);
       }
    }
    map <int,int> occ_r,occ_l;
    fl(i,1,n+1){
        occ_r[idxd[i].fi]++;
        occ_l[idxd[i].se]++;
    }
    int cnr = -1e8,cnl = -1e8;
    for(auto i = occ_r.begin();i != occ_r.end();i++){
        cnr = max(cnr,i->se);
    }
    for(auto i = occ_l.begin();i != occ_l.end();i++){
        cnl = max(cnl,i->se);
    }
    int cn = max(cnr,cnl);
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

