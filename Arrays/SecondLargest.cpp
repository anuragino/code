#include<bits/stdc++.h>
using namespace std;

/*Brute Force
    1.sort && largest = arr[n-1]
    2.for(int i =n-2;i>=0;i--){
        if(arr[i]!=largest){
            secondlargest = arr[i];
            break;
        }
    }

*/

/*Better Approach
int SLargestElement(int arr[], int n)
{
    int largest = arr[0];
    int secondLargest = -1;
    for(int i =1 ;i<n;i++){
        if(arr[i]>largest)
            largest = arr[i];
    }

    for(int i =0;i<n;i++){
        if(arr[i]>secondLargest && arr[i]!=largest){
            secondlargest = arr[i];
        }
    }
   
}

*/




int print2largest(int arr[], int n) {
    int largest = arr[0];
    int secondLargest = -1;
    
    for(int i =1;i<n;i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i]!= largest && arr[i]>secondLargest){
            secondLargest = arr[i];
        }
    }
    
    return secondLargest;
}
int main(){
    int n =6;
    int arr[n]={2,1,3,7,4,7};
    cout<<print2largest(arr,n)<<endl;
    return 0;
}