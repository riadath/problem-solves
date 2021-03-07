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
#define bs(x,y) binary_search(x.begin(),x.end(),y)
#define nl "\n"
#define sp " ";
#define srt(x) sort(x.begin(),x.end())
map<char,int> lt;
map<char,int> gt;
void solve()
{
    string a,b,c;
    cin>>a>>b>>c;
    if(a[1]=='>')
    {
        a[1] = '<';
        swap(a[0],a[2]);
    }
    if(b[1] == '>')
    {
        b[1] = '<';
        swap(b[0],b[2]);
    }
    if(c[1]=='>')
    {
        c[1] = '<';
        swap(c[0],c[2]);
    }
    lt['A'] = 0,lt['B'] = 0,lt['C'] = 0;
    gt['A'] = 0,gt['B'] = 0,gt['C'] = 0;
    lt[a[0]]++,lt[b[0]]++,lt[c[0]]++;
    gt[a[2]]++,gt[b[2]]++,gt[c[2]]++;
    char one,two,three;
    bool s1 = false,s2 = false,s3 = false;
    string to = "ABC";
    fl(i,0,to.size())
    {
        if(lt[to[i]] == 2 && gt[to[i]] == 0)
        {
            one = to[i];
            s1 = true;
        }
        else if(lt[to[i]] == 1 && gt[to[i]] == 1)
        {
            two = to[i];
            s2 = true;
        }
        else if(lt[to[i]] == 0 && gt[to[i]] == 2)
        {
            three = to[i];
            s3 = true;
        }
    }
    if(s1&&s2&&s3)cout<<one<<two<<three<<nl;
    else cout<<"Impossible"<<nl;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    solve();
    return 0;
}









