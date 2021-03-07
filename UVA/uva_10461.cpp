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
vector <int> graph[501];
bool done[501],mat[501][501];
int mn,mx,n,r,arr[501];

void bfs_mn(int st)
{
    bool visited[n+1];
    MEM(visited,false);
    visited[st] = true;
    done[st] = true;
    queue <int> node;
    node.push(st);
    while(!node.empty())
    {
        int t = node.front();
        node.pop();
        fl(i,0,graph[t].size())
        {
            int temp = graph[t][i];
            done[temp] = true;
            if(!visited[temp])
            {
                visited[temp] = true;
                node.push(temp);
            }
        }
    }
}
bool bfsc(int st,int x)
{
    bool visited[n+1];
    MEM(visited,false);
    visited[st] = true;
    queue <int> node;
    node.push(st);
    while(!node.empty())
    {
        int t = node.front();
        node.pop();
        fl(i,0,graph[t].size())
        {
            int temp = graph[t][i];
            if(temp == x)return true;
            if(!visited[temp])
            {
                visited[temp] = true;
                node.push(temp);
            }
        }
    }
    return false;
}

void solve()
{
    int kas = 1;
    while(cin>>n>>r)
    {
        int total = 0;
        if(n == 0 && r == 0)break;
        MEM(mat,false);
        MEM(arr,0);
        fl(i,1,n+1){
            cin>>arr[i];
            total += arr[i];
        }
        fl(i,0,r)
        {
            int x,y;
            cin>>x>>y;
            graph[y].pb(x);
            mat[y][x] = true;
        }
        int q;
        cin>>q;
        cout<<"Case #"<<kas++<<":\n";
        fl(i,0,q)
        {
            mn = 0,mx = 0;
            int x;
            cin>>x;
            MEM(done,false);
            bfs_mn(x);
            fl(k,1,n+1)if(done[k])
            {
                mn += arr[k];
            }
            int temp = 0;
            fl(t,1,n+1){
                if(t == x)continue;
                if(bfsc(t,x))temp += arr[t];
            }
            mx = total - temp;
            //cout<<mx<<sp<<mn<<nl;
            cout<<mx - mn<<nl;
        }
        cout<<nl;
        fl(i,0,n+1)graph[i].clear();
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

