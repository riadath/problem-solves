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
    int n, kas = 1;
    while (scanf("%d", &n) == 1)
    {
        if (kas++ > 1)
            printf("\n");
        char friends[n + 5][200];
        int frnd[n + 5];
        MEM(frnd, 0);
        for (int i = 0; i < n; i++)
        {
            scanf(" %s", friends[i]);
        }

        for (int i = 0; i < n; i++)
        {
            char temp[200];
            int amt, cnt;
            scanf("%s %d %d", temp, &amt, &cnt);
            int frn = -1;
            for (int j = 0; j < n; j++)
                if (strcmp(temp, friends[j]) == 0)
                {
                    // cout << "-->" << j << nl;
                    frn = j;
                    break;
                }
            if (cnt == 0)
                continue;
            int eq = amt / cnt;
            int tot = eq * cnt;
            frnd[frn] -= tot;
            for (int k = 0; k < cnt; k++)
            {
                char tt[200];
                frn = -1;
                scanf("%s", tt);
                for (int j = 0; j < n; j++)
                    if (strcmp(tt, friends[j]) == 0)
                    {
                        // cout << "-->" << j << nl;
                        frn = j;
                        break;
                    }
                frnd[frn] += eq;
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%s %d\n", friends[i], frnd[i]);
        }
    }
    return 0;
}
