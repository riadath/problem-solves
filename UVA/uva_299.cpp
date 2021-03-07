#include <bits/stdc++.h>
using namespace std;
int swaped;
void bubble_sort(int arr[],int n)
{
	int i,j,temp;
	int isSorted;
	for(i = 0;i < n;i++){
		isSorted = 1;
		for(j = 0;j < n-1-i;j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
				isSorted = 0;
				swaped++;
			}
		}
		if(isSorted) break;
	}
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++){
            cin>>arr[i];
        }
        swaped = 0;
        bubble_sort(arr,n);
        cout<<"Optimal train swapping takes "<<swaped<<" swaps."<<endl;
    }
    return 0;
}


















































































































