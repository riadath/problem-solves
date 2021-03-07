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

string rev(string a,int len){
    fl(i,0,len){
        a[i] = !(a[i] - '0') + '0';
    }
    reverse(a.begin(),a.begin()+len);
    return a;
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
        int arr[n],brr[m];
        fl(i,0,n)cin>>arr[i];
        fl(i,0,m)cin>>brr[i];
        bool flag = false;
        int ans = -1;
        fl(i,0,n){
            fl(j,0,m){
                if(arr[i] == brr[j]){
                    ans = arr[i];
                    flag = true;
                    break;
                }
            }
            if(flag)break;
        }
        if(flag){
            cout<<"YES"<<nl;
            cout<<1<<sp<<ans<<nl;
        }
        else cout<<"NO"<<nl;
    }
    return 0;
}















