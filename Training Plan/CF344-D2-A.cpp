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
//CF344-D2-A
void solve()
{
    int n;
    cin>>n;
    int curr,temp,cunt = 0;
    cin>>temp;
    curr = temp;
    fl(i,1,n){
        cin>>temp;
        if(temp != curr){
            cunt++;
            curr = temp;
        }
    }
    cout << cunt+1
    << "\n";
}

int main()
{
    FIO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    solve();
    return 0;
}

