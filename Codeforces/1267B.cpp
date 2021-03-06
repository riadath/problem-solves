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
    string s;
    cin >> s;
    int val, ans, st = 0, en = s.size() - 1;
    for (; st <= en;)
    {
        val = 0;
        if (s[st] == s[en])
        {
            char c = s[st];
            while (s[st] == c)
            {
                st++;
                val++;
            }
            while (s[en] == c)
            {
                if (en < st)
                {
                    if (val >= 2)
                    {
                        cout << val + 1 << nl;
                    }
                    else
                    {
                        cout << 0 << nl;
                    }
                    return 0;
                }
                en--;
                val++;
            }
            if (val <= 2)
            {
                cout << 0 << nl;
                return 0;
            }
        }
        else
        {
            cout << 0 << nl;
            return 0;
        }
        // cout << st << sp << en << nl;
    }
    cout << 0 << nl;
    return 0;
}