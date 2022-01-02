#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = (int)a; i < (int)b; i++)
#define MEM(x, y) memset(x, y, sizeof(x))
#define PI acos(0)*2
#define fi first
#define se second
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b){return a.fi < b.fi;}

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    double a,b,m,vx,vy,vz;
    cin>>a>>b>>m>>vx>>vy>>vz;

    double cx = a/2.0,cy = m,cz = 0;
    while(true){
        double tx = cx ,ty = cy ,tz = cz ;
        debug(cx);debug(cy);debug(cz);
        debug(vx);debug(vz);


        string str = "__________";
        
        cx += vx,cy += vy,cz += vz;
        
        bool dox = ((cx - a) > 0.00000001 || cx < 0.0);
        bool doz = ((cz - b) > 0.00000001 || cz < 0.0);
        bool doy = cy < 0.00000001;
        debug(dox);debug(doy);debug(doz);

        if(dox + doz + doy > 1){
            double dis_x,dis_z,dis_y;
            if((cx - a) > 0.00000001)dis_x = abs(tx - a);
            else dis_x = tx;
            if((cz - b) > 0.00000001)dis_z = abs(tz - b);
            else dis_z = tz;

            dis_x = abs(dis_x/vx);
            dis_z = abs(dis_z/vz);
            dis_y = abs(ty/vy);
            
            debug(dis_x);debug(dis_y);debug(dis_z);
            
            if(((dis_y - dis_z) < 0.00000001 || !doz) && 
            ((dis_y - dis_x) < 0.00000001 || !dox) && doy)
                doz = dox = false;

            else if(((dis_z - dis_y) < 0.00000001 || !doy) 
            && ((dis_z - dis_x) < 0.00000001 || !dox) && doz)
                dox = doy = false;

            else if(((dis_x - dis_y) < 0.00000001 || !doy) 
            && ((dis_x - dis_z) < 0.00000001 || !doz) && dox)
                doz = doy = false;
        }

        debug(dox);debug(doy);debug(doz);
        if(doy){
            double t = abs(ty/vy);
            cx = tx + t * vx;
            cz = tz + t * vz;
            cy = 0.0;
            break;
        }

        else if(dox){
            double t;
            if((cx - a) > 0.00000001){
                cx = a;
                t = abs(abs(cx - tx)/vx);
            }
            else{
                cx = 0;
                t = abs(tx/vx);
            }
            cz = tz + t * vz;
            cy = ty + t * vy;
            vx *= -1;
        }
        else if(doz){
            double t;
            if((cz - b) > 0.00000001){
                cz = b;
                t = abs(abs(cz - tz)/vz);
            }else{
                cz = 0;
                t = abs(tz/vz);
            }

            cx = tx + t * vx; 
            cy = ty + t * vy;

            vz *= -1;
        }
        
        debug(str);
    }
    cout<<fixed<<setprecision(10)<<cx<<" "<<cz<<"\n";
    return 0;
}