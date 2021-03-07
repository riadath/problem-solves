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
   fl(kas,1,T+1){
        int n;
        cin>>n;
        vector<pii> xr,yr,zr;
        int xs = 1e5,xe = 1e5,ys = 1e5,ye = 1e5,zs = 1e5,ze = 1e5;
        fl(i,0,n){
            int x1,y1,z1,x2,y2,z2;
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            xr.pb(mp(x1,x2));
            yr.pb(mp(y1,y2));
            zr.pb(mp(z1,z2));
        }
        int mul = 1;
        fl(i,0,xr.size()){
            bool up = true,down = true;
            fl(j,0,xr.size()){
                if(xr[i].fi >= xr[j].fi && xr[i].fi <= xr[j].se){}
                else{
                    up = false;
                }
                if(xr[i].se >= xr[j].fi && xr[i].se <= xr[j].se){}
                else{
                    down = false;
                }
            }
            if(up){
                xs = xr[i].fi;
            }
            if(down){
                xe = xr[i].se;
            }
        }
        fl(i,0,yr.size()){
            bool up = true,down = true;
            fl(j,0,yr.size()){
                if(yr[i].fi >= yr[j].fi && yr[i].fi <= yr[j].se){}
                else{
                    up = false;
                }
                if(yr[i].se >= yr[j].fi && yr[i].se <= yr[j].se){}
                else{
                    down = false;
                }

            }
            if(up){
                ys = yr[i].fi;
            }
            if(down){
                ye = yr[i].se;
            }
        }
        fl(i,0,zr.size()){
            bool up = true,down = true;
            fl(j,0,zr.size()){
                if(zr[i].fi >= zr[j].fi && zr[i].fi <= zr[j].se){}
                else{
                    up = false;
                }
                if(zr[i].se >= zr[j].fi && zr[i].se <= zr[j].se){}
                else{
                    down = false;
                }
            }
            if(up){
                zs = zr[i].fi;
            }
            if(down){
                ze = zr[i].se;
            }
        }
       // cout<<xs<<" "<<xe<<" "<<ys<<" "<<ye<<" "<<zs<<" "<<ze<<nl;
        int volume = abs(xe-xs) * abs(ye-ys) * abs(ze-zs);
        cout<<"Case "<<kas<<": "<<volume<<nl;
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
