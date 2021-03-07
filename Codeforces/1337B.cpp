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
    int T;
    cin>>T;
    while(T--)
    {
        int x,n,m;
        cin>>x>>n>>m;
        while(x >= 20  && n)
        {
            //cout<<x<<endl;
            x = floor(x/2) + 10;
            n--;
        }
        while(m--)
        {
            //cout<<x<<endl;
            x = x-10;
        }
        if(n > 0 && x > 0)
        {
            while(n != 0)
            {
                //cout<<x<<endl;
                x = floor(x/2) + 10;
                n--;
            }
        }
        if(x<=0)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
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

