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
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.second > b.second;
}

int main()
{
    //FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        if(kas++ > 1)printf("\n");
        ll n,lim = 2e10;
        scanf("%lld",&n);
        for(ll i = 1;;i++){
            if(n*i >= lim)break;
            bool flag = true;
            ll num = n*i,den = i,arr[12]; 
            fl(i,0,10)arr[i] = 0;
            while(num != 0){
                arr[num%10]++;
                num /= 10;
            }

            fl(i,0,10)if(arr[i] > 1)flag = false;

            fl(i,0,10)arr[i] = 0;
            while(den != 0){
                arr[den%10]++;
                den /= 10;
            }

            fl(i,0,10)if(arr[i] > 1)flag = false;

            if(flag){
                printf("%lld / %lld = %lld\n",n*i,i,n);
            }
        }
    }
    return 0;
}
