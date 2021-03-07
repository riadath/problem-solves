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
#define pdd pair<double, double>
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
#define pi 2 * acos(0)
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.second < b.second;
}
int main()
{
    FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, kas = 1;
    cin >> T;
    while (T--)
    {
        int n;
        cin>>n;
        queue<int> er,odr;
        queue<int> eb,ob;
        int cnt = n;
        string num;
        cin>>num;
        lf(i,n-1,0){
            int t = num[i] - '0';
            if((i+1)%2){
                if(t%2)odr.push(t);
                else er.push(t);
            }
            else{
                if(t%2)ob.push(t);
                else eb.push(t);
            }
        }
        bool turn = 0;
        while(cnt > 1){
            if(!turn){
                if(!er.empty()){
                    er.pop();
                    cnt--;
                }else if(!odr.empty()){
                    odr.pop();
                    cnt--;
                }
                turn = !turn;
            }else{
                if(!ob.empty()){
                    ob.pop();
                    cnt--;
                }else if(!eb.empty()){
                    eb.pop();
                    cnt--;
                }
                turn = !turn;
            }
        }
        int ans;
        if(!er.empty())ans = er.front();
        else if(!odr.empty())ans = odr.front();
        else if(!ob.empty())ans = ob.front();
        else if(!eb.empty())ans = eb.front();
        if(ans%2)cout<<1<<nl;
        else cout << 2 <<nl;
    }
    return 0;
}
