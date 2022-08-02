#include <bits/stdc++.h>
using namespace std;

#ifdef IHAVETOPEE
#include "debug.h"
#else
#define debug(args)
#endif

#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define MEM(x, y) memset(x, y, sizeof(x))
#define PI acos(0)*2
#define fi first
#define se second
#define all(a) a.begin(), a.end()


map<string,vector<pii>>ase;
bool comp(string &a,string &b){
    int len1 = (int)a.size(),len2 = (int)b.size();
    if(len1 == len2)return ase[a].size() > ase[b].size();
    return len1 > len2;
}

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T;cin>>T;
    while(T--){
        ase.clear();
        string t;cin>>t;
        int n;cin>>n;
        vector<pair<string,int>>s;
        int len = t.size();
        for(int i = 1;i <= len;i++){
            for(int j = 0;j <= len - i;j++){
                string make = "";
                for(int k = j;k < j + i;k++)make += t[k];
                // debug(make);
                ase[make].push_back({j,j + i - 1});
            }
        }

        for (int i = 0; i < n; i++){
            string temp;cin>>temp;
            if(ase[temp].size() > 0)
                s.push_back({temp,i+1});
        }
        for(pair<string,int> t : s){
            debug(t.fi);
            debug(ase[t.fi]);
        }


        bool done[t.size() + 1];
        MEM(done,false);
        int left = t.size();
        debug(left);
        vector<pii>answer;
        while(left > 0){
            
        }
        if(left > 0){
            cout<< -1<<"\n";
            continue;
        }

        cout<<answer.size()<<"\n";
        for(pii idx : answer)cout<<idx.fi<<" "<<idx.se<<"\n";
    }    

    return 0;
}
