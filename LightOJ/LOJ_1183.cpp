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
#define pll pair<long, long>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define srta(x, n) sort(x, x + n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define seg_tree int mid = (st + en) / 2, left = 2 * nd, right = left + 1
bool comp(const pii &a, const pii &b)
{
    return a.second < b.second;
}
double dt(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

#define MX 100109
struct data
{
    bool flag;
    int sum, cmd;
};
int n;
data tree[3 * MX + 100];
int arr[MX];
data make_data(int s, int c, bool f)
{
    data ret;
    ret.cmd = c;
    ret.sum = s;
    ret.flag = f;
    return ret;
}
data combine(data a, data b)
{
    data ret;
    ret.sum = a.sum + b.sum;
    ret.flag = 0;
    ret.cmd = 0;
    return ret;
}

void nd_update(int nd, int st, int en, int cm)
{
    tree[nd].sum = (en - st + 1) * cm;
    tree[nd].cmd = cm;
    tree[nd].flag = true;
}
void lz_update(int nd, int st, int en)
{
    int mid = (st + en) / 2;
    int left = 2 * nd, right = left + 1;

    nd_update(left, st, mid, tree[nd].cmd);
    nd_update(right, mid + 1, en, tree[nd].cmd);
    tree[nd].cmd = 0;
    tree[nd].flag = false;
}
void update(int nd, int st, int en, int i, int j, int cm)
{
    if (st > j || en < i)
        return;
    if (st >= i && en <= j)
    {
        nd_update(nd, st, en, cm);
        return;
    }
    int mid = (st + en) / 2;
    int left = 2 * nd, right = left + 1;
    if (tree[nd].flag)
        lz_update(nd, st, en);
    update(left, st, mid, i, j, cm);
    update(right, mid + 1, en, i, j, cm);
    tree[nd] = combine(tree[left], tree[right]);
}

data query(int nd, int st, int en, int i, int j)
{
    if (st > j || en < i)
        return make_data(0, 0, 0);
    if (st >= i && en <= j)
    {
        return tree[nd];
    }
    int mid = (st + en) / 2;
    int left = 2 * nd, right = left + 1;
    if (tree[nd].flag)
        lz_update(nd, st, en);
    data a = query(left, st, mid, i, j);
    data b = query(right, mid + 1, en, i, j);
    return combine(a, b);
}

void solve()
{
    int T;
    scanf("%d", &T);
    int kas = 1;
    while (T--)
    {
        int q;
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", kas++);
        while (q--)
        {
            int md, i, j, v;
            scanf("%d %d %d", &md, &i, &j);
            if (md == 1)
            {
                scanf("%d", &v);
                update(1, 1, n, i + 1, j + 1, v);
            }
            else
            {
                int top = query(1, 1, n, i + 1, j + 1).sum;
                int bot = (j - i + 1);
                int div = __gcd(top, bot);
                //cout << top << sp << bot << nl;
                top /= div;
                bot /= div;
                if (top % bot == 0)
                    printf("%d\n", top / bot);
                else
                    printf("%d/%d\n", top, bot);
            }
        }
        fl(i, 0, 3 * n + 20)
        {
            tree[i].sum = 0;
            tree[i].cmd = 0;
            tree[i].flag = 0;
        }
        fl(i, 0, n + 1)
        {
            arr[i] = 0;
        }
    }
}

int main()
{
    //FIO;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
