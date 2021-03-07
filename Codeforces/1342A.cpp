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

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        if(x>y)swap(x,y);
        ll cost = 0;
        ll cost1 = b*min(x,y) + a*(y-x);
        ll cost2 = a*(x+y);
        cost = min(cost1,cost2);
        cout << cost << endl;
    }
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

