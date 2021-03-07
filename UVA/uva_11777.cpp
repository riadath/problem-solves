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
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        double t1, t2, fin, at, c1, c2, c3;
        double marks, ct_max;
        scanf("%lf %lf %lf %lf %lf %lf %lf", &t1, &t2, &fin, &at, &c1, &c2, &c3);
        ct_max = max(c1, max(c2, c3));
        if (ct_max == c1)
            ct_max += max(c2, c3);
        else if (ct_max == c2)
            ct_max += max(c1, c3);
        else
            ct_max += max(c1, c2);
        ct_max /= 2;
        marks = ((t1 + t2 + ct_max) + fin + at);
        int grade = marks / 10;
        // cout << grade << nl;
        printf("Case %d: ", kas++);
        switch (grade)
        {
        case 10:
        case 9:
            printf("A");
            break;
        case 8:
            printf("B");
            break;
        case 7:
            printf("C");
            break;
        case 6:
            printf("D");
            break;
        default:
            printf("F");
            break;
        }
        printf("\n");
    }
    return 0;
}
