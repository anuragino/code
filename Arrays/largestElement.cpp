//largest element in array
#include<bits/stdc++.h>
using namespace std;
/*brute force
    1.Sort
    2.print arr[n-1]

*/

//optimal solution
int largestElement(int arr[], int n)
    {
        int largest = arr[0];
        for(int i =1 ;i<n;i++){
            if(arr[i]>largest)
                largest = arr[i];
        }
        return largest;
    }

int main(){

    int arr[]={2,4,3,1,5};
    int n =5;
    cout<<largestElement(arr,n)<<endl;
}