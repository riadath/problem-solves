#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (int i = a; i < b; i++)
#define lf(i, a, b) for (int i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
vector<int> graph[101];
int dep[101];
int n, m, printed;
bool alp[101];
void solve()
{
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        bool mat[n + 1][n + 1];
        MEM(mat, true);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            if (mat[x][y])
            {
                graph[x].pb(y);
                dep[y]++;
                mat[x][y] = false;
            }
        }
        printed = 0;
        MEM(alp, true);
        while (printed < n)
        {
            for (int i = 1; i <= n; i++)
            {
                if (dep[i] == 0 && alp[i])
                {
                    cout << i << " ";
                    alp[i] = false;
                    printed++;
                    for (int k = 0; k < graph[i].size(); k++)
                    {
                        int t = graph[i][k];
                        dep[t]--;
                    }
                }
            }
        }
        cout << "\n";
        fl(i, 0, n + 1) graph[i].clear();
        MEM(dep, 0);
    }
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
