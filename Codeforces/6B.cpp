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
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, a, b) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(), x.end())

int dirx[] = {1,-1,0,0};
int diry[] = {0,0,1,-1};

void solve()
{
    int n,m;
    char ch;
    cin>>n>>m>>ch;
    string mat[n];
    bool ltr[26];
    MEM(ltr,false);
    fl(i,0,n){
        string t;
        cin>>t;
        fl(j,0,m){
            mat[i].pb(t[j]);
            if(t[j] != '.')ltr[t[j] - 'A'] = true;
        }
    }
    int cn = 0;
    fl(i,0,n)fl(j,0,m){
        if(mat[i][j] == ch){
            fl(k,0,4){
                int x = i+dirx[k];
                int y = j+diry[k];
                if(x >=0 && x < n && y >= 0 && y < m){
                    if(mat[x][y] != '.' && mat[x][y] != ch && ltr[mat[x][y]-'A']){
                        cn++;
                        ltr[mat[x][y]- 'A'] = false;
                    }
                }
            }
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

