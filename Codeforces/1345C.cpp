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
    int T;
    cin>>T;
    while(T--)
    {
        map <int,int> ful;
        int n;
        cin>>n;
        int arr[n];
        fl(i,0,n)cin>>arr[i];
        bool flag = true;
        fl(i,0,n){
            int temp = i + arr[i];
            int n_r = temp%n;
            if(n_r < 0)n_r += n;
            if(ful[n_r] != 69){
                ful[n_r] = 69;
            }
            else if(ful[n_r] == 69){
                flag = false;
                break;
            }
        }
        if(flag)cout<<"YES"<<nl;
        else cout<<"NO"<<nl;
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

