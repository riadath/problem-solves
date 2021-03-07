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
#define pi4 pair<pii,pii>

string stcm(string a,string b){
    if(a.size() > b.size())return a;
    if(a.size() < b.size())return b;
    fl(i,0,a.size()){
        if(a[i] < b[i])return a;
        if(b[i] < a[i])return b;
    }
    return a;
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T;
    cin>>T;
    for(int kase = 1; kase<=T; kase++)
    {
        string a,b;
        cin>>a>>b;
        string dp[111][111];
        fl(i,0,111)fl(j,0,111)dp[i][j] = "";
        int lena = a.size(),lenb = b.size();
        lf(i,lena-1,0)lf(j,lenb-1,0){
            if(a[i] == b[j]){
                dp[i][j] = a[i] + dp[i+1][j+1];
            }else{
                dp[i][j] = stcm(dp[i+1][j],dp[i][j+1]);
            }
        }
        cout<<"Case "<<kase<<": ";
        if(dp[0][0].size() == 0)cout<<":("<<nl;
        else {
            cout<<dp[0][0]<<nl;
        }
    }
    return 0;
}
