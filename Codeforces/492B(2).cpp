#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(ll i = a;i < b;i++)
#define lf(i,a,b) for(ll i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(),x.end())
int n;
long double l, arr[1010];
void solve()
{
    cin>>n>>l;
    fl(i,0,n)cin>>arr[i];
    sort(arr,arr+n);
    long double cur = max(arr[0],l-arr[n-1]);
    fl(i,1,n){
        cur = max(cur,(arr[i]-arr[i-1])/2.0);
    }
    cout<<setprecision(13)<<cur<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

