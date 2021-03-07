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
    while(T--){
        string s;
        cin>>s;
        bool yes = true;
        bool flag = true;
        bool done = true;
        while(done){
            done = false;
            fl(i,0,s.size()-1){
                if(s[i] == '#')continue;
                if(s[i] == '0'){
                    int j = i+1;
                    while(s[j] == '#'){
                        if(s[j] != '#')break;
                        else j++;
                    }
                    if(s[j] == '1'){
                        s[i] = '#';
                        s[j] = '#';
                        flag = !flag;
                        done = true;
                        break;
                    }
                }
                else if(s[i] == '1'){
                    int j = i+1;
                    while(s[j] == '#'){
                        if(s[j] != '#')break;
                        else j++;
                    }
                    if(s[j] == '0'){
                        s[i] = '#';
                        s[j] = '#';
                        flag = !flag;
                        done = true;
                        break;
                    }
                }
            }
            if(!done){
                if(flag){
                   yes = false;
                }
            }
        }
        if(yes)cout<<"DA"<<nl;
        else cout<<"NET"<<nl;
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



