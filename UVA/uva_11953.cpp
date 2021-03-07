#include <bits/stdc++.h>
using namespace std;

long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(int i = a;i < b;i++)
#define lf(i,a,b) for(int i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
int dirx[] = {0,0,1,-1};
int diry[] = {1,-1,0,0};
void solve()
{
    int T;
    cin>>T;
    for(int kase = 1;kase<=T;kase++)
    {
        int alive = 0;
        int n;
        cin>>n;
        string arr[n];
        fl(i,0,n)cin>>arr[i];
        fl(i,0,n){
            fl(j,0,n){
                if(arr[i][j] == 'x'){
                    alive++;
                    for(int l = 0;l < 4;l++){
                        int x = i+dirx[l],y = j+diry[l];
                        if(x>=0&&x<n&&y>=0&&y<n){
                            if(arr[x][y]!='.'){
                               while(true){
                                    if(x<0||x>=n||y<0||y>=n)break;
                                    if(arr[x][y] == '.')break;
                                    else{
                                        arr[x][y] = '.';
                                        x += dirx[l];
                                        y += diry[l];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout <<"Case "<<kase<<": "<<alive<<"\n";
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

