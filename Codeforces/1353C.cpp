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
#define fl(i, a, b) for (int i = a; i < b; i++)
#define lf(i, a, b) for (int i = b; i >= a; i--)
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
    while(T--){
        ll n;
        cin>>n;
        ll reach = n/2;
        ll sum = 0,ex = 0,co = 0;
        for(ll i = 0;i < n/2;i++){
            ex += (reach - i);
            sum += n*(reach - i);
            ll add = co*(co+1);
            sum += add;
            //cout<<sum<<nl;
            co++;

        }
        //cout<<sum<<" "<<ex<<nl;
        sum *= 2;
        ex *= 2;
        sum += ex;
        cout<<sum<<nl;
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

