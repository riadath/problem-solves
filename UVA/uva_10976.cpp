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
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int k;
    while(scanf("%d",&k) == 1){
        int ax[10001],ay[10001];
        int cnt = 0;
        if(k == 1){
            printf("1\n1/1 = 1/2 + 1/2\n");
            continue;
        }
        for(int x = k+1;x < k*(k+1);x++){
            if((k*x)%(x-k) == 0){
                if(x > (k*x)/(x-k))break;
                ax[cnt] = x;
                ay[cnt] = (k*x)/(x-k);
                cnt++;
            }
        }
        printf("%d\n",cnt);
        for(int i = 0;i < cnt;i++){
            printf("1/%d = 1/%d + 1/%d\n",k,ay[i],ax[i]);
        }
    }
    return 0;
}
