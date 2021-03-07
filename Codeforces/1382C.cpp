#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define ull unsigned long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double,double>
#define pll pair<long, long>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>
#define all(a) a.begin(),a.end()

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}

string rev(string a,int len){
    fl(i,0,len){
        a[i] = !(a[i] - '0') + '0';
    }
    reverse(a.begin(),a.begin()+len);
    return a;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int en = n-1;
        vector <int> tt;
        while(en >= 0){
            //cout<<a<<sp<<b<<nl;
            if(a[0] == b[en]){
                tt.pb(1);
                tt.pb(en+1);
                a[0] = !(a[0]-'0') + '0';
                a = rev(a,en+1);
            }
            else{
                tt.pb(en+1);
                a = rev(a,en+1);
            }
            while(a[en] == b[en])en--;
        }
        //cout<<"-> "<<a<<sp<<b<<nl;
        cout<<tt.size()<<sp;
        fl(i,0,tt.size())cout<<tt[i]<<sp;
        cout<<nl;
    }
    return 0;
}















