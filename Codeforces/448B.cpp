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

bool comp(const pll &a,const pll &b)
{
    return a.second >= b.second;
}
int cna[30],cnb[30];
int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a,b;
    cin>>a>>b;
    fl(i,0,a.size())
    {
        cna[a[i] - 'a']++;
    }
    fl(i,0,b.size())
    {
        cnb[b[i] - 'a']++;
    }
    bool chk = true;
    fl(i,0,26){
        if(cna[i] < cnb[i]){
            chk = false;
            break;
        }
    }
    if(b.size() > a.size())
    {
        cout<<"need tree"<<nl;
    }
    else if(!chk)
    {
        cout<<"need tree"<<nl;
    }
    else
    {
        if(a.size() == b.size())
        {
            cout<<"array"<<nl;
        }
        else
        {
            int st = 0;
            fl(i,0,a.size())
            {
                if(a[i] == b[st]){
                    st++;
                }
            }
            if(st == b.size()){
                cout<<"automaton"<<nl;
            }
            else cout<<"both"<<nl;
        }
    }
    return 0;
}















