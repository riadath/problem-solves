#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(ll i = a;i < b;i++)
#define lf(i,a,b) for(ll i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(),x.end())
int n;
long double l, arr[1010];
bool pos(long double d)
{
    long double cov = 0;
    if(arr[0] > d)return false;
    else cov += d;
    fl(i,0,n-1){
       // cout<<"arr[i]:"<<arr[i]<<" d: "<<d<<"  arr[i+1]: "<<arr[i+1]<<nl;
        if(arr[i]+2*d < arr[i+1])return false;
        else{
            cov += 2*d;
        }
    }
    if(l - arr[n-1] > d)return false;
    else cov += d;
    if(cov >= l)return true;
    else return false;
}

void solve()
{
    cin>>n>>l;
    fl(i,0,n)cin>>arr[i];
    sort(arr,arr+n);
    long double low,high,mid;
    low = 0;
    high = l;
    while(low < high-0.000000001){
        mid = (low+high)/2;
        //cout<<low<<" "<<mid<<" "<<high<<nl;
        bool flag = pos(mid);
        //cout<<"POS:"<<flag<<nl;
        if(flag)high = mid - 0.000000001;
        else low = mid;
    }
    //printf("%0.9lf\n",low);
    cout<<setprecision(9)<<low<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

