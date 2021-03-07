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
    string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char c;
    cin>>c;
    string a;
    cin>>a;
    int mv = 0;
    if(c == 'R')mv = -1;
    if(c == 'L')mv = +1;
    fl(i,0,a.size()){
        fl(j,0,s.size())if(a[i] == s[j]){
            cout<<s[j+mv];
            break;
        }
    }
    cout<<nl;
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

