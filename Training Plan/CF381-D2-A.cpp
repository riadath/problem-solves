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
//CF381-D2-A
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    fl(i,0,n)cin>>arr[i];
    int s = 0,d = 0;
    int left = n;
    for(int i = 0,j = n-1;;){
        if(left == 0)break;
        if(arr[i] > arr[j]){
            s += arr[i];
            i++;
        }else{
            s += arr[j];
            j--;
        }
        left--;
        if(left == 0)break;
        if(arr[i] > arr[j]){
            d += arr[i];
            i++;
        }else{
            d += arr[j];
            j--;
        }
        left--;
        if(left == 0)break;
    }
    cout << s << " " << d << "\n";
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

