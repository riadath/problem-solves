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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int cn = 0;
        //if(n == 1 && s[0] == '0')cout<<"1"<<nl;
        //else if(n == 2 && s[0] == '0' && s[1] == '0')cout<<"1"<<nl;
        //else{
            if(s[0] == '0'){
                bool flag = true;
                fl(i,0,k+1){
                    if(s[i] == '1'){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cn++;
                    s[0] = '1';
                }
            }
            if(s[n-1] == '0'){
                bool flag = true;
                lf(i,n-1,n-1-k){
                     if(s[i] == '1'){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cn++;
                    s[n-1] = '1';
                }
            }
            for(int i = 0,j = 0;i < n;i++){
                if(s[i] == '1'){
                    j = 0;
                }
                if(s[i] == '0'){
                   if(j >= k){
                        bool flag = true;
                        fl(pp,i,i+j+1){
                            if(s[pp] == '1'){
                                flag = false;
                                j = 0;
                                i = pp;
                            }
                        }
                        if(flag){
                            cn++;
                            j = 0;
                            i = i+j;
                        }
                    }
                    else{
                        j++;
                    }
                }
            }
            cout<<cn<<nl;
        //}
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

