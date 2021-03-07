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
        ll n;
        cin >> n;
        ll arr[n + 10];
        ll temp[n + 10];
        fl(i, 0, n)
        {
            cin >> arr[i];
            temp[i] = arr[i];
        }
        sort(temp, temp + n);
        bool flag = true;
        int i, j;
        bool flg = true;
        fl(i, 0, n - 1)
        {
            if (temp[i] == temp[i + 1])
            {
                flg = false;
                break;
            }
        }
        if (!flg)
        {
            cout << "YES" << nl;
            continue;
        }
        flg = true;
        fl(i, 0, n)
        {
            if (temp[i] != arr[i])
            {
                flg = false;
                break;
            }
        }
        if (flg)
        {
            cout << "YES" << nl;
            continue;
        }
        for (i = 0, j = n - 1; i < n, j >= 0; i++, j--)
        {
            // cout << temp[j] << sp << arr[i] << nl;
            if (temp[j] != arr[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "NO" << nl;
        }
        else
            cout << "YES" << nl;
    }
    return 0;
}
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
        ll n;
        cin >> n;
        ll arr[n + 10];
        ll temp[n + 10];
        fl(i, 0, n)
        {
            cin >> arr[i];
            temp[i] = arr[i];
        }
        sort(temp, temp + n);
        bool flag = true;
        int i, j;
        bool flg = true;
        fl(i, 0, n - 1)
        {
            if (temp[i] == temp[i + 1])
            {
                flg = false;
                break;
            }
        }
        if (!flg)
        {
            cout << "YES" << nl;
            continue;
        }
        flg = true;
        fl(i, 0, n)
        {
            if (temp[i] != arr[i])
            {
                flg = false;
                break;
            }
        }
        if (flg)
        {
            cout << "YES" << nl;
            continue;
        }
        for (i = 0, j = n - 1; i < n, j >= 0; i++, j--)
        {
            // cout << temp[j] << sp << arr[i] << nl;
            if (temp[j] != arr[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "NO" << nl;
        }
        else
            cout << "YES" << nl;
    }
    return 0;
}
