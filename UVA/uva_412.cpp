#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(ll i = a;i < b;i++)
#define lf(i,a,b) for(ll i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(),x.end())

void solve()
{
    int n;
    while(cin>>n && n)
    {
        int total = n*(n-1)/2;
        int arr[n];
        fl(i,0,n)cin>>arr[i];
        int cn = 0;
        fl(i,0,n)fl(j,i+1,n){
            if(__gcd(arr[i],arr[j]) == 1)cn++;
        }
        if(cn == 0){
            cout<<"No estimate for this data set."<<nl;
        }
        else{
            //cout<<total<<" "<<cn<<nl;
            double pi;
            pi = ((double)total/(double)cn)*6.0;
            pi = sqrt(pi);
            printf("%0.6f\n",pi);
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

