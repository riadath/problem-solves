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


int bu(int arr[],int len,int h){
    int high = len-1,low = 0;
    while(low <= high){
        int mid = (high + low)/2;
        if(arr[mid] >= h){
            high = mid-1;
        }
        if(arr[mid] < h){
            low = mid+1;
        }
    }
   // cout << low << endl;
    return arr[high];
}
int bd(int arr[],int len,int h){
    int high = len-1,low = 0;
    while(low <= high){
        int mid = (high + low)/2;
        if(arr[mid] <= h){
            low = mid+1;
        }
        if(arr[mid] > h){
            high = mid-1;
        }
    }
    //cout << low << endl;
    return arr[low];
}
void solve()
{
    int n,h,Q;
    cin>>n;
    int chicks[n];
    fl(i,0,n)cin>>chicks[i];
    cin>>Q;
    fl(i,0,Q)
    {
        cin>>h;
        int a,b;
        if(chicks[0] >= h) a = -1;
        else{
            a = bu(chicks,n,h);
        }
        if(chicks[n-1] <= h) b = -1;
        else{
           b = bd(chicks,n,h);
        }
        if(a==-1)printf("X ");
        else printf("%d ",a);
        if(b==-1)printf("X\n");
        else printf("%d\n",b);
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
