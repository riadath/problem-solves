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
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int x;
        cin >> x;
        map<int, vector<int>> store;
        int chek[51];
        MEM(chek, 0);
        for (int bt = 0; bt < 1 << 10; bt++)
        {
            int sum = 0;
            vector<int> temp;
            for (int i = 0; i < 10; i++)
            {
                if (bt & (1 << i))
                {
                    sum += arr[i];
                    temp.pb(arr[i]);
                }
            }
            chek[sum] = 1;
            store[sum] = temp;
        }

        if (chek[x])
        {
            sort(all(store[x]));
            fl(i, 1, store[x].size()) cout << store[x][i];
            cout << nl;
        }
        else
        {
            cout << -1 << nl;
        }
    }
    return 0;
}
