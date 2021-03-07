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

int main()
{
    FIO;
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,x,y;
    cin>>a>>x>>y;
    if(y == 0){
        cout<<-1<<nl;
    }
    else if(y%a == 0)cout<<-1<<nl;
    else{
        int cor = y / a;
        cor++;
        //cout<<cor<<nl;
        if(cor == 1 || cor%2 == 0){
            if(abs(x) >= ((a/2 + a%2)))cout<<-1<<nl;
            else{
                if(cor == 1)cout<<1<<nl;
                else{
                    int num = 2 + (cor/2 - 1)*3;
                    cout<<num<<nl;
                }
            }
        }
        else if(cor%2 == 1){
            if(x == 0)cout<<-1<<nl;
            else if(abs(x) >= a)cout<<-1<<nl;
            else{
                int num = 2 + ((cor+1)/2 - 1)*3;
                num -= 2;
                if(x < 0)cout<<num<<nl;
                else cout<<num+1<<nl;
            }
        }

    }
    return 0;
}















