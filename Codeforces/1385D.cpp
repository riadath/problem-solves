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

string cur;
int rec(int st,int en,char crc)
{
    int len = (en - st + 1);
    if(st == en)
    {
        if(cur[en] != crc)return 1;
        else return 0;
    }
    int c1 = 0,c2 = 0;
    int mid = (st + en)/2;
    fl(i,st,mid+1)
    {
        if(cur[i] == crc)c1++;
    }
    fl(i,mid+1,en+1)
    {
        if(cur[i] == crc)c2++;
    }
    crc++;
    int pp = ((len/2) - c1) + rec(mid+1,en,crc);

    int qq = ((len/2) - c2) + rec(st,mid,crc);

    return min(pp,qq);

}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        cin>>cur;
        int ans = rec(0,n-1,'a');
        cout<<ans<<nl;
    }

    return 0;
}















