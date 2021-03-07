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
#define pi 2 * acos(0)
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.second < b.second;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        ll arr[n + 10];
        fl(i, 0, n) cin >> arr[i];
        int st = -1;
        fl(i, 0, n)
        {
            if (arr[i] > 0)
            {
                // cout << st << nl;
                if (st < i + 1)
                {
                    st = i + 1;
                }
                fl(j, st, n)
                {
                    if (arr[j] < 0)
                    {
                        st = j;
                        if (abs(arr[j]) >= arr[i])
                        {
                            arr[j] += arr[i];
                            arr[i] = 0;
                            // cout << "--->" << arr[i] << sp << arr[j] << nl;
                            break;
                        }
                        else
                        {
                            arr[i] = arr[i] + arr[j];
                            arr[j] = 0;
                            // cout << arr[i] << sp << arr[j] << nl;
                        }
                    }
                    if (j == n - 1 && arr[j] >= 0)
                        i = j;
                }
                // fl(i, 0, n) cout << arr[i] << sp;
                // cout << nl;
            }
        }
        ll mv = 0;
        fl(i, 0, n)
        {
            // cout << arr[i] << sp;
            if (arr[i] < 0)
            {
                mv += -1 * (arr[i]);
            }
        }
        // cout << nl;
        cout << mv << nl;
    }
    return 0;
}
