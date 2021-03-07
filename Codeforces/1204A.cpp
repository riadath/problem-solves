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
    string a;
    cin>>a;
    bool flag = false;
    fl(i,1,a.size()){
        if(a[i] == '1'){
            flag = true;
            break;
        }
    }
    int len = a.size()-1;

    if(len < 1)len = 0;
    else if(len <= 1)len = 1;
    else if(len <= 2 && !flag)len = 1;
    else if(len <= 2 && flag)len = 2;
    else if(!flag){
        if(len%2)len = len/2 + 1;
        else len = len/2;
    }
    else{
        int st = len - 2;
        len = 2;
        len += (st)/2;
    }
    cout<<len<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

