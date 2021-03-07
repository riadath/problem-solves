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
    string str;
    cin >> str;
    ll b, s, c, prb, ps, pc, r, nb = 0, ns = 0, nc = 0, cnt = 0;
    cin >> b >> s >> c >> prb >> ps >> pc >> r;
    fl(i, 0, str.size())
    {
        if (str[i] == 'B')
            nb++;
        if (str[i] == 'S')
            ns++;
        if (str[i] == 'C')
            nc++;
    }
    ll tot = 0;
    if (nb)
        tot += b;
    if (nc)
        tot += c;
    if (ns)
        tot += s;
    while (tot != oll)
    {
        ll cb, cs, cc;
        if (nb != 0)
            cb = b / nb;
        else
            cb = 1e12;
        if (ns != 0)
            cs = s / ns;
        else
            cs = 1e12;
        if (nc != 0)
            cc = c / nc;
        else
            cc = 1e12;
        ll mnt = min(cb, min(cs, cc));
        // if (mnt == cb)
        // {
        b -= nb * mnt;
        s -= ns * mnt;
        c -= nc * mnt;
        cnt += mnt;
        ll mmo = max(oll, (nb - b)) * prb + max(oll, ns - s) * ps + max(oll, nc - c) * pc;
        if (mmo > r)
        {
            break;
        }
        else
        {
            cnt += 1;
            r -= mmo;
            b = max(oll, b - nb), s = max(oll, s - ns), c = max(oll, c - nc);
        }
        tot = 0;
        if (nb)
            tot += b;
        if (nc)
            tot += c;
        if (ns)
            tot += s;
    }
    cnt += r / (nb * prb + ns * ps + nc * pc);
    cout << cnt << nl;
    // }
    // else if (mnt == cs)
    // {
    //     b -= nb * cs;
    //     s -= ns * cs;
    //     c -= nc * cs;
    // }
    // else
    // {
    //     b -= nb * cc;
    //     s -= ns * cc;
    //     c -= nc * cc;
    // }
    return 0;
}
