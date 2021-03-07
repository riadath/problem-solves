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
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(),x.end())

//638div2C

void solve()
{
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        string arr;
        cin>>arr;
        srt(arr);
        if(k == 1){
            cout<<arr<<nl;
            continue;
        }
        int min_char = 0;
        fl(i,0,n-1){
            if(arr[i]==arr[i+1]){
                min_char++;
            }else break;
        }
        min_char++;
        if(min_char < k)cout<<arr[k-1]<<nl;
        else if(min_char >= k){
          string temp;
          temp.pb(arr[0]);
          if(arr[k]==arr[n-1])fl(i,0,(n-1)/k)temp.pb(arr[k]);
          else fl(i,k,n)temp.pb(arr[i]);
          cout<<temp<<nl;
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

