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
    bool b[26];
    MEM(b,false);
    fl(i,0,n){
        int temp = a[i];
        if(a[i] >= 65 && a[i] <= 91)temp -= 65;
        else temp -= 97;
        b[temp] = true;
    }
    int cnt = 0;
    fl(i,0,26)if(b[i])cnt++;
    if(cnt==26)cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

