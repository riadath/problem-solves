#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

// #pragma GCC target("avx2")
// #pragma GCC optimization("O3")
// #pragma GCC optimization("unroll-loops")

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
    return a.fi < b.fi;
}



int dp[16][1<<16],damage[20][20],arr[20],n;
char mat[20][20];


void bitSET(int num)
{
    int svv = num;
    string str;
    while (num != 0)
    {
        if (num % 2 == 0)
            str += "0";
        else
            str += "1";
        num /= 2;
    }
    while ((int)str.size() < n)
    {
        str = str + '0';
    }
    reverse(all(str));
    cout <<  " ==> " << str << nl;
}

int f(int i,int bt){
    // bitSET(bt);
    if(i >= n)return 0;
    if(dp[i][bt] != -1)return dp[i][bt];
    int mv = 0,ret = 1e8;

    fl(j,0,n){
        if(!((1 << j) & bt)){
            ret = min(ret,arr[j] + f(i + 1,bt | (1<<j)));
            fl(k,0,n){
                if(1<<k & bt && damage[k][j] != 0){
                    mv = arr[j]/damage[k][j] + (arr[j]%damage[k][j] != 0) + f(i + 1,bt | 1 << j);
                    ret = min(ret,mv);
                }
            }
        }
    }
    return dp[i][bt] = ret;
}
int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    scanf("%d", &T);
    while (T--)
    {
        MEM(dp,-1);
        scanf("%d",&n);
        fl(i,0,n)scanf("%d",&arr[i]);
        fl(i,0,n){
            scanf("%s",mat[i]);
        }
        fl(i,0,n)fl(j,0,n)damage[i][j] = mat[i][j] - '0';
        // sort(arr,arr+n);
        printf("Case %d: ", kas++);
        printf("%d\n",f(0,0));
    }
    return 0;
}
