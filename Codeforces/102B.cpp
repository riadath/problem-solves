
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
///102B
void solve()
{
    string a;
    cin>>a;
    int cnt = 0;
    if(a.size()==1){
        cout<<0<<nl;
        return;
    }
    while(true){
        ll temp = 0;
        cnt++;
        fl(i,0,a.size()){
            temp += (a[i]-'0');
        }
        if(temp < 10){
            cout<<cnt<<nl;
            return;
        }
        else{
            a.clear();
            while(temp != 0){
                a.pb(temp%10 + '0');
                temp /= 10;
            }
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
