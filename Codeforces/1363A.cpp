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
    fl(kas,1,T+1)
    {
        int n,x;
        cin>>n>>x;
        vector <int> odd,even;
        fl(i,0,n)
        {
            int temp;
            cin>>temp;
            if(temp%2)odd.pb(temp);
            else even.pb(temp);
        }
        if(x == 1 && odd.size() != 0){
            cout<<"Yes"<<nl;
        }
        else if(x == 1 && odd.size() == 0){
            cout<<"No"<<nl;
        }
        else if(x%2 == 0)
        {
            if(even.size() == 0 || odd.size() == 0)
            {
                cout<<"No"<<nl;
                continue;
            }
            int temp = x-1;
            while(odd.size() < temp)
            {
                if(temp <= 1)break;
                temp -= 2;
            }
            int ht = x - temp;
            if(even.size() < ht)
            {
                cout<<"No"<<nl;
            }
            else
            {
                cout<<"Yes"<<nl;
            }
        }
        else
        {
            if(odd.size() == 0)
            {
                cout<<"No"<<nl;
                continue;
            }
            int temp = x;
            while(odd.size() < temp)
            {
                if(temp <= 1){
                    break;
                }
                temp -= 2;
            }
            int ht = x - temp;
            if(even.size() < ht)
            {
                cout<<"No"<<nl;
            }
            else
            {
                cout<<"Yes"<<nl;
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

