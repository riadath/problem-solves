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
    while(T--){
        string a,b;
        cin>>a>>b;
        if(a.size() < b.size())swap(a,b);
        string t;
        int carry = 0;
        fl(i,0,b.size()){
            int temp = (a[i]-'0')+(b[i]-'0')+carry;
            t.pb(temp%10+'0');
            carry = temp/10;
        }
        fl(i,b.size(),a.size()){
            int temp = a[i]-'0'+carry;
            t.pb(temp%10+'0');
            carry = temp/10;
        }
        while(carry != 0){
            t.pb(carry%10+'0');
            carry /= 10;
        }
        int st = 0;
        while(t[st] == '0'){
            st++;
        }
        fl(i,st,t.size())cout<<t[i];
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

