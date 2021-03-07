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
    int ans = -1;
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            int temp;
            cin>>temp;
            //cout <<temp <<endl;
            if(temp == 1)
            {
                ans = abs(3-i) + abs(3-j);
                break;
            }
        }

    }
    cout << ans << "\n";
}

int main()
{
    //FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    solve();
    return 0;
}

