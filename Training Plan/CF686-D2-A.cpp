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

void solve()
{
    ll n,x;
    cin>>n>>x;
    ll dk = 0;
    fl(i,0,n){
        char c;
        ll t;
        cin>>c>>t;
        if(c == '+')x += t;
        else if(c == '-'){
            if(t > x)dk++;
            else{
                x -= t;
            }
        }
    }
    cout<< x << " "<< dk << "\n";
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

