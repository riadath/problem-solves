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
    int d,t_hours;
    cin>>d>>t_hours;
    int mx[d],mn[d];
    int sum_min = 0,sum_max = 0;
    vector <int> diff;
    fl(i,0,d){
        cin>>mn[i]>>mx[i];
        sum_min += mn[i];
        sum_max += mx[i];
        diff.pb(mx[i] - mn[i]);
    }
    if(sum_max < t_hours || sum_min > t_hours){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        int left = t_hours - sum_min;
        for(int i = 0;i < d;i++){
           // cout << i+1 << ": ";
            if(left <= 0){
                cout << mn[i] << " ";
            }
            else if(diff[i] <= left){
                cout << mn[i] + diff[i] << " ";
                left -=  diff[i];
            }
            else if(left < diff[i]){
                cout << mn[i] + left << " ";
                left = 0;
            }
        }
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


