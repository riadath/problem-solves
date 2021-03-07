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
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (int i = a; i < b; i++)
#define lf(i, a, b) for (int i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(), x.end())

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        int a[n],b[n];
        fl(i,0,n)cin>>a[i];
        fl(i,0,n)cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        int cn = 0;
        if(a[0] >= b[n-1]) {}
        else
        {
            for(int i = 0,j = n-1; cn < k;)
            {
                if(a[i] < b[j]){
                    swap(a[i],b[j]);
                    i++,j--;
                    if(i >= n || j < 0)break;
                    cn++;
                }
               else if(a[i] >= b[j])break;
            }
        }
        int sum = 0;
        fl(i,0,n)
        {
            //cout<<"-"<<a[i]<<sp;
            sum += a[i];
        }
        //cout<<nl;
        cout<<sum<<nl;
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

