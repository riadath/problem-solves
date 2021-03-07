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

void solve()
{
    int n;
    cin>>n;
    int temp = n/2;
    bool flag = true;
    if(temp%2 == 1){
        flag = false;
    }
    if(flag){
        cout << "YES\n";
        for(int i = 0;i < n/2;i++){
            cout << 2 * (i+1) << " ";
        }
         for(int i = 0;i < n/2 - 1;i++){
            cout << 2 * (i) + 1 << " ";
        }
        int sum = (n/2)* (n/2 + 1) - (n/2 - 1)*(n/2 - 1);
        cout << sum << "\n";
    }
    else{
        cout << "NO\n";
    }
}

int main()
{
    FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}

