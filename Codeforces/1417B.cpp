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
    return a.second > b.second;
}

int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        ll n, T;
        cin >> n >> T;
        ll arr[n + 10];
        fl(i, 0, n) cin >> arr[i];
        int group[n + 10];
        MEM(group, -1);
        map<ll, bool> flag, flag2;
        map<ll, int> cfreq, dfreq;
        fl(i, 0, n)
        {
            // cout << arr[i] << sp << flag[arr[i]] << nl;
            if (!flag[arr[i]])
            {
                group[i] = 1;
                cfreq[arr[i]]++;
                if (arr[i] <= T)
                {
                    flag[T - arr[i]] = true;
                }
            }
            else if (!flag2[arr[i]])
            {
                dfreq[arr[i]]++;
                group[i] = 0;
                if (arr[i] <= T)
                {
                    flag2[T - arr[i]] = true;
                }
            }
            else
            {
                if (cfreq[T - arr[i]] < dfreq[T - arr[i]])
                {
                    cfreq[arr[i]]++;
                    group[i] = 1;
                }
                else
                {
                    dfreq[arr[i]]++;
                    group[i] = 0;
                }
            }
        }
        // fl(i, 0, n)
        // {
        //     if (group[i] == -1)
        //     {
        //         if (arr[i] > T)
        //         {
        //             group[i] = 1;
        //         }
        //         else
        //         {
        //             if (cfreq[T - arr[i]] < dfreq[T - arr[i]])
        //             {
        //                 cfreq[arr[i]]++;
        //                 group[i] = 1;
        //             }
        //             else
        //             {
        //                 dfreq[arr[i]]++;
        //                 group[i] = 0;
        //             }
        //         }
        //     }
        // }
        fl(i, 0, n) cout << group[i] << sp;
        cout << nl;
    }
    return 0;
}
