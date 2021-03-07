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

ll f(int n)
{
    return pow(2,n)-1;
}

void solve()
{
    ll n;
    cin>>n;
    ll ans;
    for(ll i = 2;i < 31;i++){
        ll temp = f(i);
        //cout << temp << endl;
        if(n%temp == 0){
            ans = n/temp;
            break;
        }
    }
    cout << ans << "\n";
}

int main()
{
    FIO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
    solve();
    return 0;
}

