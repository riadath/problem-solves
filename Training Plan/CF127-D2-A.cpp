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

double dist(int x1,int y1,int x2,int y2)
{
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}

void solve()
{
    int n,k;
    cin>>n>>k;
    double x[n],y[n];
    fl(i,0,n)cin>>x[i]>>y[i];
    double total = 0;
    fl(i,0,n-1){
        total += dist(x[i],y[i],x[i+1],y[i+1]);
    }
    total *= k;
    total /= 50.00;
    printf("%0.10lf\n",total);
}

int main()
{
    FIO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    solve();
    return 0;
}

