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
int dirx[] = {-1,0,0};
int diry[] = {0,1,-1};
string msg[] = {"forth","right","left"};
void solve()
{
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int sx,sy;
        string arr[n];
        fl(i,0,n){
            cin>>arr[i];
            fl(j,0,arr[i].size()){
                if(arr[i][j] == '@')sx=i,sy=j;
            }
        }
        //fl(i,0,n)cout << arr[i]<<endl;
        string god = "IEHOVA#";
        fl(l,0,7){
            fl(i,0,3){
                int x = sx+dirx[i],y = sy+diry[i];
                if(x>=0&&x<n&&y>=0&&y<m){
                    if(arr[x][y] == god[l]){
                        sx = x,sy = y;
                        if(l == 6)cout << msg[i]<<"\n";
                        else cout << msg[i]<< " ";
                        break;
                    }
                }
            }
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

