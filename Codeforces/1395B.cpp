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
#define pll pair<ll, ll>
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


int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,sx,sy;
    cin>>n>>m>>sx>>sy;
    int cx = sx,cy = sy;
    cout<<sx<<sp<<sy<<nl;
    fl(i,1,sy)cout<<cx<<sp<<i<<nl;
    fl(i,sy+1,m+1)cout<<cx<<sp<<i<<nl;
    cx += 1,cy = m;
    while(cx <= n){
        if(cy == m){
            while(cy >= 1){
                cout<<cx<<sp<<cy<<nl;
                cy--;
            }
            cx +=1;
            cy = 1;
        }
        else if(cy == 1){
            while(cy <= m){
                cout<<cx<<sp<<cy<<nl;
                cy++;
            }
            cy = m;
            cx += 1;
        }
    }
    cx = 1;
    while(cx < sx){
        if(cy == m){
            while(cy >= 1){
                cout<<cx<<sp<<cy<<nl;
                cy--;
            }
            cx +=1;
            cy = 1;
        }
        else if(cy == 1){
            while(cy <= m){
                cout<<cx<<sp<<cy<<nl;
                cy++;
            }
            cy = m;
            cx += 1;
        }
    }
    return 0;
}















