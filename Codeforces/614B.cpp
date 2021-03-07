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
    return a.second < b.second;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    string ans;
    bool done = false, ifzero = false;
    int cn0 = 0;
    fl(i, 0, n)
    {
        string temp;
        cin >> temp;
        // cout << temp << nl;
        if (temp.size() == 1 && temp[0] == '0')
        {
            ifzero = true;
        }
        else if (done)
        {
            cn0 += temp.size() - 1;
        }
        else
        {
            int ocn = 0, znc = 0;
            fl(i, 0, temp.size())
            {
                if (temp[i] == '1')
                    ocn++;
                if (temp[i] == '0')
                    znc++;
            }
            if (ocn == 1 && ocn + znc == temp.size())
            {
                cn0 += temp.size() - 1;
            }
            else
            {
                ans = temp;
                done = true;
            }
        }
    }
    if (ifzero)
        cout << '0' << nl;
    else
    {
        // int st = 0;
        // while (ans[st] == '0')
        //     st++;
        // fl(i, st, ans.size()) cout << ans[i];
        if (ans.size() != 0)
            cout << ans;
        else
            cout << '1';
        fl(i, 0, cn0) cout << '0';
        cout << nl;
    }
    return 0;
}
