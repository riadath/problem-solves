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


/*int cd(int arr[], int n)
{
    unordered_set<int> s;
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
*/
void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        fl(i,0,n)cin>>arr[i];
        if(n == 1)
            cout<<0<<"\n";
        else
        {
            int fl_now,fl_prev;

            int dist = 0;
            sort(arr,arr+n);
            int if_same = 0;
            int now = 0,prev = 0;
            int i,j;
            for(i = 0; i < n; i++)
            {
                dist++;
                if(arr[i] == arr[i+1])
                {
                    fl_now = arr[i];
                    for(j = i+1; j < n; j++)
                    {
                        if(arr[i] == arr[j])
                            now++;
                        else if(arr[i] != arr[j])
                            break;
                    }
                    i = j-1;
                    //cout<<i<<"    "<<j<<endl;
                    now++;
                }
                if(now  >= 1 && prev != 0)
                    if_same++;
                if(now > prev)
                {
                    fl_prev = fl_now;
                    prev = now;
                }
                now = 0;
            }

            //printf("Dist:%d same:%d if_same:%d\n",dist,prev,if_same);
            if(prev == 0)
            {
                cout<<1<<endl;
            }
            else if(dist < prev){
                cout<<dist<<"\n";
            }
            else
            {
                if(if_same == 0 && prev > dist)
                {
                    prev--;
                }
                else{
                    dist--;
                }
                if(prev < dist)
                {
                    cout<<prev<<"\n";
                }
                else
                {

                    cout<<dist<<"\n";
                }
            }
        }
    }
}

int main()
{
   // FIO;

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    solve();
    return 0;
}

