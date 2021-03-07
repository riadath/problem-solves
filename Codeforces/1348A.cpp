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
    int T;
    cin>>T;
    while(T--)
    {
        ll n,total = 0;
        cin>>n;
        ll arr[n+2];
        fl(i,1,n+1){
            arr[i] = pow(2,i);
            total += arr[i];
        }
        ll a = 0,b = 0;
        for(int i = 1;i <= n/2 -1 ;i++)a += arr[i];
        a += arr[n];
        cout<<abs(total-2*a)<<nl;
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

