#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
     queue <int> cards;
     for(int i = 1;i <= n;i++){
        cards.push(i);
     }
     int counter = n,ans;
     while(true){
        cards.pop();
        counter--;
         if(counter == 1){
            ans = cards.front();
            break;
        }
        cards.push(cards.front());
        cards.pop();
     }
     cout<<ans<<endl;
    }
    return 0;
}







