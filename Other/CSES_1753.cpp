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

string s1,s2,str;
vector<int>pi(4000009,0);
void KMP(){
    int len = (int)str.size();
    for(int i = 1;i < len;i++){
        int j = pi[i-1];
        while(j > 0 && str[j] != str[i]){
            j = pi[j-1];
        }
        if(str[i] == str[j])j++;
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
    cin>>s1>>s2;
    str = s2 + '#' + s1;
    KMP();
    int cnt = 0,l2 = (int)s2.size();
    fl(i,0,str.size()){
        if(pi[i] == l2)cnt++;
    }
    debug(str);
    cout<<cnt<<"\n";
    return 0;
}
