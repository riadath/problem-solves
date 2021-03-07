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
unordered_map <int,vector<int>> m;
int num(int arr[],int st,int en)
{
    int ret = 0;
    int a = lower_bound(m[1].begin(),m[1].end(),st) - m[1].begin();
    int b = upper_bound(m[1].begin(),m[1].end(),en) - m[1].begin();
    ret = b-a;
    return ret;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector <int> arr;
    fl(i,0,n)
    {
        int temp;
        cin>>temp;
        arr.pb(temp);
    }
    int peaks[n+1];
    MEM(peaks,0);
    fl(i,1,n-1)
    {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
        {
            peaks[i+1] = 1;
        }
    }
    for(int i = 0;i <= n;i++){
        m[peaks[i]].pb(i);
    }
    int cur_p = -1 * INT_MAX;
    int l;
    for(int i = 1; i+k-1 <= n; i++)
    {
        int num_p = num(peaks,i+1,i+k-2);
        //cout << num_p << endl;
        if(num_p > cur_p)
        {
            cur_p = num_p;
            l = i;
        }
    }
    cout << cur_p + 1 << " " << l << "\n";
    m.clear();
}
int main()
{
    FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}

