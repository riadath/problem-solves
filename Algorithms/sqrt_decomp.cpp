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
ll n,l,r,sgs,sgn,sgen,arr[100001],arr_sr[100001];
ll darr[10000],darr_sr[10000];
void pre_process()
{
    int st = -1;
    fl(i,0,n){
        if(i%sgs == 0)st++;
        darr[st] += arr[i];
        darr_sr[st] += arr_sr[i];
    }
}

ll sum_arr(ll op)
{
    ll seg_sum = 0,seg_sum2 = 0;
    while(l < r && l%sgs != 0){
        seg_sum += arr[l];
        seg_sum2 += arr_sr[l];
        l++;
    }
    while(l+sgs <= r){
        ll s = l/sgs;
        seg_sum += darr[s];
        seg_sum2 += darr_sr[s];
        l += sgs;
    }
    while(l <= r){
        seg_sum += arr[l];
        seg_sum2 += arr_sr[l];
        l++;
    }
    if(op == 1)return seg_sum;
    else return seg_sum2;
}

void solve()
{
    cin>>n;
    fl(i,0,n){
        cin>>arr[i];
        arr_sr[i] = arr[i];
    }

    sort(arr_sr,arr_sr+n);
    sgs = sqrt(n),sgn = n/sgs,sgen = sgn*sgs;
    pre_process();
    ll m;
    cin>>m;
    while(m--)
    {
        ll op;
        cin>>op>>l>>r;
        if(l == r)cout<<arr[l-1]<<nl;
        else{
            l--,r--;
            ll ans;
            ans = sum_arr(op);
            cout<<ans<<nl;
        }
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

