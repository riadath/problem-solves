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
    ll n;
    cin>>n;
    ll num_pos = 0,num_neg = 0,alp = 0,aln = 0;
    ll arr[n];
    fl(i,0,n)
    {
        cin>>arr[i];
        if(arr[i] < 0)
        {
            num_neg++;
        }
        else
        {
            num_pos++;
        }
    }
    if(num_neg == 0 || num_pos == 0)
    {
        cout<< *max_element(arr,arr+n) << "\n";
    }
    else
    {
        ll sum = 0;
        fl(i,0,n)
        {
           // cout << i << endl;
            if(arr[i] > 0)
            {
               // cout << "p" << endl;
                ll mx = arr[i];
                for(int j = i;; j++)
                {
                    //cout << "arr["<<j<<"] : "<< arr[j]<<"  mx:"<<mx <<endl;
                    if(arr[j] < 0 || j == n){
                        i = j-1;
                        break;
                    }
                    mx = max(mx,arr[j]);
                }
                sum += mx;
            }
            else if(arr[i] < 0)
            {
                //cout << "n" <<endl;
                ll mx = arr[i];
                for(int j = i;; j++)
                {
                    //cout << "arr["<<j<<"] : "<< arr[j]<<"  mx:"<<mx <<endl;
                    if(arr[j] > 0 || j == n){
                        i = j-1;
                        break;
                    }
                    mx = max(mx,arr[j]);
                }
                sum += mx;
            }
        }
        cout<< sum << "\n";
    }
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

