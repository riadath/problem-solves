#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(int i = a;i < b;i++)
#define lf(i,a,b) for(int i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
map <int,ll> car;
map <int,int> rep;
void pre_process()
{
    int in = 2;
    int diff = 5;
    while(in <= 1e9)
    {
        car[in] = 1;
        in += diff;
        diff += 3;
    }
}

void solve()
{
    pre_process();
    int T;
    cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        int cnt = 0;
        int st = n;
        int bg = n;
        if(rep[bg] != 0)cout<<rep[bg]<<nl;
        else{
            while(n >= 2){
                if(car[n] == 0){
                    n--;
                }
                else if(car[n] == 1){
                    st = (st - n);
                    cnt++;
                    n = st;
                    if(rep[n] != 0){
                        cnt += rep[n];
                        break;
                    }
                }
            }
            rep[bg] = cnt;
            cout<<cnt<<nl;
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









