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
int n,arr[50020];

struct data
{
    int sum,pre,suf,ans;
};

data tree[4*50020];

data combine(data left,data right)
{
    data ret;
    ret.sum = left.sum + right.sum;
    ret.pre = max(left.pre,left.sum+right.pre);
    ret.suf = max(right.suf,left.suf+right.sum);
    ret.ans = max(max(left.ans,right.ans),left.suf+right.pre);
    return ret;
}

data md(int x)
{
    data ret;
    ret.sum = x;
    ret.pre = x;
    ret.suf = x;
    ret.ans = x;
    return ret;
}

void update(int nd,int st,int en,int i,int x)
{
    if(i < st || i > en)return;
    if(st == en)
    {
        tree[nd] = md(x);
        return;
    }
    int left,right,mid;
    mid = (st+en)/2;
    left =  2*nd,right = left+1;
    update(left,st,mid,i,x);
    update(right,mid+1,en,i,x);
    tree[nd] = combine(tree[left],tree[right]);
}

data query(int nd,int st,int en,int i,int j)
{
    if(i > en || j < st)return md(-1e5);
    if(st >= i && en<= j)return tree[nd];
    int left = 2*nd,right = left+1;
    int mid = (st+en)/2;
    data a = query(left,st,mid,i,j);
    data b = query(right,mid+1,en,i,j);
    return combine(a,b);

}
void build(int nd,int st,int en)
{
    if(st == en){
        tree[nd] = md(arr[st]);
        return;
    }
    int left = 2*nd,right = left+1,mid = (st+en)/2;
    build(left,st,mid);
    build(right,mid+1,en);
    tree[nd] = combine(tree[left],tree[right]);
}
void solve()
{
    cin>>n;
    fl(i,1,n+1)cin>>arr[i];
    build(1,1,n);
    int q;
    cin>>q;
    fl(i,0,q)
    {
        int w,x,y;
        cin>>w>>x>>y;
        if(w == 0)
        {
            update(1,1,n,x,y);
            arr[x] = y;
        }
        else
        {
            data result = query(1,1,n,x,y);
            cout<<result.ans<<nl;
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

