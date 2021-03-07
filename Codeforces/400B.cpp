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

void solve()
{
    int n,m;
    cin>>n>>m;
    string temp;
    vector <int> line;
    fl(i,0,n){
        cin>>temp;
        int s,g;
        fl(j,0,m){
            if(temp[j] == 'S')s = j;
            if(temp[j] == 'G')g = j;
        }
        if(s < g){
            cout<<"-1"<<nl;
            return;
        }
        if(s != g)line.pb(s - g);
    }
    srt(line);
    int cn = 0;
    fl(i,0,line.size()){
        int x = line[i];
        if(x == 0)continue;
        //cout<<x<<nl;
        int dn = 0;
        fl(j,0,line.size()){
            if(line[j] != 0){
                line[j] -= x;
                line[j] = max(0,line[j]);
                dn++;
            }
        }
        if(dn != 0)cn++;
        else if(dn == 0){
            break;
        }
    }
    cout<<cn<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

