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
    vector <int> c;
    fl(i,0,n){
        int temp;
        cin>>temp;
        c.pb(temp);
    }
    cout<<abs(c[0]-c[1])<<" "<<abs(c[0]-c[n-1])<<nl;;
    fl(i,1,n-1){
        cout<<min(abs(c[i]-c[i-1]),abs(c[i]-c[i+1]))<<sp;
        cout<<max(abs(c[i]-c[n-1]),abs(c[i]-c[0]))<<nl;
    }
    cout<<abs(c[n-1]-c[n-2])<<" "<<abs(c[n-1]-c[0])<<nl;
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

