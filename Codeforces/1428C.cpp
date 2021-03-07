#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
#endif

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
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        bool flag = true;
        while (flag)
        {
            int del = 0;
            fl(i, 0, (int)s.size() - 1)
            {
                if ((s[i] == 'A' && s[i + 1] == 'B'))
                {
                    s[i] = 'x', s[i + 1] = 'x';
                    if (i > 0 && i + 2 < (int)s.size())
                    {
                        int l = i - 1, r = i + 2;
                        while (s[l] == 'A' && s[r] == 'B')
                        {
                            s[l] = 'x', s[r] = 'x';
                            if (l > 0 && r < (int)s.size() - 1)
                            {
                                l--, r++;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    del++;
                }
            }
            string temp;
            // cout << s << nl << nl << nl << nl << nl;
            fl(i, 0, (int)s.size()) if (s[i] != 'x') temp += s[i];
            s = temp;
            if (del == 0)
                flag = false;
        }
        flag = true;
        while (flag)
        {
            int del = 0;
            fl(i, 0, (int)s.size() - 1)
            {
                if ((s[i] == 'B' && s[i + 1] == 'B'))
                {
                    s[i] = 'x', s[i + 1] = 'x';
                    del++;
                }
            }
            string temp;
            // cout << s << nl << nl << nl << nl << nl;
            fl(i, 0, (int)s.size()) if (s[i] != 'x') temp += s[i];
            s = temp;
            if (del == 0)
                flag = false;
        }

        cout << (int)s.size() << nl;
    }
    return 0;
}
