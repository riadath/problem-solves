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
    int nr1;
    cin>>nr1;
    double R1 = -1e5 * 1.0;
    fl(i,0,nr1){
        double x;
        cin>>x;
        R1 = max(R1,x);
    }
    int np1;
    cin>>np1;
    double arr_p1[np1];
    fl(i,0,np1){
        cin>>arr_p1[i];
    }
    int np2;
    cin>>np2;
    double P2 = 1e5 * 1.0;
    fl(i,0,np2){
        double x;
        cin>>x;
        P2 = min(P2,x);
    }
    double A,B;
    cin>>A>>B;
    double R2 = -1e5 *1.0;
    fl(i,0,np1){
        int P1 = arr_p1[i];
        double tu,td,tt;
        tu = R1 * sqrt(B*P1);
        td = sqrt(B*P1 + A*P2);
        tt = tu/td;
        R2 = max(tt,R2);
    }
    cout<<setprecision(30)<<R2<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

