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
#define pll pair<ll,ll>
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
    int kas = 1;
    while(T--)
    {
        int n;
        cin>>n;
        pll arr[n];
        ll mnc = 1e12;
        ll mno = 1e12;
        fl(i,0,n)
        {
            cin>>arr[i].fi;
            mnc = min(arr[i].fi,mnc);
        }
        fl(i,0,n)
        {
            cin>>arr[i].se;
            mno = min(arr[i].se,mno);
        }
        ll mv = 0;
        fl(i,0,n){
            int d1 = arr[i].fi - mnc;
            int d2 = arr[i].se - mno;
            //cout<<d1<<sp<<d2<<nl;
            mv += min(d1,d2);
            mv += max(d1,d2) - min(d1,d2);

        }
        cout<<mv<<nl;
    }
    return 0;
}


