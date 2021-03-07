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
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>
#define all(a) a.begin(),a.end()

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}


int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        string s[n];
        fl(i,0,n)cin>>s[i];
        int cnt = 0;
        bool arr[n][m];
        MEM(arr,true);
        fl(i,0,n){
            fl(j,0,m){
                int dx = i,dy = j;
                while(s[dx][dy] != 'C'){
                    if(s[dx][dy] == 'R'){
                        if(dy+1 < m){
                            dy += 1;
                        }else{
                            cnt++;
                            s[dx][dy] = 'D';
                            dx += 1;
                        }
                    }else{
                        if(dx+1 < n){
                            dx += 1;
                        }else{
                            cnt++;
                            s[dx][dy] = 'R';
                            dy += 1;
                        }
                    }
                }
            }
        }
        cout<<cnt<<nl;
    }
    return 0;
}













