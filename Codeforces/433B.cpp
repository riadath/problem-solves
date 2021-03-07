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
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, a, b) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(), x.end())

///balsal trail code


void solve()
{
    ll n,l,r;
    cin>>n;
    ll arr[n],arr_sr[n];
    ll asum[n],ssum[n];
    MEM(asum,0);
    MEM(ssum,0);
    fl(i,0,n){
        cin>>arr[i];
        arr_sr[i] = arr[i];
    }
    sort(arr_sr,arr_sr+n);
    asum[0] = arr[0],ssum[0] = arr_sr[0];
    fl(i,1,n){
        asum[i] = arr[i] + asum[i-1];
        ssum[i] = arr_sr[i] + ssum[i-1];
    }
    ll m;
    cin>>m;
    while(m--)
    {
        ll op;
        cin>>op>>l>>r;
        l--,r--;
        ll ans = 0;
        if(op == 1){
            if(l == 0)ans = asum[r];
            else ans = asum[r] - asum[l-1];
        }
        else if(op == 2){
            if(l == 0)ans = ssum[r];
            else ans = ssum[r] - ssum[l-1];
        }
        cout<<ans<<nl;
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

