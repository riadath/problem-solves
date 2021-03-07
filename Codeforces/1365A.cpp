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
    int T;
    cin>>T;
    int kas = 1;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        bool arr[n][m],rows[n],cols[m];
        MEM(rows,true),MEM(cols,true);
        fl(i,0,n)fl(j,0,m){
            cin>>arr[i][j];
            if(arr[i][j]){
                rows[i] = false;
                cols[j] = false;
            }
        }
        int win = 0;
        bool flag = true,turn = true;
        while(flag){
            flag = false;
            fl(i,0,n){
                fl(j,0,m){
                    if(!arr[i][j]){
                        if(rows[i] && cols[j]){
                            flag = true;
                            arr[i][j] = 1;
                            rows[i] = false;
                            cols[j] = false;
                            break;
                        }
                    }
                }
                if(flag)break;
            }
            if(!flag){
                if(turn)win = 2;
                else win = 1;
            }
            turn = !turn;
        }
        if(win == 1)cout<<"Ashish"<<nl;
        else if(win == 2)cout<<"Vivek"<<nl;
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

