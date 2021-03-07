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
void solve()
{
    int n,m;
    cin>>n>>m;
    int arr[n+10];
    fl(i,0,n)cin>>arr[i];
    bool pos[n+10][n+10];
    MEM(pos,false);
    fl(i,0,m)
    {
        int tep;
        cin>>tep;
        pos[tep-1][tep] = true;
        pos[tep][tep-1] = true;
    }
    bool flag = true;
    fl(i,0,n)
    {
        fl(j,0,n-1-i)
        {
            if(arr[j] > arr[j+1])
            {
                if(!pos[j][j+1])
                {
                    flag = false;
                }

                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    if(flag)
        cout<<"YES"<<nl;
    else
        cout<<"NO"<<nl;
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

