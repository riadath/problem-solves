#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(int i = a;i < b;i++)
#define lf(i,a,b) for(int i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
void solve()
{
    ll n;
    cin>>n;
    map <ll,ll> arr;
    ll cn = 1;
    fl(i,0,n){
        ll temp;
        cin>>temp;
        arr[temp] = cn++;
    }
    ll m;
    cin>>m;
    ll vas = 0,pet = 0;
    fl(i,0,m){
        ll temp;
        cin>>temp;
        vas += arr[temp];
        pet += n - arr[temp] + 1;
    }
    cout<<vas<<" "<<pet<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}









