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
#define mp make_pair``
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(),x.end())
int cd(int arr[], int n)
{
    unordered_set<int> s;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i]) == s.end())
        {
            s.insert(arr[i]);
            res++;
        }
    }
    return res;
}
void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        fl(i,0,n)cin>>arr[i];
        int dist = cd(arr,n);
        if(dist > k)
        {
            cout<<-1<<"\n";
        }
        else if(n == k){
            cout<<n<<nl;
            fl(i,0,n)cout<<arr[i]<<sp;
            cout<<nl;
        }
        else
        {
            vector <int> de;
            int nde = 0;
            fl(i,0,n)
            {
                srt(de);
                if(!bs(de,arr[i])){
                    de.pb(arr[i]);
                    nde++;
                }
                if(nde == dist)
                    break;
            }
            fl(i,0,k-dist){
                de.pb(de[i]);
            }
            cout<<n*k<<nl;
            fl(i,0,n){
                fl(j,0,de.size())cout<<de[j]<<sp;
            }
            cout<<nl;
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

