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
#define lf(i, a, b) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(), x.end())
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
double dt(int x1,int y1,int x2,int y2)
{
    double dist = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
    return dist;
}
void solve()
{
    int n,m;
    double mxra;
    cin>>n>>m>>mxra;
    map<char,vector<pii>> key;
    map<int,pii>shi;
    int sc = 0;
    fl(i,0,n)
    {
        string temp;
        cin>>temp;
        fl(j,0,m)
        {
            if(temp[j] == 'S')
            {
                shi[sc++] = mp(i+1,j+1);
            }
            else key[temp[j]].pb(mp(i+1,j+1));
        }
    }

    int len;
    cin>>len;
    string a;
    cin>>a;
    int rb[27];
    fl(i,0,27)
    {
        char c = 'a' + i;
        if(key[c].size() == 0)rb[i] = -1;
        else
        {
            bool flag = false;
            for(auto i = key[c].begin(); i != key[c].end(); i++)
            {
                int x = i->first,y = i->second;
                fl(j,0,sc)
                {
                    int x1 = shi[j].first,y1 = shi[j].second;

                    double dist = dt(x,y,x1,y1);
                    if(dist <= mxra)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)rb[i] = 1;
            else rb[i] = 2;
        }
    }



    int cn = 0;
    fl(i,0,len)
    {
        if(rb[a[i]-'a'] == -1)
        {
            cout<<-1<<nl;
            return;
        }
        else if(a[i] >= 65 && a[i] <= 90)
        {
            if(sc == 0)
            {
                cout<<-1<<nl;
                return;
            }
            char c = a[i] + 32;
            c = c - 'a';
            if(rb[c] == -1)
            {
                cout<<-1<<nl;
                return;
            }
            else if(rb[c] == 2)
            {
                cn++;
            }
        }
    }
    cout<<cn<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

