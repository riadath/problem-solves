
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
///680B
void solve()
{
    int n,a;
    cin>>n>>a;
    bool arr[n];
    fl(i,0,n)cin>>arr[i];
    int cc = a-1;
    int cnt = 0;
    if(arr[cc])cnt++;
    fl(i,1,n){
        //cout<<cnt<<endl;
        if(cc-i < 0 && cc+i >= n)continue;
        else if(cc-i < 0 && arr[cc+i])cnt++;
        else if(cc+i >= n && arr[cc-i])cnt++;
        else if(arr[cc-i] && arr[cc+i])cnt += 2;
    }
    cout<<cnt<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
