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

bool comp(const int a,const int b)
{
    return a >= b;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

void solve()
{
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        vector <int> neg;
        fl(i,0,n){
            int temp;
            cin>>temp;
            neg.pb(temp);
        }
        srt(neg);

        /*fl(i,0,pos.size()){
            neg.pb(pos[i]);
        }*/

        /*fl(i,0,neg.size())cout<<neg[i]<<sp;
        cout<<nl;*/

        int st = 0,en = n-1;
        ll happy = 0;
        vector <int> did;
        int ocn = 0;
        fl(i,0,k){
            int temp;
            cin>>temp;
            if(temp == 1)ocn++;
            else did.pb(temp);
        }
        srt(did);
        fl(i,0,ocn){
            happy += neg[en]*2;
            en--;
        }
        for(int i = did.size()-1;i >= 0;i--){
            int w = did[i];
            //cout<<neg[st]<<sp<<neg[en]<<nl;
            happy += neg[st];
            happy += neg[en];
            st += (w-1);
            en--;
        }
        cout<<happy<<nl;
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


