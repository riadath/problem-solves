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
#define MX 100009
#define mod 1000000007
int arr[3*MX];
int tree_gcd[3*MX];
int tree_lcm[3*MX];
pii tree[3*MX];
int reg[3*MX];
void build(int nd,int st,int en)
{
    if(st == en){
        tree_gcd[nd] = arr[st];
        tree_lcm[nd] = arr[st];
        tree[nd].fi = reg[st];
        return;
    }
    int mid = (st+en)/2;
    int left = 2*nd,right = left+1;
    build(left,st,mid);
    build(right,mid+1,en);
    tree_gcd[nd] = abs(__gcd(tree_gcd[left],tree_gcd[right]))%mod;
    tree_lcm[nd] = abs(lcm(tree_lcm[left],tree_lcm[right]))%mod;
    tree[nd].fi = tree[left].fi + tree[right].fi;
}
void update(int nd,int st,int en,int i,int j,int v){
    if(i < st || i > en)return;
    if(en == st){
        tree[nd].fi += (en-st+1)*v;
        tree[nd].se += v;
        return;
    }
    int mid = (st+en)/2;
    update(2*nd,st,mid,i,j,v);
    update(2*nd+1,mid+1,en,i,j,v);
    tree[nd].fi = tree[2*nd].fi + tree[2*nd+1].fi + (en-st + 1)*tree[nd].se;
}

int query_gcd(int nd,int st,int en,int i,int j){
    if(j < st || i > en)return 0;
    if(st >= i && en <= j)return tree_gcd[nd];
    int mid = (st+en)/2;
    int left = 2*nd,right = left + 1;
    int a = query_gcd(left,st,mid,i,j);
    int b = query_gcd(right,mid+1,en,i,j);
    return __gcd(a,b);
}

int query_lcm(int nd,int st,int en,int i,int j){
     if(j < st || i > en)return 1;
    if(st >= i && en <= j)return tree_lcm[nd]%mod;
    int mid = (st+en)/2;
    int left = 2*nd,right = left + 1;
    int a = query_lcm(left,st,mid,i,j);
    int b = query_lcm(right,mid+1,en,i,j);
    return lcm(a,b)%mod;
}
int query(int nd,int st,int en,int i,int j,int prop){
     if(j < st || i > en)return 0;
    if(st >= i && en <= j)return tree[nd].fi + prop*(en-st+1);
    int mid = (st+en)/2;
    int left = 2*nd,right = left + 1;
    int a = query(left,st,mid,i,j,prop + tree[nd].se);
    int b = query(right,mid+1,en,i,j,prop + tree[nd].se);
    return a + b;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    fl(i,0,n){
        ll x;
        cin>>x;
        reg[i+1] = x;
        if(i == 0){
            arr[i+1] = x;
        }
        if(i == n-1){
            arr[i+1] = x;
        }
        else{
            arr[i+1] = abs(x - reg[i]);
        }
    }
    build(1,1,n);
    ll mul[3*n];
    mul[1] = arr[1];
    fl(i,2,n+1){
        mul[i] = (mul[i-1] * arr[i])%mod;
    }
    fl(i,0,m){
        int cm;
        cin>>cm;
        if(cm == 0){
            int p,q,v;
            cin>>p>>q>>v;
            p++,q++;
            update(1,1,n,p,q,v);
        }
        else{
            int p,q;
            cin>>p>>q;
            if(p == q){
                cout<<query(1,1,n,p,q,0)<<nl;
            }
            else{
                if(cm == 1){
                    if(p == 1 && q == n){
                        int LCM = 1;
                        if(q-p+1 > 2)LCM = query_lcm(1,1,n,p+1,q-1);
                        LCM = lcm(LCM,query(1,1,n,1,1,0))%mod;
                        LCM = lcm(LCM,query(1,1,n,n,n,0))%mod;
                        cout<<LCM<<nl;
                    }
                    else if(p == 1){
                        int LCM = 1;
                        LCM = query_lcm(1,1,n,p+1,q);
                        LCM = lcm(LCM,query(1,1,n,1,1,0))%mod;
                        cout<<LCM<<nl;
                    }
                    else if(q == n){
                        int LCM = 1;
                        if(q-p+1 > 2)LCM = query_lcm(1,1,n,p,q-1);
                        LCM = lcm(LCM,query(1,1,n,n,n,0))%mod;
                        cout<<LCM<<nl;
                    }
                    else{
                        int LCM = query_lcm(1,1,n,p,q);
                        cout<<LCM<<nl;
                    }
                }
                if(cm == 2){
                     if(p == 1 && q == n){
                        int LCM = 0;
                        if(q-p+1 > 2)LCM = query_gcd(1,1,n,p+1,q-1);
                        LCM = __gcd(LCM,query(1,1,n,1,1,0))%mod;
                        LCM = __gcd(LCM,query(1,1,n,n,n,0))%mod;
                        cout<<LCM<<nl;
                    }
                    else if(p == 1){
                        int LCM = 0;
                        LCM = query_gcd(1,1,n,p+1,q);
                        LCM = __gcd(LCM,query(1,1,n,1,1,0))%mod;
                        cout<<LCM<<nl;
                    }
                    else if(q == n){
                        int LCM = 0;
                        if(q-p+1 > 2)LCM = query_gcd(1,1,n,p,q-1);
                        LCM = __gcd(LCM,query(1,1,n,n,n,0))%mod;
                        cout<<LCM<<nl;
                    }
                    else{
                        int GCD = query_gcd(1,1,n,p,q);
                        cout<<GCD<<nl;
                    }
                }
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


