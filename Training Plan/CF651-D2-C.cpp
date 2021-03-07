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
#define bs(x,y) binary_search(x.begin(),x.end(),y)


void solve()
{
    ll n;
    ll cnt = 0;
    cin>>n;
    unordered_map <ll,ll> x,y;
    unordered_map <string,ll> repeat;
    fl(i,0,n)
    {
        ll t1,t2;
        cin>>t1>>t2;
        x[t1]++;
        y[t2]++;
        repeat[to_string(t1)+","+to_string(t2)]++;
    }
    for(auto i = x.begin(); i != x.end(); i++)
    {
        ll t = i->second;
        cnt += t*(t-1)/2;
    }
    for(auto i = y.begin(); i != y.end(); i++)
    {
        ll t = i->second;
        cnt += t*(t-1)/2;
    }
    for(auto i = repeat.begin(); i != repeat.end(); i++)
    {
        ll t = i->second;
        cnt -= t*(t-1)/2;
    }
    cout << cnt << "\n";
}

int main()
{
    FIO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    solve();
    return 0;
}

