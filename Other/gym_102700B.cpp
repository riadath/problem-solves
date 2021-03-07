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
    string father, mother;
    cin >> father >> mother;
    vector<char> alpha;
    fl(i, 0, 26) alpha.pb('a' + i);
    reverse(all(alpha));
    int ft = -1, mt = -1;
    string ans = "";
    fl(i, 0, alpha.size())
    {
        bool flag = false;
        fl(k, 0, father.size())
        {
            if (father[k] == alpha[i])
            {
                if (ft == -1)
                {
                    ft = k;
                }
                else if (k != father.size() - 1)
                {
                    int iter = 1;
                    while (k + iter < (int)father.size())
                    {
                        if (father[ft + iter] == father[k + iter])
                        {
                            iter++;
                        }
                        else
                            break;
                    }
                    if (k + iter != (int)father.size())
                        if (father[ft + iter] < father[k + iter])
                        {
                            ft = k;
                        }
                    k += iter - 1;
                }
                flag = true;
            }
        }
        if (flag)
            break;
    }
    fl(i, 0, alpha.size())
    {
        bool flag = false;
        fl(k, 0, mother.size())
        {
            if (mother[k] == alpha[i])
            {
                if (mt == -1)
                {
                    mt = k;
                }
                else if (k != mother.size() - 1)
                {
                    int iter = 1;
                    while (k + iter < (int)mother.size())
                    {
                        if (mother[mt + iter] == mother[k + iter])
                        {
                            iter++;
                        }
                        else
                            break;
                    }
                    if (k + iter != (int)mother.size())
                        if (mother[mt + iter] < mother[k + iter])
                        {
                            mt = k;
                        }
                    k += iter - 1;
                }
                flag = true;
            }
        }
        if (flag)
            break;
    }
    ans.pb(father[ft++]);
    if (ft < (int)father.size())
        while (father[ft] >= mother[mt])
        {
            // if (ans.size() < 200000)
            ans.pb(father[ft]);
            // else
            //     break;
            if (ft + 1 < (int)father.size())
                ft++;
            else
                break;
        }
    fl(i, mt, (int)mother.size())
    {
        // if (ans.size() < 200000)
        ans.pb(mother[i]);
        // else
        //     break;
    }
    cout << ans << nl;
    return 0;
}