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
    int M,x,y,p = 0;
    cin>>M;
    vector<pii>cor;
    vector<int> tobp;
    map<int,pii>zm;
    while(cin>>x>>y && (x||y))
    {
        if(x<0&&y<0 || x>M&&y>M)continue;
        else{
            cor.pb(mp(x,y));
        }
    }
    bool flag = true;
    if(cor.size()==0)flag = false;
    if(flag){
        int tbcov = M,base = 0;
        while(true){
            if(tbcov <= 0)break;
            int sz = 0;
            for(int i = 0;i < cor.size();i++){
                if(cor[i].first <= base && cor[i].second > base){
                    zm[i].first = cor[i].first;
                    zm[i].second = cor[i].second;
                    sz++;
                }
            }
            if(sz == 0){
                flag = false;
                break;
            }
            int indx = 0,mxx = -1*INT_MAX,ff;
            for(auto i=zm.begin();i!=zm.end();i++){
                if(i->second.second > mxx){
                    ff = i->second.first;
                    indx = i->first;
                    mxx = i->second.second;
                }
                else if(i->second.second == mxx){
                    if(i->second.first < ff){
                        ff = i->second.first;
                        indx = i->first;
                        mxx = i->second.second;
                    }
                }
            }
            tbcov -= (mxx-base);
            base = mxx;
            tobp.pb(indx);
            zm.clear();
        }
    }
    if(flag){
        cout<<tobp.size()<<nl;
        fl(i,0,tobp.size()){
            cout<<cor[tobp[i]].first<<" "<<cor[tobp[i]].second<<nl;
        }
    }
    else{
        cout<<0<<"\n";
    }
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
        cout<<nl;
    }
    return 0;
}
