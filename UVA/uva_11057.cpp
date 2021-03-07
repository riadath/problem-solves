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
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define lcm(a, b) a *b / __gcd(a, b)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define lf(i, b, a) for (ll i = b; i >= a; i--)
#define MEM(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define bs(x, y) binary_search(x.begin(), x.end(), y)
#define nl "\n"
#define sp " "
#define srt(x) sort(x.begin(), x.end())
#define pi 2 * acos(0)
#define db double
#define fi first
#define se second
#define pi4 pair<pii, pii>
#define all(a) a.begin(), a.end()

bool comp(const pii &a, const pii &b)
{
    return a.second < b.second;
}

int binary(int arr[],int el,int n){
    int low = 0, high = n;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == el)return mid;
        if(arr[mid] > el){
            high = mid-1;
        }
        if(arr[mid] < el){
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    // FIO;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n,m,arr[10009],kase = 1;
    while(scanf("%d",&n) != EOF){
        // if(kase++ > 1)printf("\n");
        for(int i = 0;i < n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        scanf("%d",&m);
        int p1 = 0,p2 = 0,cur_diff = 1e8;
        for(int i = 0;i < n;i++){
            int el = m - arr[i];
            // cout << el << nl;
            int flag = binary(arr,el,n-1);
            if(flag != -1 && flag != i){
                if(abs(arr[i] - el) < cur_diff){
                    p1 = arr[i];
                    p2 = el;
                    cur_diff = abs(p1 - p2);
                }
            }
        }
        if(p1 > p2){
            int temp = p1;
            p1 = p2;
            p2 = temp;
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",p1,p2);
    }
    return 0;
}