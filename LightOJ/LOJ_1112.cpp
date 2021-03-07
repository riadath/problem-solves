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

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

#define MX 100010
int n;
int arr[MX],tree[3*MX];

void update(int nd,int st,int en,int i,int x)
{
    if(i > en || i < st)return;
    if(st == en)
    {
        tree[nd] = x;
        return;
    }
    int left = 2*nd,right = left + 1;
    int mid = (st+en)/2;
    update(left,st,mid,i,x);
    update(right,mid+1,en,i,x);
    tree[nd] = tree[left] + tree[right];
}
int query(int nd,int st,int en,int i,int j)
{
    if(i > en || j < st)return 0;
    if(st >= i && en <= j)
    {
        return tree[nd];
    }
    int left = 2*nd,right = left+1;
    int mid = (st+en)/2;
    int a = query(left,st,mid,i,j);
    int b = query(right,mid+1,en,i,j);
    return a+b;
}

void solve()
{
    int T;
    scanf("%d",&T);
    fl(kas,1,T+1)
    {
        int q;
        scanf("%d %d",&n,&q);
        fl(i,1,n+1)scanf("%d",&arr[i]);
        fl(i,1,n+1){
            update(1,1,n,i,arr[i]);
        }
        printf("Case %d:\n",kas);
        fl(i,0,q)
        {
            int w,x,y;
            scanf("%d",&w);
            if(w == 1)
            {
                scanf("%d",&x);
                printf("%d\n",arr[x+1]);
                update(1,1,n,x+1,0);
                arr[x+1] = 0;
            }
            else if(w == 2)
            {
                scanf("%d %d",&x,&y);

                update(1,1,n,x+1,arr[x+1]+y);
                arr[x+1] += y;
            }
            else if(w == 3)
            {
                scanf("%d %d",&x,&y);
                int ans = query(1,1,n,x+1,y+1);
                printf("%d\n",ans);
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

