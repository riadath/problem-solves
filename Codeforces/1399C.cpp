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
#define pll pair<ll,ll>
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
    int kas = 1;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        fl(i,0,n)cin>>arr[i];
        sort(arr,arr+n);
        int mx = arr[n-1];
        int mn = arr[0];
        if(n > 1){
            mx += arr[n-2];
            mn += arr[1];
        }
        int mcnt = 0;
        for(int i = mn;i <= mx;i++){
            //cout<<"w :"<<i<<nl;
            int cnt = 0;
            int flag[n];
            MEM(flag,true);
            fl(j,0,n)fl(k,j+1,n){
                if(flag[j] && flag[k]){
                    if(arr[j] + arr[k] == i){
                        //cout<<arr[j]<<sp<<arr[k]<<nl;
                        cnt++;
                        flag[j] = false;
                        flag[k] = false;
                    }
                }
            }
            //cout<<"cnt : "<<cnt<<nl;
            mcnt = max(mcnt,cnt);
        }
        cout<<mcnt<<nl;
    }
    return 0;
}
