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
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>
#define all(a) a.begin(),a.end()

bool comp(const pair<int,pii> &a,const pair<int,pii> &b)
{
    if(a.se.se > b.se.se)return true;
    else if(a.se.se == b.se.se)return a.fi < b.fi;
    return false;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    vector <pair<int,pii>> arr;
    fl(i,0,n){
        int x,y;
        cin>>x>>y;
        arr.pb(mp(i+1,mp(x,y)));
    }
    sort(all(arr),comp);
    fl(i,0,n){
        cout<<arr[i].se.fi<<sp<<arr[i].se.se<<nl;;
    }
    return 0;
}















