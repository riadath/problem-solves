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
        int arr[100];
        string str;
        getline(cin,str);
        while(str.length()==0)getline(cin,str);
        cout<<str<<nl;
        cout<<"------------\n";
        stringstream s;
        s<<str;
        string temp;
        int found;
        int n = 0;
        while(!s.eof()){
            s>>temp;
            if(stringstream(temp)>>found){
                arr[n] = found;
                n++;
            }
            temp = "";
        }
        fl(i,0,n)cout<<arr[i]<<sp;
        cout<<nl;
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

