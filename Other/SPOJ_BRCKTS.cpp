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

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}
int n;
string s;
pii tree[300000];
void build(int nd,int st,int en)
{
    if(st == en){
        int x;
        if(s[st-1] == '(')x = 1;
        else x = -1;
        tree[nd].fi = x;
        tree[nd].se = x;
        return;
    }
    int left = 2*nd,right = left+1;
    int mid = (st+en)/2;
    build(left,st,mid);
    build(right,mid+1,en);
    tree[nd].fi = tree[left].fi + tree[right].fi;
    tree[nd].se = min(tree[left].se,tree[left].fi+tree[right].se);
}

void update(int nd,int st,int en,int id)
{
    if(id < st || id > en)return;
    if(st == en){
        tree[nd].fi = -1 * tree[nd].fi;
        tree[nd].se = -1 * tree[nd].se;
        return;
    }
    int mid = (st + en)/2;
    int left = 2*nd,right = left + 1;
    update(left,st,mid,id);
    update(right,mid+1,en,id);
    tree[nd].fi = tree[left].fi + tree[right].fi;
    tree[nd].se = min(tree[left].se,tree[left].fi+tree[right].se);
}

void solve()
{

    int kas = 1;
    while(cin>>n){
        cin>>s;
        build(1,1,n);
        fl(i,1,2*n+2)cout<<tree[i].fi<<sp<<tree[i].se<<nl;
        int q;
        cin>>q;
        cout<<"Test "<<kas++<<":"<<nl;
        while(q--){
            int tt;
            cin>>tt;
            if(tt != 0){
                update(1,1,n,tt);
            }else{
                bool flag = false;
                //cout<<"---> "<<tree[1].fi<<sp<<tree[1].se<<nl;
                if(tree[1].fi == 0 && tree[1].se == 0)flag = true;
                if(flag)cout<<"YES"<<nl;
                else cout<<"NO"<<nl;
            }
        }
        fl(i,0,5*n)tree[i].fi = 0,tree[i].se = 0;
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

