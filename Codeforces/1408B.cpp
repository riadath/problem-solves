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

    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n + 10];
        fl(i, 0, n)
        {
            cin >> arr[i];
        }
        if (arr[0] == arr[n - 1])
        {
            cout << 1 << nl;
            continue;
        }
        if (k == 1)
        {
            if (arr[0] == arr[n - 1])
                cout << 1 << nl;
            else
                cout << -1 << nl;
            continue;
        }

        int cmpr[arr[n - 1] + 10][n + 10];
        int mx = arr[n - 1];
        MEM(cmpr, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int el = arr[i];
            for (int p = mx - 1; el > 0; p--)
            {
                cmpr[p][i] = 1;
                el--;
            }
        }

        int st = mx - 1, bt = 0;
        int ans = 0;
        while (bt < st)
        {
            int temp[n + 10], diff = 0;
            set<int> counter;
            fl(i, 0, n)
            {
                temp[i] = cmpr[bt][i] + cmpr[bt + 1][i];
                counter.insert(temp[i]);
            }
            diff = counter.size();
            if (diff <= k)
            {
                fl(l, 0, n) cmpr[bt + 1][l] = temp[l];
                bt++;
                if (bt == mx - 1)
                {
                    ans++;
                    break;
                }
            }
            else
            {
                ans++, bt++;
                if (bt == mx - 1)
                {
                    ans++;
                    break;
                }
            }
        }
        cout << max(1, ans) << nl;
    }
    return 0;
}
