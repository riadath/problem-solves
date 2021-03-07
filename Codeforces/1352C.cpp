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
        ll n,k;
        cin>>n>>k;
        if(n > k)
        {
            cout<<k<<nl;
            continue;
        }
        if(n == k)
        {
            cout<<n+1<<nl;
            continue;
        }
        if(n == 2)
        {
            cout<<2*k-1<<nl;
        }
        else
        {
            ll st = k;
            if(st%n != 0)
                st--;
            ll pos = st - (st/n);
            while(pos < k){
                ll pp = (k-pos);
                ll tit =st + pp;
                pos = tit - (tit/n);
                st = tit;
            }
            //cout<<"POS : "<<pos<<"  NUM : "<<st<<nl;
            while(true)
            {
                if(pos >= k)
                    break;
                st++;
                if(st%n != 0)
                    pos++;
            }
            cout<<st<<nl;
        }
    }
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

