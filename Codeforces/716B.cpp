#include <bits/stdc++.h>
using namespace std;
long long oll = 0;
#define ll long long
#define ull unsigned long long
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define pii pair<int, int>
#define pdd pair<double,double>
#define pll pair<long, long>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define pi 3.141592653589793238
#define db double
#define fi first
#define se second
#define pi4 pair<pii,pii>
#define all(a) a.begin(),a.end()

bool comp(const pll &a,const pll &b)
{
    return a.second >= b.second;
}

int main()
{
    FIO;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a;
    cin>>a;
    if(a.size() < 26){
        cout<<-1<<nl;
        return 0;
    }
    int st = -1;
    fl(i,0,a.size()-26+1){
        int let = 0;
        int q = 0;
        map <char,bool>flag;
        fl(k,0,26){
            if(a[i+k] == '?')q++;
            else{
                if(!flag[a[i+k]]){
                    flag[a[i+k]] = true;
                    let++;
                }
            }
        }
        if(let + q == 26){
            st = i;
            break;
        }
    }
    if(st == -1){
        cout<<-1<<nl;
    }
    else{
        string temp;
        fl(i,st,st+26){
            temp += a[i];
        }
        bool leter[30];
        MEM(leter,false);
        fl(i,0,temp.size()){
            if(temp[i] != '?'){
                int k = temp[i] - 'A';
                leter[k] = true;
            }
        }
        string mis = "";
        fl(i,0,26){
            if(leter[i] == false){
                char c = i + 'A';
                mis += c;
            }
        }
        int b = 0;
        fl(i,0,temp.size()){
            if(temp[i] == '?'){
                temp[i] = mis[b];
                b++;
            }
        }
        fl(i,0,a.size()){
            if(i == st){
                cout<<temp;
                i += temp.size()-1;
            }
            else {
                if(a[i] == '?')cout<<'X';
                else cout<<a[i];
            }
        }
    }
    return 0;
}















