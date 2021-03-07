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
    int n,m;
    cin>>n>>m;
    string c;
    cin>>c;
    int mis[m];
    int arr[27];
    MEM(arr,0);
    fl(i,0,n){
        arr[c[i]-'a']++;
    }
    fl(i,0,m){
        cin>>mis[i];
    }
    sort(mis,mis+m);
    int cur = 0;
    fl(i,0,m){
        fl(j,cur,mis[i]){
            int t = c[j] - 'a';
            arr[t] += m-i;
        }
        cur = mis[i];
    }
    fl(i,0,26)cout<<arr[i]<<sp;
    cout<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
    solve();
    return 0;
}

