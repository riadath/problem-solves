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
    int n;
    cin>>n;
    string arr;
    cin>>arr;
    int st;
    fl(i,0,n){
        if(arr[i] != '.'){
            st = i;
            break;
        }
    }
    int s,e;
    if(arr[st] == 'L'){
        e = st;
        while(arr[st] == 'L'){
            st++;
        }
        s = st;
    }
    else if(arr[st] == 'R'){
        s = st + 1;
        while(arr[st] == 'R'){
            st++;
        }
        if(arr[st] = '.')st++;
        e = st;
    }
    cout<<s<<" "<<e<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}

