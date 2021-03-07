#include <bits/stdc++.h>
using namespace std;

// #ifdef IHAVETOPEE
// #include "debug.h"
// #else
// #define debug(args...)
// #endif

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

int mat[109][109];
int n, m, k, cx, cy;
int dirx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int diry[] = {0, 0, 1, -1, 1, -1, -1, 1};
int zombi(int sx, int sy)
{
    int ret = 0, svx = sx, svy = sy;
    fl(l, 0, 8)
    {
        while (sx < n && sy < m)
        {
            sx += dirx[l], sy += diry[l];
            if (sx >= 0 && sx < n && sy >= 0 && sy < m)
            {
                ret += mat[sx][sy];
            }
            else
                break;
        }
        sx = svx, sy = svy;
    }
    return ret;
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
        MEM(mat, 0);
        cin >> n >> m >> k;
        fl(i, 0, k)
        {
            int x, y, w;
            cin >> x >> y >> w;
            mat[x - 1][y - 1] = w;
        }
        cin >> cx >> cy;
        int ax = cx, ay = cy;
        int mx = 0; // zombi(cx - 1, cy - 1);
        fl(i, 0, n) fl(j, 0, m)
        {
            // if (i == cx - 1 && j == cy - 1)
            //     continue;
            if (mat[i][j] == 0)
            {
                int temp = zombi(i, j);
                // cout << temp << nl;
                if (temp > mx)
                {
                    mx = temp;
                    ax = i + 1, ay = j + 1;
                }
            }
        }
        cout << "Case " << kas++ << ": ";
        cout << ax << sp << ay << nl;
    }
    return 0;
}
