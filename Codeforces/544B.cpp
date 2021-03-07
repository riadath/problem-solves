#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define ull unsigned long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double,double>
#define pll pair<long, long>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>
#define all(a) a.begin(),a.end()

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}

int main()
{
    FIO;
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    if(((n*n)/2 + (n*n)%2) < k){
        cout<<"NO"<<nl;
    }
    else{
        bool mat[n+10][n+10];
        MEM(mat,false);
        int cn = 0;
        fl(i,0,n){
            fl(j,0,n){
                if(i%2){
                    if(j%2 && cn < k){
                        mat[i][j] = true;
                        cn++;
                        if(cn == k)break;
                    }
                }
                else{
                    if(j%2 == 0 && cn < k){
                        mat[i][j] = true;
                        cn++;
                        if(cn == k)break;
                    }
                }
                if(cn == k)break;
            }
            if(cn == k)break;
        }
        cout<<"YES"<<nl;
        fl(i,0,n){
            fl(j,0,n){
                if(mat[i][j])cout<<'L';
                else cout<<'S';
            }
            cout<<nl;
        }
    }
    return 0;
}















