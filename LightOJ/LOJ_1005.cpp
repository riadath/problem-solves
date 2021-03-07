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


int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int kas = 1;
    while(T--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        ll tot = 1;
        if(k > n)tot = 0;
        else{
            int arr[k+1];
            MEM(arr,true);
            for(int i = n,j = 1;j <= k;i--,j++){
                tot *= i*i;
                for(int fact = 1;fact <= k;fact++){
                    if(arr[fact] && tot%fact == 0){
                        tot /= fact;
                        arr[fact] = false;
                    }
                }
            }
        }
        printf("Case %d: %lld\n",kas++,tot);
    }
    return 0;
}















