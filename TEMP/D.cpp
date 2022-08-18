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

int main()
{
    FIO;
    #ifdef IHAVETOPEE 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int T;cin>>T;
    
    while(T--){
        int n,k;cin>>n>>k;
        string str;cin>>str;
        map<int,bool>flip;
        int pre[n+1];
        MEM(pre,0);
        for(int i = 0;i < n-k+1;i++){
            int bit = str[i] - '0';
            if(!i){
                if(bit){
                    pre[0] = 1;
                    flip[i] = true;
                }
            }else{

            }
        }

        for(int i = 0;i < n-k+1;i++)cout<<"0";
        int cnt = 0;
        for(int i = n-k+1,j = 0;i < n;i++,j++){
            int bit = str[i] - '0';
            if(flip[j])cnt++;
            if(cnt%2){
                bit = !bit;
            }
            cout<<(bit)?"0":"1";
        }
        cout<<"\n";
    }
    

    return 0;
}