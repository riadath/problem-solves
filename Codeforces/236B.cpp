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

bool comp(const pii &a,const pii &b){
    return a.second < b.second;
}
#define MOD 1073741824
#define MX 1000109

ll nod[MX];
bool flag[MX];
vector <ll> primes;

void sieve()
{
    for(ll i = 4;i <= MX;i += 2)flag[i] = true;
    for(ll i = 3;i*i <= MX;i++){
        for(ll j = 2;i*j <= MX;j++){
            flag[i*j] = true;
        }
    }
    fl(i,2,MX)if(!flag[i]){

        primes.pb(i);
    }
}
void NOD_CAL()
{
    sieve();
    nod[1] = 1;
    for(ll j = 2;j <= MX;j++){
        ll n = j;
        ll cnt = 1;
        for(int i = 0;primes[i]*primes[i] <= n && i < primes.size();i++){
           // cout<<"--->"<<primes[i]<<nl;
            if(n % primes[i] == 0){
                ll temp = 0;
                while(n % primes[i] == 0){
                    temp += 1;
                    n /= primes[i];
                }
                cnt *= (temp+1);
            }
        }
        if(n != 1)cnt *= 2;
        nod[j] = cnt;
        //cout<<"nod("<<j<<") : "<<nod[j]<<nl;
    }
}
int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    NOD_CAL();
    ll a,b,c;
    cin>>a>>b>>c;
    ll sum = 0;
    fl(i,1,a+1){
        fl(j,1,b+1){
            fl(k,1,c+1){
                ll temp = nod[i*j*k];
                //cout<<i*j*k<<sp<<temp<<nl;
                sum += temp;
                sum %= MOD;
            }
        }
    }
    cout<<sum<<nl;

    return 0;
}















