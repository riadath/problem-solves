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
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}
void solve()
{
    int T;
    cin>>T;
    fl(kas,1,T+1)
    {
        string s;
        cin>>s;
        int ans = 1e8;
        fl(i,0,s.size()){
            int l1 = 0,l0 = 0,r1 = 0,r0 = 0;
            fl(j,0,i){
                if(s[j] == '0')l0++;
                if(s[j] == '1')l1++;
            }
            fl(j,i,s.size()){
                if(s[j] == '0')r0++;
                if(s[j] == '1')r1++;
            }
            int temp = min(l0,l1) + min(r1,r0);
            ans = min(temp,ans);
        }
        cout<<ans<<nl;
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

