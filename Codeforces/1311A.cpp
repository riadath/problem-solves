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
#define srt(x) sort(x.begin(),x.end())

void solve()
{
    ll a,b;
    cin>>a>>b;
    if(a == b)cout<<0<<nl;
    else if(a < b){
        bool same;
        if(a%2 == b%2)same = true;
        else same = false;
        if(same)cout<<2<<nl;
        else cout<<1<<nl;
    }else{
        bool same;
        if(a%2 == b%2)same = true;
        else same = false;
        if(same)cout<<1<<nl;
        else cout<<2<<nl;
    }

}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}

