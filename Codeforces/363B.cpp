#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, a, b) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(), x.end())

void solve()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    fl(i,0,n)cin>>arr[i];
    int sumbitch[n];
    sumbitch[0] = arr[0];
    fl(i,1,n){
        sumbitch[i] = arr[i] + sumbitch[i-1];
    }
    int mn = INT_MAX;
    int inx = 0;
    for(int i = 0;i <= n-k;i++){
        int temp;
        if(i-1 < 0)temp = sumbitch[i+k-1];
        else temp = sumbitch[i+k-1] - sumbitch[i-1];
        //cout<<temp<<" "<<inx<<nl;;
        if(temp < mn){
           inx = i;
           mn = temp;
        }
    }
    cout<<inx+1<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

