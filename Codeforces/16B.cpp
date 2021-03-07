
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

///16B

bool comp(const pii &a,const pii &b){return a.second > b.second;}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector <pii> mat;
    fl(i,0,m){
        int x,y;
        cin>>x>>y;
        mat.pb(mp(x,y));
    }
    sort(mat.begin(),mat.end(),comp);
    ll cnt = 0;
    fl(i,0,m){
        if(n <= 0)break;
        if(mat[i].first < n){
            cnt += (mat[i].first * mat[i].second);
            n -= mat[i].first;
        }
        else if(mat[i].first >= n){
            cnt += n * mat[i].second;
            n -= mat[i].first;
        }
    }
    cout<<cnt<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

        solve();
    return 0;
}
