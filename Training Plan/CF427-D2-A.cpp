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
    int num_of = 0;
    int ut = 0;
    fl(i,0,n){
        int temp;
        cin>>temp;
        if(temp != -1){
            num_of += temp;
        }
        else if(temp == -1){
            if(num_of > 0){
                num_of--;
            }else{
                ut++;
            }
        }
    }
    cout << ut << "\n";
}

int main()
{
    FIO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    solve();
    return 0;
}

