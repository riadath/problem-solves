#include <bits/stdc++.h>
using namespace std;

string dec_to_bin(int N)
{
    string binary;

    while(N != 0)
    {
        int temp = N%2;
        binary.push_back(temp + '0');
        N /= 2;
    }
    binary.push_back('0');
    reverse(binary.begin(),binary.end());
    return binary;
}

int bin_to_dec(string a){
    int p = 0;
    int res = 0;
    for(int i = a.length()-1;i>=0;i--){
        res += (a[i]-'0')*(pow(2,p));
        p++;
    }
    return res;
}

bool is_shifted(string temp,int len)
{
    for(int i = temp.length()-1; i>=len+2; i--)
    {
        if(temp[i] == '0' && temp[i-1] == '1')
        {
            return true;
        }
    }
    return false;
}

int main()
{

    /*string a = "11010";
    bool what = is_shifted(a,2);
    cout<<what<<endl;*/
    int T;
    cin>>T;
    for(int k = 1; k <= T; k++)
    {
        int n;
        cin>>n;
        string bin = dec_to_bin(n);
        bool detector = false;
        for(int i = bin.length()-1; i >= 1; i--)
        {
            if(bin[i] == '1' && bin[i-1] == '0')
            {
                bin[i] = '0';
                bin[i-1] = '1';
                detector = !detector;
            }
            if(detector){
                int cou = 20;
                while(is_shifted(bin,i)){
                    for(int j = bin.length()-1;j >= i+2;j--){
                        if(bin[j] == '0' && bin[j-1] == '1'){
                            bin[j] = '1';
                            bin[j-1] = '0';
                        }
                    }
                }
            }
            if(detector){
                break;
            }
        }
        int res = bin_to_dec(bin);
        printf("Case %d: %d\n",k,res);
    }
    return 0;
}
