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
    int n;
    cin>>n;
    int arr[n];
    fl(i,0,n)cin>>arr[i];
    int dc = 0;
    int st = -1,en = -1;
    if(n != 1)
    fl(i,0,n-1)
    {
        if(arr[i] > arr[i+1])
        {
            st = i;
            dc++;
            while(true)
            {
                if(i >= n-1)break;
                else if(arr[i] > arr[i+1])i++;
                else break;
            }
            i--;
            en = i+1;
        }
        if(dc >= 2)
        {
            cout<<"no"<<nl;
            return;
        }
    }
    bool flag = true;
    if(st != -1)
    {
        int mx = arr[st];
        fl(i,en+1,n)
        {
            if(arr[i] < mx)
            {
                //  cout<<"wht the fycF"<<nl;
                flag = false;
                break;
            }
        }
    }
    if(en != -1){
        int mn = arr[en];
        fl(i,0,st){
            if(arr[i] > mn){
                flag = false;
                break;
            }
        }
    }
    if(flag)
    {
        cout<<"yes"<<nl;
        if(st != -1)cout<<st+1<<" "<<en+1;
        else if(st == -1)cout<<1<<" "<<1<<nl;

    }
    else cout<<"no"<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

