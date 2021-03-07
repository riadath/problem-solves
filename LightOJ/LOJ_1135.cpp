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
#define pdd pair<double,double>
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
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>
#define seg_tree int mid=(st+en)/2,left = 2*nd,right = left+1
bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

#define MX 100009
struct data
{
    bool flag;
    int zero,one,two;
    int cmd;
};
int n;
data tree[4*MX];
string s;
data make_data(int s,int c,bool f)
{
    data ret;
    ret.zero = s;
    ret.one = c;
    ret.two = f;
    ret.cmd = 0;
    ret.flag = false;
    return ret;
}
data combine(data a,data b)
{
    data ret;
    ret.zero = a.zero + b.zero;
    ret.one = a.one + b.one;
    ret.two = a.two + b.two;
    ret.cmd = 0;
    ret.flag = false;
    return ret;
}
void build(int nd,int st,int en)
{
    if(st == en)
    {
        tree[nd].zero = 1;
        tree[nd].one = 0;
        tree[nd].two = 0;
        tree[nd].cmd = 0;
        tree[nd].flag = false;
        return;
    }
    seg_tree;

    build(left,st,mid);
    build(right,mid+1,en);

    tree[nd] = combine(tree[left],tree[right]);
}

void nd_update(int nd,int st,int en,int cm)
{
    int zr = tree[nd].zero;
    int on = tree[nd].one;
    int tw = tree[nd].two;
    if(cm == 1)
    {
        tree[nd].zero = on;
        tree[nd].one = tw;
        tree[nd].two = zr;
    }
    if(cm == 2)
    {
        tree[nd].zero = tw;
        tree[nd].one = zr;
        tree[nd].two = on;
    }
    tree[nd].cmd += cm;
    tree[nd].cmd %= 3;
    tree[nd].flag = true;
}
void lz_update(int nd,int st,int en)
{
    seg_tree;
    nd_update(left,st,mid,tree[nd].cmd%3);
    nd_update(right,mid+1,en,tree[nd].cmd%3);

    tree[nd].cmd = 0;
    tree[nd].flag = false;
}
void update(int nd,int st,int en,int i,int j,int cm)
{
    if(st > j || en < i)return;
    if(st >= i && en <= j)
    {
        nd_update(nd,st,en,cm);

        return;
    }
    seg_tree;
    if(tree[nd].flag)lz_update(nd,st,en);

    update(left,st,mid,i,j,cm);
    update(right,mid+1,en,i,j,cm);

    tree[nd] = combine(tree[left],tree[right]);
}

data query(int nd,int st,int en,int i,int j)
{
    if(st > j || en < i)return make_data(0,0,0);
    if(st >= i && en <= j)
    {
        return tree[nd];
    }

    seg_tree;
    if(tree[nd].flag)lz_update(nd,st,en);

    data a = query(left,st,mid,i,j);
    data b = query(right,mid+1,en,i,j);

    return combine(a,b);
}

void solve()
{
    int T;
    scanf("%d",&T);
    int kas = 1;
    while(T--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        build(1,1,n);
        printf("Case %d:\n",kas++);
        fl(i,0,q)
        {
            int a,x,y;
            scanf("%d %d %d",&a,&x,&y);
            x++,y++;
            if(a == 0)
            {
                update(1,1,n,x,y,1);
            }
            else{
                data ans = query(1,1,n,x,y);
                printf("%d\n",ans.zero);
            }
        }
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


