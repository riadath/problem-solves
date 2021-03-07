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

///CF770-D2-A
void solve()
{
    int n,a;
    cin>>n>>a;
    string temp;
    fl(i,0,a){
        temp.pb('a'+i);
    }
    int num = floor(n/a);
    for(int i = 0;i < num;i++){
        cout << temp ;
    }
    int left = n - num * a;
    fl(i,0,left){
        cout << temp[i];
    }
    cout << "\n";
}

int main()
{
    FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    solve();
    return 0;
}

