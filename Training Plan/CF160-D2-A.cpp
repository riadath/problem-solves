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
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    int total = 0;
    fl(i,0,n){
        cin>>arr[i];
        total+= arr[i];
    }
    sort(arr,arr+n);
    int sum = 0,cnt = 0;
    lf(i,0,n-1){
        sum += arr[i];
        cnt++;
        if(sum > (total-sum)){
            break;
        }
    }
    cout<<cnt<<nl;
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

