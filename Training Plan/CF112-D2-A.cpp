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
    string a,b;
    cin>>a>>b;
    fl(i,0,a.size()){
        if(a[i] >= 65 && a[i] <= 91){
            a[i] = a[i] + 32;
        }
        if(b[i] >= 65 && b[i] <= 91){
            b[i] = b[i] + 32;
        }
    }
    if(lexicographical_compare(a.begin(),a.end(),b.begin(),b.end())){
        cout << -1 << "\n";
    }else if(lexicographical_compare(b.begin(),b.end(),a.begin(),a.end())){
        cout << 1 << "\n";
    }else{
        cout << 0 << "\n";
    }
}

int main()
{
   // FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    solve();
    return 0;
}

