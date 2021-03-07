#include <bits/stdc++.h>
using namespace std;

long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(int i = a;i < b;i++)
#define lf(i,a,b) for(int i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))

bool prime[100000];

void sieve()
{
    prime[0] = true,prime[1] = 1;
    for(int i = 4;i < 100000;i += 2)prime[i] = true;
    for(int i = 3;i < 1000;i += 2){
        for(int j = 2;i*j < 100000;j++){
            prime[i*j] = true;
        }
    }
}

ll num_of_div(ll n)
{
    int t = n;
    int nod = 1;
    for(ll i = 2;i*i <= n;i++){
        if(!prime[i]){
            int temp = 0;
            if(n%i == 0){
                while(n%i==0){
                    temp++;
                    n = n/i;
                }
                nod = nod*(temp+1);
            }
        }
    }
    if(n != 1)nod *= 2;
   // printf("NOD of %d : %d\n",t,nod);
    return nod;
}

void solve()
{
    memset(prime,false,sizeof(prime));
    sieve();
    ll n;
    while(true)
    {
        cin>>n;
        if(n == 0)break;
        int nod = num_of_div(n);
        if(nod%2)cout<<"yes\n";
        else cout<<"no\n";
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

