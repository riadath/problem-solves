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
int n;
bool tree[3*100000];
char binary[2*100001];
void update(int nd,int st,int en,int i,int j)
{
    if(st > j || en < i)return;
    if(st >= i && en <= j)
    {
        tree[nd] = !tree[nd];
        return;
    }
    int left = nd*2,right = left+1;
    int mid = (st+en)/2;
    update(left,st,mid,i,j);
    update(right,mid+1,en,i,j);
}


int query(int nd,int st,int en,int i)
{
    if(i < st || i > en)return -1e8;
    if(st == en)
    {
        return tree[nd];
    }
    int left = 2*nd,right = left+1,mid = (st+en)/2;
    int a = 0,b = 0;
    a = tree[nd] + query(left,st,mid,i);
    b = tree[nd] + query(right,mid+1,en,i);
    return max(a,b);


}

void solve()
{
    int T;
    scanf("%d",&T);
    fl(kas,1,T+1)
    {
        int q;
        scanf(" %[^\n]",binary);
        n = strlen(binary);
        scanf("%d",&q);
        printf("Case %d:\n",kas);
        fl(i,0,q)
        {
            char a;
            int x,y;
            scanf(" %c",&a);
            if(a == 'I')
            {
                scanf("%d %d",&x,&y);
                update(1,1,n,x,y);
                /*cout<<"after update : "<<nl;
                fl(i,1,3*n+2)cout<<"tree["<<i<<"] : "<<tree[i]<<nl;*/
            }
            else
            {
                scanf("%d",&x);
                int ans = query(1,1,n,x);
                //cout<<"ans : "<<ans<<nl;
                int temp = binary[x-1] - '0';
                if(ans%2 == 1) temp = !temp;
                printf("%d\n",temp);

            }
        }
        MEM(tree,0);
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

