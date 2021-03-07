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
string add_string (string a,string b)
{
    if(a.size() > b.size())
    {
        string temp = b;
        b = a;
        a = temp;
    }

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string total = "";
    int carry = 0;
    fl(i,0,a.size())
    {
        int temp;
        temp = a[i] -'0' + b[i] - '0' + carry;
        //cout<<temp<<endl;
        total.pb(temp%10 + '0');
        carry = temp/ 10;
    }
    if(a.size() != b.size())
    {
        fl(i,a.size(),b.size())
        {
            int temp = b[i]-'0' + carry;
            total.pb(temp%10 + '0');
            carry = temp/10;
        }
    }
    while(carry != 0)
    {
        total.pb(carry%10 + '0');
        carry /= 10;
    }
    //reverse(total.begin(),total.end());
    return total;
}

string multiply(string a,string b)
{
    if(a.size() < b.size())
    {
        string temp = b;
        b = a;
        a = temp;
    }
    bool flag = false;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string total = "";
    int carry = 0;
    fl(i,0,b.size())
    {
        string res = "";
        fl(j,0,a.size())
        {
            int temp = (a[j]-'0')*(b[i]-'0') + carry;
            res.pb(temp%10 + '0');
            carry = temp/10;
        }
        while(carry != 0)
        {
            res.pb(carry%10 + '0');
            carry = carry/10;
        }
        if(total.size() == 0)
        {
            fl(k,0,res.size())total.pb(res[k]);
        }
        else
        {
            reverse(res.begin(),res.end());
            reverse(total.begin(),total.end());
            for(int p = 0; p < i; p++)
            {

                res.pb('0');
            }
            // cout<<res<<" "<<total<<endl;
            total = add_string(res,total);
            //cout<<total<<endl;
        }

    }
    reverse(total.begin(),total.end());
    return total;
}

void solve()
{

    string a,b,res;

    while(cin>>a>>b)
    {
        res = multiply(a,b);
        if(res[0] == '0')cout<<0;
        else cout<<res;
        cout<<"\n";
        a.clear();
        b.clear();
        res.clear();
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

