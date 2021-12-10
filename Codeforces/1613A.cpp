#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

long long oll = 0;
#define ll long long
#define ull unsigned long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = (int)a; i < (int)b; i++)
#define lf(i, b, a) for (ll i = (int)b; i >= (int)a; i--)
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
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.fi < b.fi;
}

int main()
{
    FIO;
#ifdef IHAVETOPEE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        ll x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        ll a1 = x1, a2 = x2;
        ll d1 = 0,d2 = 0;
        while (a1 % 10 == 0)
        {
            if(a1%10 == 0)p1++;
            else break;
            a1 /= 10;
        }
        while (a2 % 10 == 0)
        {
            if(a2%10 == 0)p2++;
            else break;
            a2 /= 10;
        }
        debug(a1);debug(a2);
        x1 = a1,x2 = a2;
        while (x1 != 0)
        {
            int temp = x1 % 10;
            x1 /= 10;
            d1++;
        }

        while (x2 != 0)
        {
            int temp = x2 % 10;
            x2 /= 10;
            d2++;
        }
        debug(d1+p1);debug(d2+p2);
        if(d1 + p1 < d2 + p2)cout<<"<\n";
        else if(d1+p1 > d2+p2)cout<<">\n";

        else {
            string s1,s2;
            ll t1 = a1,t2 = a2;
            while(t1 != 0){
                s1.pb('0' + t1%10);
                t1 /= 10;
            }
            reverse(all(s1));
            while(t2 != 0){
                s2.pb('0' + t2%10);
                t2 /= 10;
            }
            reverse(all(s2));
            debug(s1);
            debug(s2);

            int flag = 0;
            fl(i,0,min(s1.size(),s2.size())){
                if(s1[i] > s2[i]){
                    flag = 1;break;
                }
                if(s1[i] < s2[i]){
                    flag = 2;
                    break;
                }
            }
            debug(flag);
            if(flag == 0){
                if(s1.size() < s2.size())flag = 2;
                else if(s1.size() > s2.size())flag = 1;
            }
            if(flag== 0)cout<<"=\n";
            if(flag == 1)cout<<">\n";
            if(flag == 2)cout<<"<\n";
        }
        
    }
    return 0;
}
