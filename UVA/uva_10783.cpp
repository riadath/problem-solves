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


bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(db x1,db y1,db x2,db y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

db tra(pdd a,pdd b,pdd c)
{
    db temp = 0;
    temp += a.fi*b.se+b.fi*c.se+c.fi*a.se;
    temp -= b.fi*a.se+c.fi*b.se+a.fi*c.se;
    temp = abs(temp);
    temp /= 2.0;
    return temp;
}

void solve()
{
    int T;
    cin>>T;
    int kas = 1;
    while(T--){
        int a,b;
        cin>>a>>b;
        if(a%2 == 0)a++;
        if(b%2 == 0)b--;
        int sum = 0;
        for(int i = a;i <= b;i += 2)
            sum += i;
        cout<<"Case "<<kas++<<": ";
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
