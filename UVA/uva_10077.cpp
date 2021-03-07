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
#define pll pair<long, long>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>
#define all(a) a.begin(),a.end()

bool comp(const pll &a,const pll &b)
{
    return a.second >= b.second;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(cin>>n>>m && !(n == 1 && m == 1)){
        pii cur = mp(1,1);
        pii lt = mp(0,1);
        pii rt = mp(1,0);
        string ans = "";
        while(true){
            if(cur.fi == n && cur.se == m)break;
            if(cur.fi*m > cur.se*n){
                ans.pb('L');
                rt.fi = cur.fi;
                rt.se = cur.se;
                cur.fi += lt.fi;
                cur.se += lt.se;
            }
            else{
                ans.pb('R');
                lt.fi = cur.fi;
                lt.se = cur.se;
                cur.fi += rt.fi;
                cur.se += rt.se;
            }
        }
        cout<<ans<<nl;
    }
    return 0;
}















