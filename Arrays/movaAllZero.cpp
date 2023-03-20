#include<bits/stdc++.h>
using namespace std;

//brute force T.C ->O(2n)   S.C->O(x) (in wrost case O(n)  )
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    vector<int> v; //temporary list
    
	    for(int i =0;i<n;i++){    //Pushing non-zero elements in temporary list
	        if(arr[i]==0)   continue;
	        v.push_back(arr[i]);
	    }
    
	    for(int i =0;i<n;i++){
	       if(i<v.size()){  //pushing non-zero element in the array
	            arr[i] = v[i];
	       }else{
	           arr[i]=0;  //pushing zero to last of the array
	       } 
	    }
	}
};


//Optimal Soultion T.C->O(N)   S.C->O(1)
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int j = -1;
	    for(int i =0;i<n;i++){
	        if(arr[i]==0){
	            j=i;
	            break;
	        }
	    }
	    
	    if(j==-1)   return;
	    
	    
	    for(int i = j+1;i<n;i++){
	        if(arr[i]!=0){
	            swap(arr[i],arr[j]);
	            j++;
	        }
	    }
	}
};

int main(){
  int t;  cin>>t;
  while(t--){
    int i,n;
    cin>>n;
    int arr[n];
    for(i =0;i<n;i++)
        cin>>arr[i];
    Solution ob;
    ob.pushZerosToEnd(arr,n);
    for(i=0;i<n;i++)
      cout<<arr[i];
    cout<<endl;
  }
  return 0;
}
