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
        ll p1 = 0, p2 = 0;
        bool flag = true;
        while (n > 0)
        {
            if (flag)
            {
                if(n == 4){
                    p1 += n/2;
                    n = n/2;
                }
                else if (n % 2 == 1)
                {
                    p1 += 1;
                    n -= 1;
                }
                else if (n % 2 == 0)
                { 
                    ll q = n / 2;
                    if (q % 2 == 0)
                    {
                        p1 += 1;
                        n -= 1;
                    }
                    else
                    {
                        p1 += n / 2;
                        n = n / 2;
                    }
                }
                flag = !flag;
            }
            else
            {
                if(n == 4){
                    p2 += n/2;
                    n = n/2;
                }
                else if (n % 2 == 1)
                {
                    p2 += 1;
                    n -= 1;
                }
                else if (n % 2 == 0)
                {
                    ll q = n / 2;
                    if (q % 2 == 0)
                    {
                        p2 += 1;
                        n -= 1;
                    }
                    else
                    {
                        p2 += n / 2;
                        n = n / 2;
                    }
                }
                flag = !flag;
            }
        }
        cout << p1 << nl;
    }
    return 0;
}
