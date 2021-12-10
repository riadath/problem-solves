#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif
#define FIO ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

#define ll long long

bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return a.second > b.second;
}


int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int T;
    cin>>T;
    while(T--){
        int n;cin>>n;
        vector<pair<ll,ll>>arr;
        ll brr[n + 1];
        memset(brr,0,sizeof(brr));  
        for(int i = 0;i < n;i++){
            ll temp;
            cin>>temp;
            brr[i+1] = temp;
            arr.push_back(make_pair(i+1,temp));
        }
        sort(arr.begin(),arr.end(),comp);
        debug(arr);
        list<ll>ans;
        ans.push_back(0);
        for(int i = 0;i < arr.size();i++){
            if(i%2){
                ans.push_front(arr[i].first);
            }else{
                ans.push_back(arr[i].first);
            }
        }
        debug(ans);
        int i = -1;
        map<ll,ll>finAns;
        for(auto itr : ans){
            finAns[itr] = i++;
        }
        ll total_walk = 0;
        for(int i = 0;i <= n;i++){
            total_walk += 2 * brr[i] * abs((finAns[0] - finAns[i]));
        }
        cout<<total_walk<<"\n";
        for(int i = 0;i <= n;i++){
            cout<<finAns[i]<<" ";
        }cout<<"\n";
    }
    return 0;
}
