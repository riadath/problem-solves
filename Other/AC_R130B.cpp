#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
struct detup{
    ll t,n,c;
};
int main()  
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    
    ll H, W,C, Q;
    cin>>H>>W>>C>>Q;
    vector<detup>query;
    for(int i = 0;i < Q;i++){
        detup temp;
        cin>>temp.t>>temp.n>>temp.c;
        query.push_back(temp);
    }
    reverse(query.begin(),query.end());

    map<pair<ll,ll>,ll>flag;
    ll colCount[C + 1];
    memset(colCount,0,sizeof(colCount));
    ll preC = 0,preH = 0,preCol = -1,preHol = -1;

    for(int i = 0;i < Q;i++){
        if(!flag[make_pair(query[i].n,query[i].t)]){
            if(query[i].t == 1){
                colCount[query[i].c] += (W - preC),preH++;
            }
            else{
                colCount[query[i].c] += (H - preH),preC++;
            } 
            flag[make_pair(query[i].n,query[i].t)] = 1;
        }
    }
    for(int i = 1;i <= C;i++){
        cout<<colCount[i]<<" ";
    }cout<<"\n";

    return 0;
}
