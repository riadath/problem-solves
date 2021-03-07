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
    int arr[n];
    int c1 = 0,c2 = 0,c3 = 0;
    vector <int> in1,in2,in3;
    fl(i,0,n){
        cin>>arr[i];
        if(arr[i] == 1){
            c1++;
            in1.pb(i+1);
        }
        else if(arr[i] == 2){
            in2.pb(i+1);
            c2++;
        }
        else {
            c3++;
            in3.pb(i+1);
        }
    }
    int ans = min(c1,min(c2,c3));
    if(ans == 0){
        cout << 0 << "\n";
    }else{
        cout << ans << "\n";
            for(int i = 0;i < ans;i++){
                cout << in1[i] << " ";
                cout << in2[i] << " ";
                cout << in3[i] << " ";
                cout << "\n";
            }
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

