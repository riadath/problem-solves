#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define ull unsigned long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double,double>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, a, b) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(), x.end())

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,p;
        cin>>n>>p;
        int party[p];
        fl(i,0,p)cin>>party[i];
        bool days[n+1];
        MEM(days,false);
        int cn = 0;
        for(int i = 6; i <= n; i += 7)days[i] = true;
        for(int i = 7; i <= n; i += 7)days[i] = true;
        fl(i,0,p)
        {
            for(int j = party[i]; j <= n; j += party[i])
            {
                if(days[j] == false)
                {
                    cn++;
                    days[j] = true;
                }
            }
        }
        cout<<cn<<nl;
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

