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
int days[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool ic(int d1,int m1,int y1,int d2,int m2,int y2)
{
    bool leap;
    if(y1%4==0 && y1%100!=1 || y1%400==0)leap = true;
    else leap = false;

    if(m1 == 2 && leap && m2==3 && d1 == 29 && d2 == 1 && y1 == y2)return true;
    else if(m1 == 2 && !leap && m2 == 3 && d1 == 28 && d2 == 1 && y1 == y2)return true;
    else if(d2 == d1+1 && m1 == m2 && y1 == y2)return true;
    else if(m2 == m1+1 && d1 == days[m1] && d2 == 1 && y1 == y2 && m1 != 2)return true;
    else if(y2 == y1+1 && m1 == 12 && m2 == 1 && d1 == 31 && d2 == 1)return true;
    else return false;

}

void solve()
{
    int n;
    while(cin>>n && n)
    {
        int dates[n],months[n],years[n],values[n];
        fl(i,0,n){
            cin>>dates[i]>>months[i]>>years[i]>>values[i];
        }
        int cnt = 0;
        int sum = 0;
        fl(i,0,n-1){
            if(ic(dates[i],months[i],years[i],dates[i+1],months[i+1],years[i+1])){
                cnt++;
                sum += values[i+1] - values[i];
            }
        }
        cout<< cnt << " " << sum <<"\n";
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

