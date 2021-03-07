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
    int n, k, cnt = 0;
    cin >> n >> k;
    string str, letter;
    fl(i, 0, k)
    {
        letter.pb('A' + i);
    }
    cin >> str;
    if (k == 2)
    {
        string temp1, temp2;
        char c1 = 'A', c2 = 'B';
        fl(i, 0, n)
        {
            temp1.pb(c1);
            temp2.pb(c2);
            if (c1 == 'A')
                c1 = 'B';
            else
                c1 = 'A';
            if (c2 == 'B')
                c2 = 'A';
            else
                c2 = 'B';
        }
        int cnt1 = 0, cnt2 = 0;
        fl(i, 0, n)
        {
            cnt1 += (temp1[i] != str[i]);
            cnt2 += (temp2[i] != str[i]);
        }
        if (cnt1 < cnt2)
        {
            cout << cnt1 << nl << temp1 << nl;
        }
        else
        {
            cout << cnt2 << nl << temp2 << nl;
        }
    }
    else
    {
        fl(i, 1, n - 1) if (str[i] == str[i - 1] && str[i] == str[i + 1])
        {
            str[i] = 'A' + (str[i] - 'A' + 1) % k;
            cnt++;
        }
        fl(i, 1, n)
        {
            bool done = false;
            if (!done && str[i] == str[i - 1])
            {
                fl(p, 0, k)
                {
                    if (letter[p] != str[i + 1] && letter[p] != str[i])
                    {
                        str[i] = letter[p];
                        cnt++;
                        break;
                    }
                }
            }
        }
        cout << cnt << nl << str << nl;
    }
    return 0;
}
