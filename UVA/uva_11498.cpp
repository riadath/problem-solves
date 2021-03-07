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

bool if_pal(string temp)
{
    for(int i = 0,j = temp.size()-1;i < temp.size()/2;i++,j--){
        if(temp[i] != temp[j])return false;
    }
    return true;
}

void solve()
{
   int k;
   while(cin>>k && k){
        int n,m;
        cin>>n>>m;
        fl(i,0,k){
            int x,y;
            cin>>x>>y;
            x -= n,y -= m;
            if(x==0 || y == 0)cout<<"divisa"<<nl;
            if(x > 0 && y > 0)cout<<"NE"<<nl;
            if(x < 0 && y > 0)cout<<"NO"<<nl;
            if(x > 0 && y < 0)cout<<"SE"<<nl;
            if(x < 0 && y < 0)cout<<"SO"<<nl;
        }
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
