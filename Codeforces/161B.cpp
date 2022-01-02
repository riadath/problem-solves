#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = (int)a; i < (int)b; i++)
#define MEM(x, y) memset(x, y, sizeof(x))
#define PI acos(0)*2
#define fi first
#define se second
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b){return a.fi > b.fi;}

//f

int main()
{
    // FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ll n,k;cin>>n>>k;
    vector<pll>stool,pencil;
    long double sum = 0.0,disc = 0.0;
    fl(i,0,n){
        ll ci,ti;cin>>ci>>ti;
        sum += ci * 1.0;
        if(ti == 1)stool.pb(mp(ci,i + 1));
        else pencil.pb(mp(ci,i + 1));
    }
    sort(all(stool),comp);
    sort(all(pencil));
    fl(i,0,min((int)k-1,(int)stool.size())){
        disc += 0.5 * stool[i].fi;
    }
    debug(stool);
    debug(disc);
    if(stool.size() >= k){
        ll rem = 1e12;
        fl(i,k-1,stool.size())rem = min(rem,stool[i].fi);
        fl(i,0,pencil.size())rem = min(rem,pencil[i].fi);
        disc += 0.5 * rem;
        debug(disc);

        printf("%0.1Lf\n",sum - disc);
        fl(i,0,k-1){
            cout<<1<<" "<<stool[i].se<<"\n";
        }
        cout<<stool.size() - k + 1 + pencil.size()<<" ";
        fl(i,k-1,stool.size())cout<<stool[i].se<<" ";
        fl(i,0,pencil.size())cout<<pencil[i].se<<" ";   
        cout<<"\n";
    }
    else {
        printf("%0.1Lf\n",sum - disc);
        fl(i,0,stool.size()){
            cout<<1<<" "<<stool[i].se<<"\n";
        }
        int cnt = 0;
        fl(i,0,k - stool.size() - 1){
            cnt++;
            cout<<1<<" "<<pencil[i].se<<"\n";
        }
        cout<<pencil.size() - cnt<<" ";
        fl(i,cnt,pencil.size())cout<<pencil[i].se<<" ";
        cout<<"\n";

        
    }
    return 0;
}