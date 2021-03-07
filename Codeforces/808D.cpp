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
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

void solve()
{
    ll n;
    cin>>n;
    vector <ll> arr;
    map <ll,vector<int>> exist;
    ll sum = 0;
    ll pos = 0;
    fl(k,0,n){
        int i;
        cin>>i;
        arr.pb(i);
        exist[i].pb(pos);
        pos++;
        sum += i;

    }
    if(sum%2 == 1)
    {
        cout<<"NO"<<nl;
        return;
    }
    ll sum1 = 0,point = 0,diff = 0,mv = 1e8;
    fl(i,0,n)
    {
        sum1 += arr[i];
        if(sum1 == sum/2)
        {
            cout<<"YES"<<nl;
            return;
        }
        if(sum1 < sum/2)
        {
            diff = (sum/2) - sum1;
            if(exist[diff].size() != 0){
                if(exist[diff][exist[diff].size()-1] > i){
                    cout<<"YES"<<nl;
                    return;
                }
            }
        }
        if(sum1 > sum/2)
        {
            diff = sum1 - (sum/2);
            if(exist[diff].size() != 0){
                //cout<<sum1 <<sp<<diff <<sp<<i<<sp<<arr[i]<<nl;
                if(exist[diff][0] <= i){
                    cout<<"YES"<<nl;
                    return;
                }
            }
        }
    }

    cout<<"NO"<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}





