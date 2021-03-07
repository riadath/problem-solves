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
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, a, b) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(), x.end())

void solve()
{
    int n = 0;
    char cc;
    map <int,pdd> xr,yr;
    while(true){
        cin>>cc;
        if(cc == '*')break;
        double x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        xr[n] = mp(x1,x2);
        yr[n] = mp(y2,y1);
        n++;
    }
    double x,y;
    int pc = 1;
    while(cin>>x>>y){
        if(x == 9999.9 && y == 9999.9)break;
        bool isc = true;
        //cout<<"x: "<<x<<" y: "<<y<<nl;
        fl(i,0,n){
            if(x > xr[i].first && x < xr[i].second)
            if(y > yr[i].first && y < yr[i].second){
                isc = false;
                printf("Point %d is contained in figure %d\n",pc,i+1);
            }
        }
        if(isc){
            printf("Point %d is not contained in any figure\n",pc);
        }
        pc++;
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

