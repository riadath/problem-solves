#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    while(cin>>n && n)
    {
        queue <int> cards;
        for(i = 1; i <= n; i++)
        {
            cards.push(i);
        }
        int counter = n,ans = cards.front();
        cout<<"Discarded cards:";
        while(n != 1)
        {

            cout<<" "<<cards.front();
            cards.pop();
            counter--;
            if(counter == 1)
            {
                ans = cards.front();
                break;
            }
            cards.push(cards.front());
            cards.pop();
            if(!cards.empty())cout<<",";
        }
        cout<<endl<<"Remaining card: "<<ans<<endl;
    }
    return 0;
}








