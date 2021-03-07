
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n && n)
    {
        int i = 0,v = 0,x = 0,l = 0,c = 0,q;
        for(int k = n; k >= 1; k--)
        {
            int temp = k;
            if(temp >= 100)
            {
                ;
                for(q = 1; q*100 < temp; q++)
                {
                }
                if(q*100 > temp)
                    q--;
                temp = temp - q*100;
              //  cout<<q<<"----"<<temp<<endl;
                c += q;

            }
            if(temp>= 90 && temp < 100)
            {
                c++;
                x++;
                temp -= 90;
            }
            if(temp >= 50)
            {
                for(q = 1; q*50 < temp; q++)
                {
                }
                if(q*50 > temp)
                    q--;
                temp = temp - q*50;
              //  cout<<q<<"----"<<temp<<endl;
                l += q;
            }
            if(temp>= 40 && temp < 50)
            {
                l++;
                x++;
                temp -= 40;
            }


            if(temp >= 10)
            {
                for(q = 1; q*10 < temp; q++)
                {
                }
                if(q*10 > temp)
                    q--;
                temp = temp - q*10;
                //cout<<q<<"----"<<temp<<endl;
                x += q;
            }
            if(temp<= 3)
            {
                for(int m = 1; m <= 3; m++)
                {
                    if(temp == m)
                    {
                        i += m;
                        break;
                    }
                }
            }
            else if(temp == 4 || temp == 6)
            {
                i++;
                v++;
            }
            else if(temp == 5)
            {
                v++;
            }
            else if(temp == 7)
            {
                v++;
                i += 2;
            }
            else if(temp == 8)
            {
                v++;
                i += 3;
            }
            else if(temp == 9)
            {
                x++;
                i++;
            }
            //printf("%d: %d i, %d v, %d x, %d l, %d c\n",k,i,v,x,l,c);
        }
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,i,v,x,l,c);
    }
    return 0;
}
