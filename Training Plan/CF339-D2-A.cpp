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
    string str;
    cin>>str;
    vector <int> sorted;
    for(int i = 0;i < str.size(); i+= 2){
        sorted.pb(str[i] - '0');
    }
    sort(sorted.begin(),sorted.end());
    fl(i,0,sorted.size()){
        cout << sorted[i];
        if(i != sorted.size()-1)cout << "+";
    }
    cout << "\n";
}

int main()
{
    FIO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    solve();
    return 0;
}

