#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--){
		long long int a, b, is_pos;
		cin>>a>>b;
		if(a<b)is_pos = 0;
		else if((a%2)==0 && (b%2)!=0)is_pos = 0;
		else if((a%2)!=0 && (b%2)==0)is_pos = 0;
		else is_pos = 1;
		if(is_pos){
			cout<<(a+b)/2<<" "<<((a-b)/2)<<"\n";
		}else{
			cout<<"impossible"<<"\n";
		}
	}
	return 0;
}
