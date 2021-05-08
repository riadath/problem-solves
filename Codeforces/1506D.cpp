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
    return a.se > b.se;
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
        int n;
        cin>>n;
        vector<ll>arr(n);
        map<ll,int>cnt;
        fl(i,0,n){
            cin>>arr[i];cnt[arr[i]]++;
        }
        priority_queue<int>occur;
        for(auto i : cnt){
            occur.push(i.se);
        }
        while(occur.size() > 1){
            // debug(occur.size());
            int tp1 = occur.top();
            occur.pop();
            int tp2 = occur.top();
            occur.pop();
            tp1--,tp2--;
            if(tp1 > 0)
                occur.push(tp1);
            if(tp2 > 0)
                occur.push(tp2);
        }
        int ans = 0;
        while(!occur.empty()){
            ans += occur.top();
            occur.pop();
        }
        cout<<ans<<nl;
    }
    return 0;
}