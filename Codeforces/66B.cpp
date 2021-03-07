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
#define srt(x) sort(x.begin(),x.end())
//66B

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    fl(i,0,n)cin>>arr[i];
    vector <int> c_ar;
    fl(i,0,n){
        int cm = arr[i];
        int cnt = 0;
        lf(j,0,i-1){
            if(arr[j] <= cm){
                cnt++;
                cm = arr[j];
            }else break;
        }
        cm = arr[i];
        fl(j,i+1,n){
            if(arr[j]<=cm){
                cnt++;
                cm = arr[j];
            }else break;
        }
        cnt++;
       // cout<<"cnt: "<<cnt<<nl;
        c_ar.pb(cnt);
    }
    cout<<*max_element(c_ar.begin(),c_ar.end())<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

