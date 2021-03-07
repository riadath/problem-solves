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
    return a.fi < b.fi;
}

int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int w, h, n;
    int kas = 1;
    while (true)
    {
        scanf("%d %d %d", &w, &h, &n);
        if (!w && !h && !n)
            break;
        int arr[w + 10][h + 10];
        MEM(arr, 0);
        for (int l = 0; l < n; l++)
        {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            for (int i = min(x1, x2); i <= max(x1, x2); i++)
            {
                for (int j = min(y1, y2); j <= max(y1, y2); j++)
                {
                    arr[i][j] = 1;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= w; i++)
        {
            for (int j = 1; j <= h; j++)
            {
                if (arr[i][j] == 0)
                {
                    cnt++;
                }
            }
        }
        if (cnt == 0)
        {
            printf("There is no empty spots.\n");
        }
        else if (cnt == 1)
        {
            printf("There is one empty spot.\n");
        }
        else
            printf("There are %d empty spots.\n", cnt);
    }
    return 0;
}
