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

#define MX 1124000
struct data{
    bool flag;
    int sum,cmd;
};
int n;
data tree[3*MX];
string s;
data make_data(int s,int c,bool f)
{
    data ret;
    ret.cmd = c;
    ret.sum = s;
    ret.flag = f;
    return ret;
}
data combine(data a,data b)
{
    data ret;
    ret.sum = a.sum + b.sum;
    ret.flag = 0;
    ret.cmd = 0;
    return ret;
}
void build(int nd,int st,int en)
{
    if(st == en){
        tree[nd].sum = s[st-1] - '0';
        tree[nd].cmd = 0;
        tree[nd].flag = false;
        return;
    }
    int mid = (st+en)/2,left = 2*nd,right = left+1;
    build(left,st,mid);
    build(right,mid+1,en);
    tree[nd] = combine(tree[left],tree[right]);
}

void nd_update(int nd,int st,int en,int cm)
{
   // cout<<st<<sp<<en<<sp<<cm<<sp<<tree[nd].cmd<<" <---"<<nl;
    if(cm == 1)tree[nd].sum = (en-st+1) - tree[nd].sum;
    if(cm == 2)tree[nd].sum = en-st+1;
    if(cm == 3)tree[nd].sum = 0;
    tree[nd].flag = true;
    if(cm == 2 || cm == 3)tree[nd].cmd = cm;
    if(cm == 1){
        if(tree[nd].cmd == 2)tree[nd].cmd = 3;
        else if(tree[nd].cmd == 3)tree[nd].cmd = 2;
        else if(tree[nd].cmd == 1)tree[nd].cmd = 0;
        else tree[nd].cmd = 1;
    }
}
void lz_update(int nd,int st,int en)
{
    int mid = (st+en)/2;
    int left = 2*nd,right = left+1;
    nd_update(left,st,mid,tree[nd].cmd);
    nd_update(right,mid+1,en,tree[nd].cmd);
    tree[nd].cmd = 0;
    tree[nd].flag = false;
}
void update(int nd,int st,int en,int i,int j,int cm)
{
    if(st > j || en < i)return;
    if(st >= i && en <= j){
        //cout<<"PREV : "<<tree[nd].cmd<<nl;
        nd_update(nd,st,en,cm);
        //cout<<st<<sp<<en<<sp<<tree[nd].sum<<sp<<tree[nd].cmd<<nl;
        return;
    }
    int mid = (st+en)/2;
    int left = 2*nd,right =  left+1;

    if(tree[nd].flag)lz_update(nd,st,en);

   // cout<<st<<sp<<en<<sp<<tree[nd].sum<<nl;

    update(left,st,mid,i,j,cm);
    update(right,mid+1,en,i,j,cm);
    tree[nd] = combine(tree[left],tree[right]);
}

data query(int nd,int st,int en,int i,int j)
{
    if(st > j || en < i)return make_data(0,0,0);
    if(st >= i && en <= j){
       // cout<<"->"<<st<<sp<<en<<sp<<tree[nd].sum<<nl;
        return tree[nd];
    }
    int mid = (st+en)/2;
    int left = 2*nd,right = left + 1;
    if(tree[nd].flag)lz_update(nd,st,en);

    //cout<<st<<sp<<en<<sp<<tree[nd].sum<<sp<<tree[nd].cmd<<nl;

    data a = query(left,st,mid,i,j);
    data b = query(right,mid+1,en,i,j);
    return combine(a,b);
}

void solve()
{
    int T;
    cin>>T;
    int kas = 1;
    while(T--)
    {
        int m;
        cin>>m;
        s.clear();

        while(m--)
        {
            int rep;
            string temp;
            cin>>rep;
            cin>>temp;
            while(rep--){
                s += temp;
            }
        }
        n = s.size();
        build(1,1,n);
        //cout<<tree[1].sum<<nl;
        int q;
        cin>>q;
        cout<<"Case "<<kas++<<":\n";
        int kk = 1;
        while(q--)
        {
            int a,b;
            char cc;
            cin>>cc;
            cin>>a>>b;
            a++,b++;
            if(cc == 'F'){
                update(1,1,n,a,b,2);
            }
            if(cc == 'E'){
                update(1,1,n,a,b,3);
            }
            if(cc == 'I'){
                update(1,1,n,a,b,1);
            }
            if(cc == 'S'){
                data ans = query(1,1,n,a,b);
                cout<<"Q"<<kk++<<": " <<ans.sum<<nl;
            }
        }
    }
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

