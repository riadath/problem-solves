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

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}

int main()
{
    FIO;
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k,l,r,s1,s2;
    cin>>n>>k>>l>>r>>s1>>s2;
    vector <int> nums;
    int m = s2/k;
    int rem = s2%k;
    fl(i,0,rem){
        nums.pb(m+1);
    }
    fl(i,0,max(0,k-rem)){
        nums.pb(m);
    }
    r = m-1;
    int lft = n-k;
    int s = s1 - s2;
    if(s > 0 && lft > 0){
        m = s/lft;
        rem = s%lft;

        fl(i,0,rem){
            nums.pb(m+1);
        }
        fl(i,0,max(0,lft-rem)){
            nums.pb(m);
        }
    }
    fl(i,0,nums.size())cout<<nums[i]<<sp;
    cout<<nl;
    return 0;
}















