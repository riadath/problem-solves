
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

void solve()
{
   ll l,r;
   cin>>l>>r;
   if(r-l+1 < 3)cout<<-1<<nl;
   else{
    for(ll i = l;i<=r;i++)for(ll j = i+1;j<=r;j++)
        for(ll k = j+1;k<=r;k++){
        if(__gcd(i,j)==1 && __gcd(j,k)==1 && __gcd(i,k) != 1){
            cout<<i<<" "<<j<<" "<<k<<nl;
            return;
        }
    }
    cout<<-1<<nl;
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
