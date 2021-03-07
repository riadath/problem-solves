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


int arr[100009];
int remain[4];
int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,sq = 0;
    cin>>n;
    fl(i,0,n){
        int x;
        cin>>x;
        remain[ arr[x] % 4]--;
        arr[x]++;
        remain[ arr[x] % 4]++;
    }

    for(int i = 1; i <= 100000; i++){
        sq += arr[i]/4;
    }

    int len = n,q;
    cin>>q;
    fl(i,0,q)
    {
        char a;
        int x;
        cin>>a>>x;
        remain[arr[x]%4]--;
        sq -= arr[x]/4;
        if(a == '+'){
            arr[x]++;
            len++;
        }
        else{
            arr[x]--;
            len--;
        }
        remain[arr[x]%4]++;
        sq += arr[x]/4;
        bool flag;
        if(sq > 1)flag = true;
        else if(sq == 1 && (remain[2]+remain[3])/2 > 0)flag = true;
        else flag = false;
        if(flag && len > 0)cout<<"YES"<<nl;
        else cout<<"NO"<<nl;
    }
    return 0;
}















