/**
Reyadath Ullah Akib
**/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(int i = a;i < b;i++)
#define lf(i,a,b) for(int i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))


void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        ll a[n],b[n];
        fl(i,0,n)cin>>a[i]>>b[i];
        ll ze = 0,bullets = 0;
        ll t = 0;
        ll minimum = 100000000000000000;
        fl(i,0,n){
            int t = (i+1)%n;
            //cout<<bullets<<"\n";
            minimum = min(minimum,min(a[t],b[i]));
            bullets += max(ze,a[t] - b[i]);

        }
        //cout<<minimum<<endl;
        cout<<bullets+minimum<<"\n";
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
