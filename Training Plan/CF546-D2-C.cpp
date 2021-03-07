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
    int n;
    cin>>n;
    int s1,s2;
    cin>>s1;
    queue <int> t1;
    fl(i,0,s1){
        int temp;
        cin>>temp;
        t1.push(temp);
    }
    cin>>s2;
    queue <int> t2;
    fl(i,0,s2){
        int temp;
        cin>>temp;
        t2.push(temp);
    }
    int moves = 0;
    int winner = -1;
    fl(i,0,1e4){
        int f1,f2;
        f1 = t1.front();
        t1.pop();
        f2 = t2.front();
        t2.pop();
        if(f1 > f2){
            t1.push(f2);
            t1.push(f1);
        }else if(f2 > f1){
            t2.push(f1);
            t2.push(f2);
        }
        moves++;
        if(t1.empty()){
            winner = 2;
            break;
        }
        else if(t2.empty()){
            winner = 1;
            break;
        }
    }
    if(winner == -1){
        cout << -1 << "\n";
    }else if(winner == 1 || winner == 2){
        cout << moves << " " << winner << "\n";
    }

}

int main()
{
    FIO;

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    solve();
    return 0;
}

