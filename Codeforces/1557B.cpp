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

bool comp(const pll &a, const pll &b)
{
    return a.fi < b.fi;
}

int main()
{
    FIO;
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<pll> arr(n);
        fl(i, 0, n){
             cin >> arr[i].first;
             arr[i].second = i;
        }
        int subs = 1;
        sort(all(arr),comp);
        fl(i,1,n){
            if(arr[i].second != arr[i-1].second + 1)subs++;
        }
        debug(subs);
        debug(arr);
        if (k < subs)
            cout<<"No"<<nl;
        else
            cout << "Yes" << nl;
    }
    return 0;
}
