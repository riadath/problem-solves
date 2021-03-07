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
#define srta(x,n) sort(x,x+n)
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>

bool comp(const pii &a,const pii &b)
{
    return a.second < b.second;
}
double dt(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

int is_balanced(string input,int st,int len)
{
    char stack[100];
    int top,i;

    top = 0;

    for(i = st; i < len; i++)
    {
        if(input[i] == '(')
        {
            stack[top] = '(';
            top++;
        }
        else if(input[i] = ')')
        {
            if(top == 0)
            {
                return 0;
            }
            top--;
            if(stack[top] != '(')
            {
                return 0;
            }
        }
    }
    if(top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cn = 0;
        int nc = 0;
        fl(i,0,n){
            if(cn == 0 && s[i] == ')'){
                nc++;
            }
            else if(s[i] == '('){
                while(s[i] == '('){
                    cn++;
                    i++;
                }
                while(s[i] == ')'){
                    cn--;
                    i++;
                    if(cn == 0)break;
                }
                i--;
                //cout<<cn<<nl;
            }
        }
        cout<<nc<<nl;
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



