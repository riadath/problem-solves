/** unsolved
**/

#include <bits/stdc++.h>
using namespace std;
vector <long long>times;
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define pii pair<int,int>
#define lcm(a,b) a*b/__gcd(a,b)
#define fl(i,a,b) for(int i = a;i < b;i++)
#define lf(i,a,b) for(int i = b;i >= a;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
long long int oll = 0;

void solve()
{
    int T;
    cin>>T;
    int k = 1;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        fl(i,0,n)cin>>arr[i];
        int diff1 = 0,diff2 = 0,diff_t = 0;
        fl(i,0,n-1)
        {
            int j = i+1;
            if(arr[j] < arr[i]){
                diff_t = 0;
               for(;;i++,j = i+1){
                    if(arr[j] >= arr[i])break;
                    diff_t += arr[i] - arr[j];

                }

            }
            if(diff_t > diff1)diff1 = diff_t;
        }
        fl(i,1,n){
            diff2  = max(0,arr[i-1] - arr[i]);
        }
        //cout<<diff1<<"  "<<diff2<<endl;
        int diff = max(diff1,diff2);
       // cout<<diff<<endl;
        if(diff == 0){
            //cout<<"case: "<<k++<<" ->";
            cout<<diff<<"\n";
        }

        else
        {
            int sec = 0;
            //fl(i,0,times.size())cout<<times[i]<<" ";
            //cout<<"\n";
            for(int i = 0; i < times.size(); i++){
                if(times[i] >= diff){
                    sec = i+1;
                    break;


                }
            }
            //cout<<"case: "<<k++<<" ->";
            cout<<sec<<"\n";
        }
    }
}
    int main()
    {
        FIO;

        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
        times.pb(1);
        for(int i = 1,j = 1; i <= 33; i++,j++){
            times.pb(pow(2,i) + times[i-1]);
        }
        solve();
        return 0;
    }


