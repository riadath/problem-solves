#include <bits/stdc++.h>
using namespace std;

bool prime[1200];
void sieve()
{
    for(int i = 1; i < 1200; i++)
    {
        prime[i] = true;
    }

    for(int i = 4; i < 1200; i += 2)
    {
        prime[i]= false;
    }
    for(int i = 3; i*i < 1200; i += 2)
    {
        for(int j = i*i; j < 1200; j += 2*i)
        {
            prime[j] = false;
        }
    }

}
int main()
{
    sieve();
    char arr[52];
    int count_arr[52];
    for(int i = 0; i < 26; i++)
    {
        arr[i] = i + 97;
        count_arr[i] = i+1;
    }
    for(int i = 26; i < 52; i++)
    {
        arr[i] = i-26+65;
        count_arr[i] = i+1;
    }
    string word;
    while(cin>>word && word[0] != EOF)
    {
        int sum = 0;
        for(int i = 0; i < word.length(); i++)
        {

                for(int j = 0; j < 52; j++)
                {
                    if(word[i] == arr[j])
                    {
                        sum += count_arr[j];
                    }
                }
        }
        //cout<<sum<<endl;
        if(prime[sum])
        {
            printf("It is a prime word.\n");
        }
        else
        {
            printf("It is not a prime word.\n");
        }
    }
    return 0;
}
