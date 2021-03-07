#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    while(true)
    {
    	cin>>s;
    	char arr[50];
    	strcpy(arr,s.c_str());
    	if(arr[0] == '#')break;
    	int n = strlen(arr);
		sort(arr,arr+n);
        next_permutation(s.begin(),s.end());
        char arr2[50];
        strcpy(arr2,s.c_str());
        if(strcmp(arr,arr2)){
			cout<<arr2<<endl;
        }else{
			cout<<"No Successor"<<endl;
        }
    }
    return 0;
}















