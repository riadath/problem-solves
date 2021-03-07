
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
    bool flag = true;
    ll sum_rows[n];
    ll sum_cols[n];
    ll dg1 = 0,dg2 = 0;
    MEM(sum_rows,0);
    MEM(sum_cols,0);
    ll em_r,em_c;
    fl(i,0,n){
        fl(j,0,n){
            ll temp;
            cin>>temp;
            if(temp == 0){
                em_r = i;
                em_c = j;
            }
            sum_rows[i] += temp;
            sum_cols[j] += temp;
            if(i == j)dg1 += temp;
            if(j == n-i-1)dg2 += temp;
        }
    }
    ll ans = sum_rows[(em_r+1)%n] -sum_rows[em_r];
    sum_rows[em_r] += ans;
    sum_cols[em_c] += ans;
    if(em_r == em_c)dg1 += ans;
    if(em_c == n-em_r-1)dg2 += ans;
    sort(sum_rows,sum_rows+n);
    sort(sum_cols,sum_cols+n);

    /*cout << "ans: " << ans <<"\n";
    cout << "dg1: "<<dg1 << " dg2: "<<dg2 << "\n";
    cout << "___________\n";;
    fl(i,0,n) cout << sum_rows[i] << " ";
    cout << "\n";
    fl(i,0,n) cout << sum_cols[i] << " ";
    cout << "\n";*/

    if(dg1 != dg2)flag = false;
    else if(dg1 != sum_cols[0])flag = false;
    else if(sum_rows[0] != sum_rows[n-1])flag = false;
    else if(sum_cols[0] != sum_cols[n-1])flag = false;
    else if(sum_rows[0] != sum_cols[0])flag = false;
    else if(ans <= 0)flag = false;
    else if(ans > 1e18)flag = false;

    if(n == 1)cout << 1 << "\n";
    else if(flag) cout << ans << "\n";
    else cout << -1 << "\n";
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
