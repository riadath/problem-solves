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
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int a,b;
        cin>>a>>b;
        string str;
        cin>>str;
        if((a+b)%2==0 && (a%2 || b%2)){
            cout<<-1<<nl;
            continue;
        }
        if((a+b)%2 && a%2 && b%2){
            cout<<-1<<nl;
            continue;
        }

        bool flag = true;
        int len = a + b;
        fl(i,0,len/2){
            if(str[i] != '?' && str[len - i -1] != '?'){
                if(str[len - i - 1] != str[i]){
                    flag = false;
                    break;
                }
            }
            else if(str[i] != '?'){
                str[len - i - 1] = str[i];
            }
            else if(str[len - i - 1] != '?'){
                str[i] = str[len - i - 1];
            }
        }

        if(!flag){
            cout<<-1<<nl;
            continue;
        }   

        int ac = 0,bc = 0;

        fl(i,0,len){
            if(str[i] == '0')ac++;
            if(str[i] == '1')bc++;
        }

        if(ac > a || bc > b){
            cout<<-1<<nl;
            continue;
        }

        fl(i,0,len/2){
            if(str[i] == '?' && str[len - i -1] == '?'){
                if(ac + 2 <= a)str[i] = str[len - i - 1] = '0',ac += 2;
                else if(bc + 2 <= b)str[i] = str[len - i - 1] = '1',bc += 2;
                else {
                    flag = false;
                    break;
                }
            }
        }
        if(str[len/2] == '?'){
            if(ac < a)str[len/2] = '0',ac++;
            else if(bc < b)str[len/2] = '1',bc++;
            else flag = false;
        }
        if(!flag || (ac > a) || (bc > b)){
            cout<<-1<<nl;
            continue;
        }
        cout<<str<<nl;
    }
    return 0;
}
