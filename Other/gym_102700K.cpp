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
    string str1, str2, l1, l2, n1, n2;
    cin >> str1 >> str2;
    fl(i, 0, str1.size())
    {
        if (str1[i] >= 'a' && str1[i] <= 'z')
            l1 += str1[i];
        if (str1[i] >= '0' && str1[i] <= '9')
            n1 += str1[i];
    }
    fl(i, 0, str2.size())
    {
        if (str2[i] >= 'a' && str2[i] <= 'z')
            l2 += str2[i];
        if (str2[i] >= '0' && str2[i] <= '9')
            n2 += str2[i];
    }
    // cout << l1 << sp << l2 << sp << n1 << sp << n2 << nl;
    if (l1 == l2 && n1 == n2)
        cout << '=' << nl;
    else if (l1 == l2 && n1 != n2)
    {
        // cout << "HERE" << nl;
        if (n1.size() > n2.size())
            cout << '>' << nl;
        else if (n1.size() < n2.size())
            cout << '<' << nl;
        else
        {
            fl(i, 0, n1.size())
            {
                if (n1[i] > n2[i])
                {
                    cout << '>' << nl;
                    break;
                }
                else if (n1[i] < n2[i])
                {
                    cout << '<' << nl;
                    break;
                }
            }
        }
    }
    else if (lexicographical_compare(all(l1), all(l2)))
        cout << '<' << nl;
    else
        cout << '>' << nl;
    return 0;
}