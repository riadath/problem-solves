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
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(),x.end())

void solve()
{
   int n,p,q;
   cin>>n;
   cin>>p;
   int x[p];
   fl(i,0,p)cin>>x[i];
   cin>>q;
   int y[q];
   fl(i,0, q)cin>>y[i];
   bool game[n+10];
   MEM(game,false);
   fl(i,0,p){
    game[x[i]] = true;
   }fl(i,0,q){
    game[y[i]] = true;
   }
   bool flag = true;
   fl(i,1,n+1){
    if(game[i] == false){
        flag = false;
        break;
    }
   }
   if(flag)cout<<"I become the guy."<<nl;
   else cout<<"Oh, my keyboard!"<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

