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
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        vector <int> nums;
        int pos = 0;
        for(int i = a.size()-1;i >= 0;i--){
            if(a[i] != '0'){
                nums.pb(pow(10,pos) * (a[i]-'0'));
            }
            pos++;
        }
        cout<<nums.size()<<nl;
        fl(i,0,nums.size())cout<<nums[i]<<sp;
        cout<<nl;
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

