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
#define lf(i, a, b) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(), x.end())
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238


void solve()
{
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    map<int,bool>ws;
    vector <int> ls;
    fl(i,0,k){
        int x,y;
        cin>>x>>y;
        int temp = (x-1)*m + y;
        ws[(x-1)*m + y] = true;
        ls.pb(temp);
    }
    srt(ls);
    fl(i,0,q){
        int x,y;
        cin>>x>>y;
        int fil = (x-1)*m + y;
        if(ws[fil])cout<<"Waste"<<nl;
        else{
            int m = upper_bound(ls.begin(),ls.end(),fil) - ls.begin();
           // cout<<"fil: "<<fil<<" m: "<<m<<nl;
            fil -= (m+1);
            fil = fil%3;
            if(fil == 0)cout<<"Carrots"<<nl;
            else if(fil == 1)cout<<"Kiwis"<<nl;
            else cout<<"Grapes"<<nl;
        }
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

