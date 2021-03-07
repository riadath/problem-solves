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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int kas = 1;
    string temp;

    while(true)
    {
        cin>>temp;
        if(temp == "#")break;
        if(temp == "HELLO"){
            cout<<"Case "<<kas++<<": "<<"ENGLISH"<<nl;
        }
        else if(temp == "HOLA"){
            cout<<"Case "<<kas++<<": "<<"SPANISH"<<nl;
        }
         else if(temp == "HALLO"){
            cout<<"Case "<<kas++<<": "<<"GERMAN"<<nl;
        }
         else if(temp == "BONJOUR"){
            cout<<"Case "<<kas++<<": "<<"FRENCH"<<nl;
        } else if(temp == "CIAO"){
            cout<<"Case "<<kas++<<": "<<"ITALIAN"<<nl;
        } else if(temp == "ZDRAVSTVUJTE"){
            cout<<"Case "<<kas++<<": "<<"RUSSIAN"<<nl;
        }
        else{
            cout<<"Case "<<kas++<<": "<<"UNKNOWN"<<nl;
        }


    }
    return 0;
}















