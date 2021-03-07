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
#define mp make_pair

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        string arr;
        cin>>arr;
        if(arr.size() <= 2)cout << arr <<"\n";
        else{
            int z = 0,o = 0;
            fl(i,0,arr.size()){
                if(arr[i] == '0')o++;
                else z++;
            }
            if(z == 0 || o == 0)cout << arr <<"\n";
            else{
                string tt;
                for(int i = 0;i < arr.size()-1;i++){
                    if(arr[i] == arr[i+1]){
                        if(tt[tt.size()-1] !=arr[i])tt.pb(arr[i]);
                        if(arr[i]=='1')tt.pb('0');
                        else tt.pb('1');
                        tt.pb(arr[i+1]);
                    }
                    else{
                        if(tt[tt.size()-1] !=arr[i])tt.pb(arr[i]);
                        tt.pb(arr[i+1]);
                    }
                }
                cout << tt <<"\n";
            }
        }
    }

}

int main()
{
    //FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

