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

    int n;
    cin >> n;
    vector<int> prs;
    vector<int> ans;
    fl(i, 0, n - 1)
    {
        cout << "? " << 1 << sp << i + 2 << nl;
        fflush(stdout);
        int a;
        cin >> a;
        // scanf("%d", &a);
        prs.pb(a);
    }
    fl(i, 1, prs.size())
    {
        ans.pb(prs[i] - prs[i - 1]);
    }
    int one, two;
    cout << "? " << 2 << sp << 3 << nl;
    fflush(stdout);
    int a;
    cin >> a;
    two = a - ans[0];
    one = prs[0] - two;

    string final;
    final += "! ";
    final += to_string(one);
    final += " ";
    final += to_string(two);
    final += " ";
    fl(i, 0, ans.size())
    {
        final += to_string(ans[i]);
        final += " ";
    }

    cout << final << nl;

    fflush(stdout);
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
string y = "Ya", n = "Tidak";
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((a + b + c + d) == 0)
            cout << n << sp << n << sp << n << sp << n << nl;
        else if ((a + b) % 2 == 1)
        {
            if ((a > 0 || d > 0) && (b > 0 || c > 0))
            {
                cout << y << sp << y << sp << n << sp << n << nl;
            }
            else if ((a > 0 || d > 0) && (b == 0 && c == 0))
            {
                cout << y << sp << n << sp << n << sp << n << nl;
            }
            else
            {
                cout << n << sp << y << sp << n << sp << n << nl;
            }
        }
        else if ((a + b) % 2 == 0)
        {
            if ((a > 0 || d > 0) && (b > 0 || c > 0))
            {
                cout << n << sp << n << sp << y << sp << y << nl;
            }
            else if ((a > 0 || d > 0) && (c == 0 && b == 0))
            {
                cout << n << sp << n << sp << n << sp << y << nl;
            }
            else
            {
                cout << n << sp << n << sp << y << sp << n << nl;
            }
        }
    }
    return 0;
}
