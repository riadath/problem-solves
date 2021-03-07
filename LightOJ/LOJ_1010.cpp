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
// int dirx[] = {2, -2, 1, -1, 1, 2, -1, -2};
// int diry[] = {1, -1, 2, -2, -2, -1, 2, 1};
int main()
{
    //FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        int cnt;
        if (x == 1 || y == 1)
        {
            if (x == 1)
                cnt = y;
            else
                cnt = x;
        }
        else if (x == 2 || y == 2)
        {
            int nt = max(x, y);
            int flag[nt + 10];
            MEM(flag, 1);
            cnt = 0;
            fl(i, 0, nt)
            {
                if (flag[i])
                {
                    cnt++;
                    flag[i] = 0;
                    if (i + 2 < nt)
                        flag[i + 2] = 0;
                }
            }
            cnt *= 2;
        }
        else
        {
            cnt = (x * y) / 2;
            if ((x * y) % 2 == 1)
                cnt++;
        }
        printf("Case %d: %d\n", kas++, cnt);
    }
    return 0;
}
