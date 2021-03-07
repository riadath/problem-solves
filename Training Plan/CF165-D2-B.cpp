
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
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";

void solve()
{
    long double n,k;
    cin>>n>>k;
    if(n <= k){
        cout << n <<nl;
    }
    else{
        long double mx_p = ceil(log(n)/log(k));
        long double mx_v = n/((1-pow((1/k),mx_p))/(1-(1/k)));
        ll nigga = ceil(mx_v) - 1;
       // cout<<"nigga:"<<nigga<<nl;
        for(ll bitch = nigga;;bitch++){
            ll sum = 0;
            for(ll p = 0;pow(k,p)<=n;p++){
              //  cout<<"sum: "<<sum<<nl;
                sum += floor(bitch/pow(k,p));
                if(sum >= n){
                    cout<<bitch<<nl;
                    return;
                }
            }
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
