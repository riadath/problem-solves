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
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, kas = 1;
    while (scanf("%d", &n) && n)
    {
        int arr[n + 10];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        printf("Case %d:\n", kas++);
        int m;
        scanf("%d", &m);
        while (m--)
        {
            int q;
            scanf("%d", &q);
            int mn = 1e8;
            int res = 1e8;
            fl(i, 0, n)
            {
                fl(j, i + 1, n)
                {
                    int sum = arr[i] + arr[j];
                    if (abs(q - sum) < mn)
                    {
                        mn = abs(q - sum);
                        res = arr[i] + arr[j];
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", q, res);
        }
    }
    return 0;
}
