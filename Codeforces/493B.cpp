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
    int n;
    cin >> n;
    vector<ll> first, second;
    ll fr = 0, sc = 0;
    int lst = -1;
    fl(i, 0, n)
    {
        int temp;
        cin >> temp;
        if (temp > 0)
        {
            if (i == n - 1)
            {
                lst = 1;
            }
            first.pb(temp);
            fr += temp;
        }
        else
        {
            if (i == n - 1)
            {
                lst = 2;
            }
            temp *= -1;
            second.pb(temp);
            sc += (temp);
        }
    }
    // cout << fr << sp << sc << nl;
    if (fr > sc)
    {
        cout << "first" << nl;
    }
    else if (fr < sc)
    {
        cout << "second" << nl;
    }
    else
    {
        int win = -1;
        fl(i, 0, min(first.size(), second.size()))
        {
            if (first[i] > second[i])
            {
                win = 1;
                break;
            }
            else if (first[i] < second[i])
            {
                win = 2;
                break;
            }
        }
        if (win == 1)
        {
            cout << "first" << nl;
        }
        else if (win == 2)
        {
            cout << "second" << nl;
        }
        else
        {
            if (lst == 1)
            {
                cout << "first" << nl;
            }
            else
            {
                cout << "second" << nl;
            }
        }
    }
    return 0;
}
