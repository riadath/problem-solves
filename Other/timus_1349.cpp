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
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    if(n > 2){
        cout<<-1<<nl;
    }
    else{
        bool flag = false;
        if(n == 0)cout<<-1<<nl;
        else if(n == 1){
            cout<<1<<sp<<2<<sp<<3<<nl;
        }
        else {
            cout<<3<<sp<<4<<sp<<5<<nl;
        }
    }
    return 0;
}















