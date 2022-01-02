#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

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
#define fl(i, a, b) for (ll i = (int)a; i < (int)b; i++)
#define lf(i, b, a) for (ll i = (int)b; i >= (int)a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define srt(x) sort(x.begin(), x.end())
#define PI 3.141592653589793238
#define fi first
#define se second
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.fi < b.fi;
}

vector<int>pi(200009,0);
void KMP(string s){
    int n = (int)s.size();
    pi[0] = 0;
    for(int i = 1;i < n;i++){
        int j = pi[i-1];
        while(j > 0 && s[j] != s[i]){
            j = pi[j-1];
        }
        if(s[j] == s[i])j++;
        pi[i] = j;
    }
}


int main()  
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    string s1;cin>>s1;
    int n = s1.size();
    string s = s1;
    KMP(s);
    
    // cout<<s<<"\n";
    // fl(i,0,2*n+1)cout<<pi[i];
    // cout<<"\n";

    vector<int>ans(n+1,0);
    for(int i = 0;i < n;i++){
        ans[pi[i]]++;
    }
    for(int i = n-1;i > 0;i--){
        ans[pi[i-1]] += ans[i];
    }
    for(int i = 0;i <= n;i++){
        ans[i]++;
    }
    debug(ans);

    vector<pii>out;
    int j = n-1;
    while(pi[j]){
        out.pb(mp(pi[j],ans[pi[j]]));
        j = pi[j] - 1;
    }
    out.pb(mp(n,ans[n]));
    sort(all(out),comp);
    cout<<(int)out.size()<<"\n";
    for(int i = 0;i < (int)out.size();i++){
        cout<<out[i].fi<<" "<<out[i].se<<"\n";
    }
    return 0;
}
