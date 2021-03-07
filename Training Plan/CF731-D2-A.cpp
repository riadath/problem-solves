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
    string a;
    cin>>a;
    int curr = 0,moves = 0;
    fl(i,0,a.size()){
        int temp = a[i] - 97;
        //cout << temp << "\n";
        int fr,bc;
        fr = abs(temp - curr);
        bc = 26 - fr;
        moves += min(fr,bc);
        curr = temp;
    }
    cout << moves << "\n";
}

int main()
{
    FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    solve();
    return 0;
}

