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

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        int len;
        cin>>len;
        string t;
        cin>>t;
        reverse(t.begin(),t.end());
        fl(i,0,len-1)
        {
            if(t[i] == '0' && t[i+1] == '1')
            {
                int pp = i+1;
                while(t[pp] == '1')
                {
                    if(pp > len-1)break;
                    t[pp] = '#';
                    pp++;
                }
                if(i > 0)
                {
                    pp = i-1;
                    if(t[pp] == '0' || t[pp] == '#')
                    {
                        while(t[pp] == '0' || t[pp] == '#')
                        {
                            if(pp < 0)break;
                            t[pp] = '#';
                            pp--;
                        }
                    }
                }

            }
        }
        //cout<<"->"<<t<<nl;
        lf(i,t.size()-1,0)if(t[i] != '#')cout<<t[i];
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



