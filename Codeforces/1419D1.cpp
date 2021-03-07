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
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define pi 2 * acos(0)
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.second < b.second;
}
int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    ll arr[n+10];
    fl(i,0,n)cin>>arr[i];
    sort(arr,arr+n);
    int st = 0,en = n-2;
    int cn = 0;
    // if(arr[st] == arr[en+1]){
    //     cout << 0 << nl;
    //     return 0;
    // }
    queue <int> list;
    while(st < en){
        if(arr[st] >= arr[en]){
            break;
        }
        list.push(arr[st]);
        cn++,st++,en--;
    }
    bool flag = 0;
    cout << cn <<nl;
    lf(i,n-1,st){
        if(!flag || list.empty()){
            cout << arr[i] <<sp;
            flag = !flag;
        }
        if(flag && !list.empty()){
            cout << list.front() <<sp;
            list.pop();
            flag = !flag;
        }
    }
   
    
    return 0;
}
