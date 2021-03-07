
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

bool comp(const int &a,const int &b)
{
    return a > b;
}
#define MX 100009
int n,k,p;
int arr[MX];

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k>>p;
        fl(i,0,n)cin>>arr[i];
        int mx = 0;
        fl(z,0,p+1){
            int sum = 0;
            for(int i = 0;i <= k-2*z;i++){
                sum += arr[i];
            }
            int t = 0;
            for(int i = 0;i <= k-2*z;i++)
                t = max(t,arr[i]+arr[i+1]);
            mx = max(mx,sum+t*(int)z);
        }
        cout<<mx<<nl;

    }
    return 0;
}















