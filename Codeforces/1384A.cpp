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

bool comp(const pll &a,const pll &b)
{
    return a.second >= b.second;
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
        int arr[n+10];
        fl(i,0,n)cin>>arr[i];
        string s[n+10];
        fl(i,0,max(arr[0],1))
            s[0] += 'a';
        fl(i,0,n-1){
            int si = i+1;
            if(arr[i] != 0){
                fl(l,0,arr[i])
                    s[si] += s[i][l];
                int lm = arr[si] - arr[i];
                if(lm < 0)lm = 0;
                char ad = ((s[i][s[i].size()-1] - 'a') + 1)%26 + 'a';
                fl(k,0,lm)s[si] += ad;
            }
            else{
                s[si] += ((s[i][0] - 'a') + 1)%26 + 'a';
                fl(k,0,arr[si] - 1)s[si] += 'a';
            }
            //cout<<arr[i]<<sp<<s[si]<<nl;
        }
        if(arr[n-1] != 0)fl(i,0,max(1,arr[n-1]))s[n] += s[n-1][i];
        else{
            s[n] += ((s[n-1][0] - 'a') + 1)%26 + 'a';
        }
        fl(i,0,n+1)cout<<s[i]<<nl;
    }
    return 0;
}















