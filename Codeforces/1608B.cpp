#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

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
#define fl(i, a, b) for (ll i = (int)a; i < (int)b; i++)
#define lf(i, b, a) for (ll i = (int)b; i >= (int)a; i--)
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
    return a.fi < b.fi;
}

int main()
{
    FIO;
#ifdef IHAVETOPEE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        bool flag = true;
        int cnt = (n - (n % 2 == 0)) / 2;
        // debug(cnt)
        if (a + b > n - 2 || a > cnt || b > cnt  || abs(a - b) > 1)
            flag = false;

        if (!flag)
        {
            cout << -1 << "\n";
            continue;
        }

        int ac = 0, bc = 0;
        map<int, bool> check;
        list<int> ans;
        if (a < b)
        {
            int st = n - (b - a), en = 1, idx = 0;
            bool turn = true;
            while (idx < b)
            {
                // debug(idx);
                if (turn)
                {
                    check[st] = 1;
                    ans.push_back(st);
                    st -= 1;
                }
                else
                {
                    debug(en);
                    check[en] = 1;
                    ans.push_back(en);
                    en += 1;
                    idx++;
                }
                turn = !turn;
            }
            fl(i, 1, n + 1)
            {
                if (!check[i]){
                    ans.push_back(i);
                    check[i] = 1;
                }
            }
        }
        else if (a > b)
        {
            int st = 1, en = n - (a - b), idx = 0;
            bool turn = true;
            while (idx < a)
            {
                if (turn)
                {
                    check[st] = 1;
                    ans.push_back(st);
                    st += 1;
                    idx++;
                }
                else
                {
                    check[en] = 1;
                    ans.push_back(en);
                    en -= 1;
                }
                turn = !turn;
            }
            lf(i, n, 1)
            {
                if (!check[i])
                    ans.push_front(i);
            }
        }

        else
        {
            int st = 1, en = (a + b + 2), idx = 0;
            list<int> f1, f2;
            bool turn = true, turn2 = true;
            
            while (idx < (a + b+2)/2)
            {
                int val1, val2;
                if (turn)
                {
                    val1 = st++;
                    val2 = en--;
                }
                else
                {
                    val1 = en--;
                    val2 = st++;
                }
                f1.push_back(val1);
                f2.push_front(val2);
                check[val1] = check[val2] = 1;
                turn = !turn;
                idx++;
            }
            debug(f1);
            debug(f2);
            for (auto i : f1)
                ans.push_back(i);
            for (auto i : f2)
                ans.push_back(i);
            fl(i,a+b+3,n+1)ans.push_back(i);
        }
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
