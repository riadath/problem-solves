#include <bits/stdc++.h>
using namespace std;

long long oll = 0;
#define ll long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (int i = a; i < b; i++)
#define lf(i, a, b) for (int i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair

int cd(char arr[], int n)
{
    unordered_set<char> s;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        //cout<<*s.end()<<endl;
        if (s.find(arr[i]) == s.end())
        {
            s.insert(arr[i]);
            res++;
        }
    }

    return res;
}

void solve()
{
    char arr[101];
    cin>>arr;
    if(cd(arr,strlen(arr))%2){
        cout << "IGNORE HIM!\n";
    }
    else {
        cout << "CHAT WITH HER!\n";
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

