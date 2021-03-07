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
    string str, seq = "9876543210";
    int k;
    cin >> str >> k;
    fl(cur_pos, 0, str.size())
    {
        bool flag = true;
        fl(i, 0, 10)
        {
            fl(j, cur_pos + 1, str.size())
            {
                if (j == cur_pos)
                    continue;
                if (str[j] == seq[i] && k >= (j - cur_pos) && str[cur_pos] < str[j])
                {
                    // swap(str[j], str[cur_pos])
                    // cout << cur_pos + 1 << sp << j + 1 << nl;
                    if (cur_pos > j)
                    {
                        fl(pu, j, cur_pos) swap(str[pu], str[pu + 1]);
                    }
                    else
                    {
                        lf(pu, j, cur_pos + 1) swap(str[pu], str[pu - 1]);
                    }
                    k -= (j - cur_pos), flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (k <= 0)
            break;
    }
    cout << str << nl;
    return 0;
}
