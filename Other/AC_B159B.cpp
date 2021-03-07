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

bool if_palindrome(string a,int st,int n)
{
    for(int i = st,j = n;i <= n/2;i++,j--)
    {
        if(a[i] != a[j])return false;
    }
    return true;
}

void solve()
{
   string a;
   cin>>a;
   int n = a.size();
   bool x,b,c;
   x = if_palindrome(a,0,((n-1)/2)-1);
   b = if_palindrome(a,((n+3)/2),n-1);
   c = if_palindrome(a,0,n-1);
  if(x&&b&&c)cout << "Yes\n";
   else cout << "No\n";
}

int main()
{
    //FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}
