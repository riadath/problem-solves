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
#define MX 5000000
int rel_prime[MX];
ull sum[MX];
void r_prime()
{
    for(int i = 1;i <= MX;i++){
        rel_prime[i] = i;
        if(i%2 == 0){
            rel_prime[i] /= 2;
        }
    }
    for(int i = 3;i <= MX;i += 2){
        if(rel_prime[i] == i){
            rel_prime[i] = rel_prime[i] - 1;
            for(int j = 2*i;j <= MX;j += i){
                rel_prime[j] /= i;
                rel_prime[j] *= (i-1);
            }
        }
    }
}
void c_sum()
{
    sum[1] = 0;
    for(int i = 2;i <= MX;i++){
        sum[i] = rel_prime[i];
        sum[i] *= sum[i];
        sum[i] += sum[i-1];
    }
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    r_prime();
    c_sum();
    int T;
    scanf("%d",&T);
    int kas = 1;
    while(T--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",kas++,sum[b] - sum[a-1]);
    }
    return 0;
}















