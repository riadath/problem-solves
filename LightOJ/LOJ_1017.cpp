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
#define pdd pair<double, double>
#define pll pair<ll, ll>
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
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.second > b.second;
}
int n,k,w;
vector <ll> ycor;
int dp[200][200];
int f(int i,int j)
{
    if(i >= n){
        return 0;
    }
    if(dp[i][j] != -1)return dp[i][j];
    int a = 0,b = 0;
    a = f(i+1,j);
    if(j+1 <= k){
        int tot = 0,pl;
        fl(l,i,n){
            if(ycor[l] <= ycor[i]+w)tot++;
            else break;
        }
        b = tot + f(i+tot,j+1);
    }
    dp[i][j] = max(a,b);
    return dp[i][j];
}

int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int T, kas = 1;
    cin>>T;
    while (T--)
    {
        MEM(dp,-1);
        cin>>n>>w>>k;
        fl(i,0,n){
            int x,y;
            cin>>x>>y;
            ycor.pb(y);
        }
        srt(ycor);

        cout << "Case "<<kas++<<": ";
        cout << f(0,0) <<nl;
        ycor.clear();
    }
    return 0;
}
