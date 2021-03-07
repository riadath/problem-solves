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
    int T;
    cin>>T;
    while(T--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        int m = n/a;
        int left = n - m*a;
        string temp = "";
        for(int i = 0;i < b;i++){
            char c = 'a' + i;
            temp.pb(c);
        }
        char c = 'a';
        for(int i = 0;i < a-b;i++){
            temp.pb(c);
        }
        for(int i = 0;i < m;i++){
            cout<<temp;
        }
        if(left > 0){
            for(int i = 0;i < left;i++){
                cout<<temp[i];
            }
        }
        cout<<"\n";
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
