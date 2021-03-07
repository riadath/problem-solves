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
        string str, fri, sce;
        cin >> str;
        fl(i, 0, str.size())
        {
            if (str[i] == '(' || str[i] == ')')
                fri.pb(str[i]);
            else
                sce.pb(str[i]);
        }
        int cntfr = 0, cntsc = 0;
        int uc = 0;
        // cout<<fri<<sp<<sce<<nl;
        fl(i, 0, fri.size())
        {
            int cur = i;
            if (fri[i] == ')')
            {
                // cout << uc << nl;
                if (uc > 0)
                {
                    while (uc > 0 && fri[i] == ')')
                    {
                        uc--, cntfr++;
                        if (i + 1 < fri.size())
                            i++;
                        else
                            break;
                    }
                }
                if (fri[i] == '(')
                    i--;
            }
            else
            {
                while (fri[i] == '(')
                {
                    uc++;
                    if (i + 1 < fri.size())
                        i++;
                    else
                        break;
                }
                if (fri[i] == ')')
                    i--;
            }
        }
        uc = 0;
        fl(i, 0, sce.size())
        {
            int cur = i;
            if (sce[i] == ']')
            {
                if (uc > 0)
                {
                    while (uc > 0 && sce[i] == ']')
                    {
                        uc--, cntsc++;
                        if (i + 1 < sce.size())
                            i++;
                        else
                            break;
                    }
                }
                if (sce[i] == '[')
                    i--;
            }
            else
            {
                while (sce[i] == '[')
                {
                    uc++;
                    if (i + 1 < sce.size())
                        i++;
                    else
                        break;
                }
                if (sce[i] == ']')
                    i--;
            }
        }
        cout << cntfr + cntsc << nl;
    }
    return 0;
}
