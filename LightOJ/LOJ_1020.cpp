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
    //FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        ll n;
        string s;
        bool flag;
        cin >> n >> s;
        if (s == "Bob")
        {
            if (n == 1 || n == 2)
            {
                flag = 1;
            }
            else
            {
                //===
                if (n % 3 == 0)
                {
                    flag = 0;
                }
                else
                {
                    flag = 1;
                }
            }
        }
        else
        {
            if (n == 1)
            {
                flag = 1;
            }
            else if (n == 2 || n == 3)
            {
                flag = 0;
            }
            else if (n == 4)
            {
                flag = 1;
            }
            else
            {
                //====
                n -= 4;
                if (n % 3 == 0)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
        }
        printf("Case %d: ", kas++);
        if (flag)
            printf("Bob\n");
        else
            printf("Alice\n");
    }
    return 0;
}
