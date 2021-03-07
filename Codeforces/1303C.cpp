#include <bits/stdc++.h>
using namespace std;
#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args...)
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
    return a.fi < b.fi;
}
int is_pos = 1;
map<char, vector<char>> graph;
map<pair<char, char>, bool> flag;
map<char, int> visited, chek;
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        is_pos = 1;
        graph.clear();
        flag.clear();

        fl(i, 0, str.size() - 1) if (!flag[mp(str[i], str[i + 1])])
        {
            graph[str[i]].pb(str[i + 1]);
            graph[str[i + 1]].pb(str[i]);
            flag[mp(str[i], str[i + 1])] = true;
            flag[mp(str[i + 1], str[i])] = true;
        }
        char root = '#';
        fl(i, 0, str.size())
        {
            if (graph[str[i]].size() <= 1)
            {
                root = str[i];
            }
            if (graph[str[i]].size() > 2)
                is_pos = 0;
        }
        if (!is_pos || root == '#')
        {
            cout << "NO" << nl;
            continue;
        }

        cout << "YES" << nl;
        string ans = "";
        //clear
        visited.clear();
        queue<char> node;
        node.push(root);
        visited[root] = 1;
        ans.pb(root);
        while (!node.empty())
        {
            char u = node.front();
            node.pop();
            fl(i, 0, graph[u].size())
            {
                int v = graph[u][i];
                if (!visited[v])
                {
                    visited[v] = true;
                    ans.pb(v);
                    node.push(v);
                }
            }
        }
        //clear
        fl(i, 0, ans.size()) chek[ans[i]] = true;
        fl(i, 0, 26)
        {
            char c = 'a' + i;
            if (!chek[c])
            {
                chek[c] = true;
                ans.pb(c);
            }
        }
        cout << ans << nl;
        //clear
        graph.clear();
        flag.clear();
        visited.clear();
        chek.clear();
    }
    return 0;
}
