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
#define sp " ";
#define srt(x) sort(x.begin(), x.end())
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second

bool comp(const pii &a,const pii &b){
    return a.second < b.second;
}
double dt(double x1,double y1,double x2,double y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}


void solve()
{
    int T;
    cin>>T;
    while(T--){
        double r1,r2,r3;
        cin>>r1>>r2>>r3;
        double a,b,c,tri,v1,v2,v3;
        a = r1+r2,b = r1+r3,c = r2+r3;
        double s = (a+b+c)/2;
        tri = sqrt(s*(s-a)*(s-b)*(s-c));
        double ang1,ang2,ang3;
        ang1 = acos(((a*a + b*b) - (c*c))/(2*a*b));
        ang2 = acos(((a*a + c*c) - (b*b))/(2*a*c));
        ang3 = acos(((b*b + c*c) - (a*a))/(2*c*b));
        v1 = 0.5*r1*r1*ang1;
        v2 = 0.5*r2*r2*ang2;
        v3 = 0.5*r3*r3*ang3;
        double ans = tri - (v1+v2+v3);
        printf("%0.6lf\n",ans);
    }
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
