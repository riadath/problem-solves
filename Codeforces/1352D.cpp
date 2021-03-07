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
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        fl(i,0,n)cin>>arr[i];
        int start = 0,en = 0,moves = 0;
        int rem = n;
        bool flag = true;
        int bob = 0,alice = 0;
        int i,j;
        bool fff[n];
        MEM(fff,true);
        for(i = 0,j = n-1;;){
            if(flag){
                moves++;
                flag = !flag;
                alice = 0;
                while(true){
                    if(alice > bob)break;
                    if(i > j)break;
                    fff[i] = false;
                    alice += arr[i];
                    start += arr[i];
                    i++;
                }
                //cout<<"Left: "<<alice<<nl;
            }
            else{
                moves++;
                flag = !flag;
                bob = 0;
                while(true){
                    if(bob > alice)break;
                    if(j < i)break;
                    fff[j] = false;
                    bob += arr[j];
                    en += arr[j];
                    j--;
                }
               // cout<<"Right "<<bob<<nl;
            }
            if(i > j || j < i)break;
        }
        /*if(flag){
            fl(i,0,n)if(fff[i]){
                moves++;
                start += arr[i];
                break;
            }
        }else{
            fl(i,0,n)if(fff[i]){
                moves++;
                en += arr[i];
                break;
            }
        }*/
        cout<<moves<<" "<<start<<" "<<en<<nl;
    }
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

