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
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    int mn = n*(a-b);
    int mx = n*(a+b);
    bool flag = false;
    int rn = c-d;
    int rx = c+d;

    if(mn<rn && mx<rn)flag = false;
    else if(mn > rx && mx>rx)flag = false;
    else flag = true;

    if(flag)cout << "YES\n";

    else cout << "NO\n";
}

int main()
{
    FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}

