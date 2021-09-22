#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int T;cin>>T;
    while(T--)
    {
        int a,b,tot;
        cin>>a>>b;
        int mx = max(a,b);
        int mn = min(a,b);
        int dif = (mx - mn);
        dif = dif/2;
        tot = a + b;
        if(tot%2){
            int ones = tot/2 + (tot%2);
            int br = mx - ones;
            set<int>ans;
            while(br <= tot - dif){
                ans.insert(br);
                br += 1;
            }
            cout<<ans.size()<<"\n";
            for(auto i : ans){
                cout<<i<<" ";
            }cout<<"\n";
        }
        else{
            int ones = tot/2;
            int br = mx - ones;
            vector<int>ans;
            while(br <= tot-dif){
                ans.push_back(br);
                br += 2;
            }
            cout<<ans.size()<<"\n";
            for(int i = 0;i < ans.size();i++){
                cout<<ans[i]<<" ";
            }cout<<"\n";
        }

    }
    return 0;
}
