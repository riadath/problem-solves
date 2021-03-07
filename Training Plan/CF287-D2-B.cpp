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

ll quad(ll a)
{

    double x;
    x = (1+sqrt(8*a-7))/2;
    ll p = ceil(x);
    return p;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll mx = k*(k-1)/2 + 1;
    if(n<2)cout <<0<<"\n";
    else if(n > mx)
        cout<<-1<<"\n";
    else if(k>=n)cout<<1<<"\n";
    else if(mx == n)cout << k-1 <<"\n";
    else
    {
        bool flag = true;
        ll sum = 0,cnt = 0;
        ll diff = mx - n;
        if(diff < 2){
            diff = 2;
        }
        ll p = quad(diff);
        cnt = k-p;
        sum = mx - (1 + p*(p-1)/2);
        k = p;
        if(sum == n)
        {
            sum -= k;
            k--;
            cnt--;
        }
        //printf("MX:%I64d,diff:%I64d,P:%I64d,cnt:%I64d,sum:%I64d\n",mx,diff,p,cnt,sum);
        while(k>=2)
        {
            if(n-(sum+1) == 0)
            {
                cout << cnt <<"\n";
                flag = false;
                break;
            }
            if(n-sum <= k)
            {
                cnt++;
                cout<<cnt<<"\n";
                flag = false;
                break;
            }
            sum += k-1;
            k--;
        }
        if(flag)
            cout<<-1<<"\n";
    }
}

int main()
{
    FIO;
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
