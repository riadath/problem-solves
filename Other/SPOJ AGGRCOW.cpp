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
ll n,k,arr[100010];
bool pos(ll d)
{
    int c = arr[0],cn = 1;
    fl(i,1,n)
    {
        if(arr[i] - c >= d)
        {
            cn++;
            c = arr[i];
        }
    }
    if(cn >= k)
        return true;
    else
        return false;
}

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        fl(i,0,n)cin>>arr[i];
        sort(arr,arr+n);
        ll h = 1000000001,l = 0,m;
        while(l < h-1)
        {
            m = (l+h)/2;
            if(pos(m))
                l = m;
            else
                h = m-1;
        }
        if(pos(h))
            cout<<h<<nl;
        else
            cout<<l<<nl;
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
