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
    while(T--){
        ll r,g,b,w;
        cin>>r>>g>>b>>w;
        int odd = 0;
        if(r%2)odd++;
        if(g%2)odd++;
        if(b%2)odd++;

        bool zero;
        if(!r || !g || !b)zero = true;
        else zero = false;

        if(!r && !g && !b && !w)cout<<"Yes"<<nl;
        else{
            if(odd == 0)cout<<"Yes"<<nl;
            else if(odd == 1 && w%2 == 0)cout<<"Yes"<<nl;
            else if(zero && (odd + w%2) > 1)cout<<"No"<<nl;
            else{
                if(w%2){
                    if(odd == 2 || odd == 3)cout<<"Yes"<<nl;
                    else cout<<"No"<<nl;
                }else{
                    if(odd == 3)cout<<"Yes"<<nl;
                    else cout<<"No"<<nl;
                }
            }
        }
    }
    return 0;
}















