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
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

bool if_pal(string temp)
{
    for(int i = 0,j = temp.size()-1;i < temp.size()/2;i++,j--){
        if(temp[i] != temp[j])return false;
    }
    return true;
}

void solve()
{
    int n;
    int m;
    cin>>n>>m;
    vector <string> arr;
    fl(i,0,n){
        string tt;
        cin>>tt;
        arr.pb(tt);
    }
    bool rev[n+100];
    vector<string>fir,sec,pals;
    int pal = 0;
    MEM(rev,false);
    fl(i,0,n){
        string temp = arr[i];
        reverse(temp.begin(),temp.end());
        if(!rev[i])
        fl(j,0,n){
            if(j == i)continue;
            if(arr[j] == temp && !rev[j]){
                fir.pb(arr[i]);
                sec.pb(temp);
                rev[i] = true;
                rev[j] = true;
                break;
            }
        }
        if(!rev[i] && if_pal(arr[i])){
            pals.pb(arr[i]);
            pal++;
        }
    }
    int cn = 0;
    fl(i,0,n)if(rev[i])cn++;
    if(pal > 0)cn++;
    ll ans = cn*m;
    if(ans == 0){
        cout<<0<<nl;
        cout<<nl;
        return;
    }
    string res = "";
    if(fir.size() != 0)lf(i,fir.size()-1,0)res += fir[i];
    if(pal > 0)res += pals[0];
    if(sec.size() != 0)fl(i,0,sec.size())res += sec[i];
    cout<<ans<<nl;
    cout<<res<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout)
    solve();
    return 0;
}

