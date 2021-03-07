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
    int n;
    cin>>n;
    string a;
    cin>>a;
    if(a.size() == 1)cout<<a<<nl;
    else{
        string temp;
        temp.pb(a[n-2]);
        temp.pb(a[n-1]);
        for(int ct = n-3;ct >= 0;ct--){
            if(temp.size() == n)break;
            string tt;
            int sz = temp.size();
            fl(i,0,sz/2)tt.pb(temp[i]);
            tt.pb(a[ct]);
            fl(i,sz/2,temp.size())tt.pb(temp[i]);
            temp.clear();
            temp = tt;
        }
        cout<<temp<<nl;
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

