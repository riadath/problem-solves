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
void solve()
{
    int N;
    int kase = 1;
    while(cin>>N && N>=0)
    {
        vector <double> sig;
        vector <int> dur[N];
        vector <int> spd;
        fl(i,0,N)
        {
            double temp;
            cin>>temp;
            sig.pb(temp);
            int g,y,r;
            cin>>g>>y>>r;
            dur[i].pb(g),dur[i].pb(y),dur[i].pb(r);
        }
        fl(i,30,61)
        {
            bool flag = true;
            fl(j,0,sig.size())
            {
                int mod = dur[j][0]+dur[j][1]+dur[j][2];
                double x = sig[j]*3600.00/i;
                bool what;
                if(floor(x) == ceil(x))
                    what = true;
                else
                    what = false;
                int d = (int)x;
                d = d%mod;
                //cout<<"spd:"<<i<<" "<<d<<endl;
                if(!what)
                {
                    if(d >= dur[j][0]+dur[j][1])
                    {
                        flag = false;
                        break;
                    }
                }
                else if(what)
                {
                    if(d > dur[j][0]+dur[j][1])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                spd.pb(i);
            }
        }
        if(spd.size() == 0)
        {
            cout<<"Case "<<kase++<<": No acceptable speeds.\n";
        }
        else
        {
            int pr = 0;
            cout<<"Case "<<kase++<<": ";
            for(int i = 0; i < spd.size()-1; i++)
            {
                cout<<spd[i];
                pr++;
                if(spd[i+1] == spd[i]+1)
                {
                    while(spd[i+1] == spd[i]+1)
                    {
                        pr++;
                        i++;
                    }
                    cout<<"-"<<spd[i];
                    pr++;
                    if(i != spd.size()-1)
                        cout<<", ";
                }
                else
                    cout<<", ";
            }
            if(pr < spd.size())
                cout<<spd[spd.size()-1];
            //fl(i,0,spd.size())cout<<spd[i]<<" ";
            cout<<"\n";
        }
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

