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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    string str;
    cin>>str;
    int total = 0;
    fl(i,0,str.size()){
        int temp = str[i] - '0';
        if(temp == 1){
            total += a;
        }else if(temp == 3){
            total += c;
        }
        else if(temp == 2){
            total += b;
        }
        else if(temp==4){
            total += d;
        }
    }
    cout << total << "\n";
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

