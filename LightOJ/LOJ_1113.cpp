#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args)
// #endif

// #pragma GCC target("avx2")
// #pragma GCC optimization("O3")
// #pragma GCC optimization("unroll-loops")

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
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
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
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        string cmd;
        cout << "Case " << kas++ << ":\n";
        string def = "http://www.lightoj.com/";
        stack<string>forward,backward;
        backward.push(def);
        while(true)
        {
            cin>>cmd;
            if(cmd == "QUIT")break;
            if(cmd[0] == 'V'){
                string web;
                cin>>web;
                cout<<web<<nl;
                backward.push(web);
                while(!forward.empty()){
                    forward.pop();
                }
            }

            else if(cmd[0] == 'B'){
               if(backward.size() <= 1){
                   cout<<"Ignored"<<nl;
               }else{
                   forward.push(backward.top());
                   backward.pop();
                   cout<<backward.top()<<nl;
               }
            }
            if(cmd[0] == 'F'){
                if(forward.size() == 0){
                    cout<<"Ignored"<<nl;
                }else{
                    cout<<forward.top()<<nl;
                    backward.push(forward.top());
                    forward.pop();
                }
            }
        }
        
    }
    return 0;
}
