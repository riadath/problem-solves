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
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool leap(int a)
{
    if(a%4 == 0 && a%100 != 0)return true;
    if(a%400 == 0)return true;
    return false;
}

void solve()
{
    ll x,d,m,y;
    while(cin>>x>>d>>m>>y &&(x||d||m||y)){
        ll rem = 0;
        rem += months[m] - d;
        fl(i,m+1,13){
            rem += months[i];
        }
        if(leap(y) && m <= 2)rem += 1;
        if(rem >= x){
            int nd = 0,nm = m;
            int ex = 0;
            if(leap(y) && m <= 2)ex++;
            if(x <= (months[m] - d + ex)){
                nd = d + x;
                cout<<nd<<sp<<m<<sp<<y<<nl;
                continue;
            }
            x -= (months[m] - d);
            x -= ex;
            nm++;
            //cout<<"-->"<<x<<nl;
            while(x > 0){
                x -= months[nm];
                if(x > 0)nm++;
            }
            x += months[nm];
            nd += x;
            cout<<nd<<sp<<nm<<sp<<y<<nl;
        }else{
            x -= rem;
            int nd = 0,nm = 1,ny = y+1;
            int ah = 0;
            while(ah < x){
                int d;
                if(leap(ny))d = 366;
                else d = 365;
                ah += d;
                if(ah < x)ny++;
                else{
                    ah -= d;
                    break;
                }
            }
            x -= ah;
            //cout<<"--->"<<x<<nl;
            //cout<<ny<<sp<<">>>"<<leap(ny)<<nl;
            while(x >= 0){
                if(leap(ny) && nm == 2)x -= 29;
                else x -= months[nm];
                //cout<<x<<nl;
                if(x > 0)nm++;
                else if(x == 0){
                    if(leap(ny) && nm == 2)nd = 29;
                    else nd = months[nm];
                    break;
                }
                else{
                   if(leap(ny) && nm == 2)x += 29;
                   else x += months[nm];
                   nd += x;
                   break;
                }
            }
            cout<<nd<<sp<<nm<<sp<<ny<<nl;
        }
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

