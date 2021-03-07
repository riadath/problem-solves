#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(ll i = a;i < b;i++)
#define lf(i,a,b) for(ll i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(),x.end())

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        if(n%2 == 1 && k%2 == 0){
            cout<<"NO"<<nl;
            continue;
        }

        if(k > n){
            cout<<"NO"<<nl;
            continue;
        }
        else if(n%2 == 0&&k%2 == 1){
            if(k*2 > n){
                cout<<"NO"<<nl;

            }
            else{
                int tt = n/k;
                if(tt%2==1){
                    if(tt == 1)tt++;
                    else tt--;
                }
                cout<<"YES"<<nl;
                int sum = (k-1)*tt;
                fl(i,0,k-1){
                    cout<<tt<<sp;
                }
                cout<<n - sum<<nl;
            }
        }
        else if(n%2 == 0 && k%2 == 0){
            cout<<"YES"<<nl;
            int sum = (k-1)*1;
            fl(i,0,k-1){
                cout<<1<<sp;
            }
            cout<<n - sum<<nl;
        }
        else if(n%2 == 1&&k%2 == 1){
            int tt = n/k;
            if(tt%2==0){
                tt--;
            }
            cout<<"YES"<<nl;
            int sum = (k-1)*tt;
            fl(i,0,k-1){
                cout<<tt<<sp;
            }
            cout<<n - sum<<nl;
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

