#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(ll i = a;i < b;i++)
#define lf(i,a,b) for(ll i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(),x.end())

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    vector <int>pp_neg,pp_pos;
    fl(i,0,n){
        cin>>arr[i];
        if(abs(arr[i])%2 == 1){
            if(arr[i] < 0)pp_neg.pb(i);
            else pp_pos.pb(i);
        }
    }

    fl(i,0,n)
    {
       int temp = floor(arr[i]/2);
       arr[i] = temp;
    }
    int sum = 0;
    fl(i,0,n)sum += arr[i];
    if(sum < 0){
        while(sum != 0){
            fl(j,0,pp_pos.size()){
                int i = pp_pos[j];
                arr[i] += 1;
                sum++;
                if(sum == 0)break;
            }
        }
    }
    else if(sum > 0){
        fl(j,0,pp_neg.size()){
            int i = pp_neg[j];
            arr[i] -= 1;
            sum--;
            if(sum == 0)break;
        }
    }
    fl(i,0,n)cout<<arr[i]<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

