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
#define all(a) a.begin(),a.end()

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}


int main()
{
    FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T;
    cin>>T;

    while(T--)
    {
        string ss;
        cin>>ss;
       // string c;
        int r = 0,p = 0,s = 0;
        fl(i,0,ss.size()){
            if(ss[i] == 'R')p++;
            if(ss[i] == 'P')s++;
            if(ss[i] == 'S')r++;
        }
        int mx = max(r,max(p,s));
       // cout<<mx<<nl;
        //cout<<r<<sp<<p<<sp<<s<<nl;
        char cc;
        if(mx == r)cc = 'R';
        else if(mx == p)cc = 'P';
        else cc = 'S';
        fl(i,0,ss.size())cout<<cc;
        cout<<nl;
    }
    return 0;
}














