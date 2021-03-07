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

int dis_char (string a)
{
    int cnt = 0;
    unordered_set <char> m;
    for(int i = 0;i < a.size();i++){
        if(m.find(a[i]) == m.end()){
            m.insert(a[i]);
            cnt++;
        }
    }
    return cnt;
}

void solve()
{
    string a;
    getline(cin,a);
    string temp;
    for(int i = 0;i < a.size();i++){
        if(a[i] >= 97 && a[i] < 123){
            temp.pb(a[i]);
        }
    }
    //cout << temp << endl;
    cout << dis_char(temp) << "\n";
}

int main()
{
    //FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}


