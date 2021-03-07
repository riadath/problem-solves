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
        // vector<string> s;
        int arr[30];
        MEM(arr, 0);
        fl(i, 0, n)
        {
            string temp;
            cin >> temp;
            fl(i, 0, temp.size())
            {
                int t = temp[i] - 'a';
                arr[t]++;
            }
        }
        bool flag = true;
        fl(i, 0, 26)
        {
            if (arr[i] != 0 && arr[i] % n != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
    }
    return 0;
}
