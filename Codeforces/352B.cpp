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
#define all(a) a.begin(),a.end()

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}


int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    map <int,pii> pos;
    fl(i,0,n)
    {
        int x;
        cin>>x;
        if(pos[x].fi == 0)
        {
            pos[x].fi = i+1;
            pos[x].se = 0;
        }
        else
        {
           // cout<<x<<sp<<i+1<<nl;
            int diff = (i+1) - pos[x].fi;
            if(pos[x].se == 0)
            {
                pos[x].fi = i+1;
                pos[x].se = diff;
            }
            else
            {
                if(pos[x].se != diff)pos[x].se = -1;
                else{
                    pos[x].fi = i+1;
                }
            }
        }
    }
    int cn = 0;
    for(auto i = pos.begin(); i != pos.end(); i++)
    {
        if(i->se.se != -1)cn++;
    }
    cout<<cn<<nl;
    for(auto i = pos.begin(); i != pos.end(); i++)
    {
        if(i->se.se != -1)cout<<i->fi<<sp<<i->se.se<<nl;
    }

    return 0;
}















