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
#define pi4 pair<pii,pii>
#define all(a) a.begin(),a.end()

bool comp(const pii &a,const pii &b){
    return a.second < b.second;
}


int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n+100];
        fl(i,0,n){
            int x;
            cin>>x;
            arr[i] = x - (i+1);
        }
        int st = 0,en = n-1;
        if(arr[st] == 0){
            while(arr[st] == 0 && st < n)st++;
        }
        if(st == n){
            cout<<0<<nl;
            continue;
        }
        if(arr[en] == 0){
            while(arr[en] == 0 && en >= 0)en--;
        }
        int p = 0;
        fl(i,st,en+1){
            if(arr[i] == 0){
                p = 1;
                break;
            }
        }
        //cout << st <<sp <<en<<nl;
        cout<<p + 1<<nl;
    }
    return 0;
}















