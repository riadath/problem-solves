#include <bits/stdc++.h>
using namespace std;

long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(int i = a;i < b;i++)
#define lf(i,a,b) for   (int i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
//team
void solve()
{
    int n;
    cin>>n;
    int cn = 0;
    fl(i,0,n){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b+c >= 2)cn++;
    }
    cout << cn <<"\n";
}

int main()
{
    FIO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    solve();
    return 0;
}

