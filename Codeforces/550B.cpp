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

ll n,lm,rm,x;
ll cn = 0;
vector <ll> arr;
void combinationUtil(int data[],int start, int en,int index, int r)
{

    if (index == r)
    {
        int mn = 1e8,mx = -1e8;
        int sum = 0;
        fl(k,0,r){
           // cout<<data[k]<<sp;
            mn = min(data[k],mn);
            mx = max(data[k],mx);
            sum += data[k];
        }
       // cout<<nl;
        //cout<<sum<<nl;
        if(mx-mn >= x && sum >= lm && sum <= rm){
            cn++;
            //cout<<"here"<<nl;
        }
        return;
    }

    for (int i = start; i <= en &&
        en - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combinationUtil(data,i+1, en, index+1, r);
    }
}

int main()
{
    //FIO;
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    cin>>n>>lm>>rm>>x;

    fl(i,0,n){
        ll temp;
        cin>>temp;
        if(temp < rm)arr.pb(temp);
    }
    srt(arr);
    n = arr.size();
    fl(i,2,n+1){
        int data[100];
        combinationUtil(data,0,n-1,0,i);
    }
    cout<<cn<<nl;
    return 0;
}















