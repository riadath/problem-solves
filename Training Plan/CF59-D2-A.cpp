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
    string a;
    cin>>a;
    int num_u = 0,num_l = 0;
    fl(i,0,a.size())
    {
        if(a[i] >= 65 && a[i] <= 91)
        {
            num_u++;
        }
        else
        {
            num_l++;
        }
    }
    if(num_u > num_l)
    {
        fl(i,0,a.size())
        {
            if(a[i] >= 97 && a[i] <= 123)
            {
                a[i] -= 32;
            }
        }
    }
    else
    {
        fl(i,0,a.size())
        {
            if(a[i] >= 65 && a[i] <= 91)
            {
                a[i] += 32;
            }
        }
    }
    cout << a << "\n";
}

int main()
{
    FIO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    solve();
    return 0;
}
