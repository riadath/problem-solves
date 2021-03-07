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


void solve()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        vector <int> srt;
        fl(i,0,n)cin>>arr[i];
        sort(arr,arr+n);
        bool is = true;
        for(int i = 0,j = n-1;;){
            if(i >= n/2 && j < n/2)break;
            if(is){
                //cout<<arr[j]<<endl;
                srt.pb(arr[j]);
                j--;
                is = !is;
            }else{
                //cout<<arr[i]<<endl;
                srt.pb(arr[i]);
                i++;
                is = !is;
            }
        }
        lf(i,0,srt.size()-1)cout<<srt[i]<<" ";
        cout<<"\n";
    }

}

int main()
{
    //FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    solve();
    return 0;
}

