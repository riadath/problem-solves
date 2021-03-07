
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
string t = "abacaba";
int str_cnt(string s)
{
    int cnt = 0;
    int n = s.size();
    fl(i,0,n-7+1)
    {
        bool flag = true;
        if(s[i] == 'a')
        {
            for(int j = i,k = 0; k < 7; k++,j++)
            {
                if(s[j] != t[k])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)cnt++;
        }
    }
    return cnt;
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
        string s;
        cin>>s;
        string an = s;
        int cnt = str_cnt(s);
        if(cnt > 1)cout<<"NO"<<nl;
        if(cnt == 1)
        {
            fl(i,0,n)if(s[i] == '?')s[i] = 'x';
            cout<<"YES"<<nl;
            cout<<s<<nl;
        }
        bool done = true;
        if(cnt == 0)
        {
            fl(i,0,n-7+1)
            {
                bool flag = true;
                if(s[i] == 'a' || s[i] == '?')
                {
                    vector <int> poi;
                    for(int j = i,k = 0; k < 7; k++,j++)
                    {
                        //cout<<s[j]<<sp<<t[k]<<nl;
                        if(s[j] == '?')
                        {
                            s[j] = t[k];
                            poi.pb(j);
                        }
                        else if(s[j] != t[k])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag && str_cnt(s) == 1)
                    {
                        fl(k,0,n)if(s[k] == '?')s[k] = 'x';
                        cout<<"YES"<<nl;
                        cout<<s<<nl;
                        done = false;
                        break;
                    }
                    else
                    {
                        fl(l,0,poi.size())s[poi[l]] = '?';
                    }
                }
            }
            if(done)cout<<"NO"<<nl;
        }
    }
    return 0;
}














