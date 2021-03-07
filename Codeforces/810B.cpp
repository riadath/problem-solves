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

bool comp(const pll &a,const pll &b){
    int dif1 = min(2*a.first,a.second);
    dif1 = dif1 - a.first;
    int dif2 = min(2*b.first,b.second);
    dif2 = dif2 - b.first;
    return dif1 > dif2;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector <pll> arr;
    fl(i,0,n){
        ll x,y;
        cin>>x>>y;
        arr.pb(mp(x,y));
    }
    sort(arr.begin(),arr.end(),comp);
    //fl(i,0,n)cout<<arr[i].first<<"___"<<arr[i].second<<nl;
    ll sum = 0;
    fl(i,0,n){
        if(arr[i].first == 0)continue;
        else if(arr[i].first < arr[i].second && k > 0){
            sum += min(arr[i].second,2*arr[i].first);
            k--;
        }
        else sum += min(arr[i].first,arr[i].second);
    }
    cout<<sum<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

