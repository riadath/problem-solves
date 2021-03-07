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
int coin[25];
int dp[25][210];
int n,total;

bool f(int i,int cost)
{
    if(i >= n){
        if(cost == total-cost)return true;
        else return false;
    }
    if(dp[i][cost] != -1)return dp[i][cost];
    bool a = false,b = false;
    if(cost+coin[i] <= total/2)a = f(i+1,cost + coin[i]);
    b = f(i+1,cost);
    return dp[i][cost] = a||b;
}

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        getline(cin,str);
        while(str.length()==0)getline(cin,str);
        stringstream s;
        s<<str;
        string temp;
        int found;
        n = 0,total = 0;
        while(!s.eof()){
            s>>temp;
            if(stringstream(temp)>>found){
                coin[n] = found;
                total += found;
                n++;
            }
            temp = "";
        }
        if(total%2==1)cout<<"NO"<<nl;
        else{
            MEM(dp,-1);
            bool flag = f(0,0);
            if(flag)cout<<"YES"<<nl;
            else cout<<"NO"<<nl;
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

