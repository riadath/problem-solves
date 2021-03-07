#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define ull unsigned long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(int i = a;i < b;i++)
#define lf(i,a,b) for(int i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair


void solve()
{
    ll n;
    cin>>n;
    ll colors[n+5];
    ll freq[n+5];
    MEM(freq,0);
    fl(i,1,n+1){
        cin>>colors[i];
        freq[colors[i]]++;
    }
    ll total = 0;
    fl(i,0,n+1){
        if(freq[i] >= 2){
            ll temp = freq[i] * (freq[i]-1)/2;
            total += temp;
        }
    }
    //cout << total << endl;
    for(int i = 1;i <= n;i++){
        ll t = freq[colors[i]] - 1;
        ll sum = total - t;
        cout << sum << "\n";
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

