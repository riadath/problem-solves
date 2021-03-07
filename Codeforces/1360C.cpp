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
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        bool pres[1000];
        MEM(pres,false);
        int os = 0,es = 0;
        vector <int> even,odd;
        fl(i,0,n){
            cin>>arr[i];
            pres[arr[i]] = true;
            if(arr[i]%2 == 1)os++;
            es++;
        }
        if(os%2 == 0 && es%2 == 0){
            cout<<"YES"<<nl;
        }
        else{
            int cn = 0;
            fl(i,0,n){
                if(pres[arr[i]+1]){
                    cn++;

                }else if(pres[arr[i]-1]){
                    cn++;
                }
                if(cn >= 1)break;
            }
            if(cn >= 1)cout<<"YES"<<nl;
            else cout<<"NO"<<nl;
        }
    }
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

