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
int fact[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    int pl = 0,mi = 0;
    fl(i,0,s1.size()){
        if(s1[i]=='+')pl++;
        if(s1[i]=='-')mi++;
    }
    int hp = 0,hm = 0,place = 0;
    fl(i,0,s2.size()){
        if(s2[i]=='+')hp++;
        if(s2[i]=='-')hm++;
        if(s2[i]=='?')place++;
    }
    hp = pl - hp;
    hm = mi - hm;
    if(hp < 0 || hm < 0){
        cout<<0.00000000000<<nl;
        return;
    }
    if(place == 0){
        if(hp == 0 && hm == 0){
            cout<<1.000000000000<<nl;
        }else{
            cout<<0.000000000000<<nl;
        }
        return;
    }
    double total = pow(2,place);
    double corr = fact[place]/(fact[hm]*fact[hp]);
    double ans = corr/total;
    cout<<setprecision(30)<<ans<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

