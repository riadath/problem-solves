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
    int arr[20009];
    int st = 0, n;
    while (scanf("%d", &n) != EOF)
    {
        arr[st++] = n;
        for (int i = st - 1; i >= 1; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                int tm = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tm;
            }
        }
        // fl(i, 0, st) cout << arr[i] << sp;
        // cout << nl;
        if (st % 2 == 1)
        {
            printf("%d\n", arr[st / 2]);
        }
        else
        {
            printf("%d\n", (arr[st / 2 - 1] + arr[st / 2]) / 2);
        }
    }
    return 0;
}
