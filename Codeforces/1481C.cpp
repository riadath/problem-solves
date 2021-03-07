#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
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
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr, brr, crr;
        map<ll, int> avail;
        vector<int> avB[n + 1];
        queue<int> need[n + 1];
        fl(i, 0, n)
        {
            int pp;
            cin >> pp;
            arr.pb(pp);
        }
        fl(i, 0, n)
        {
            int pp;
            cin >> pp;
            brr.pb(pp);
            avB[brr[i]].pb(i + 1);
        }
        fl(i, 0, m)
        {
            int pp;
            cin >> pp;
            crr.pb(pp);
            avail[crr[i]]++;
        }
        int flag = 1, idx = m - 1;
        fl(i, 0, n)
        {
            if (arr[i] != brr[i] && (int)avail[brr[i]] < (int)need[brr[i]].size() + 1)
            {
                flag = 0;
                break;
            }
            if (arr[i] != brr[i])
            {
                need[brr[i]].push(i + 1);
            }
        }
        if (flag)flag = ((int)avB[crr[m - 1]].size() > 0);
        if(need[crr[m-1]].size() > 0){
            idx = need[crr[m-1]].front();
            need[crr[m-1]].pop();
        }
        else{
            fl(i,0,n){
                if(brr[i] == crr[m-1]){
                    idx = i+1;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << "NO" << nl;
            continue;
        }
        cout << "YES" << nl;
        fl(i, 0, m)
        {

            if ((int)need[crr[i]].size() == 0)
            {
                cout << idx << sp;
            }
            else
            {
                cout << need[crr[i]].front() << sp;
                need[crr[i]].pop();
                // cout << need[crr[i]].size() << nl;
            }
        }
        cout << nl;
    }
    return 0;
}
