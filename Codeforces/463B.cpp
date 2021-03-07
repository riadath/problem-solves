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
///463B
void solve()
{
    int t;
    cin>>t;
    int arr[t];
    fl(i,0,t)cin>>arr[i];
    ll en = 0,s = arr[0];
    fl(i,1,t){
        if(arr[i] > arr[i-1]){
            if(arr[i]-arr[i-1] > en){
                s += (arr[i]-arr[i-1])-en;
                en = 0;
            }
            else{
                en += (arr[i-1]-arr[i]);
            }
        }
        else{
            en += (arr[i-1]-arr[i]);
        }
    }
    cout<<s<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

