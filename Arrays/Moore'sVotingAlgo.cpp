//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
//BRUTE FORCE  T.C->O(n^2)
class Brute{
  public:
    int majorityElement(int a[], int size)
    {     
        int cnt =0;
        for(int i =0;i<n;i++){
            int times =0;
            for(int j =0;j<n;j++{
                if(a[j]==a[i])  times++;
            }
            cnt = max(cnt,times);
            if(cnt > size/2)  return a[i];
        }
        
        return -1;
    }
};
                
//BETTER SOLUTION    T.C->O(nlogn)   S.C->O(n)  
class Better{
  public:
    int majorityElement(int a[], int size)
    {     
        imap<int,int> mpp;
        for(int i =0;i<n;i++){
            mpp[a[i]]++;
        }
        for(auto it: mpp){
            if(it.second>size/2)  return it.first;
        }
        
        return -1;
    }
};


//OPTIMAL SOLUTION    T.C.->O(n)
class Solution{
  public:
    int majorityElement(int a[], int size)
    {
        // Moore's voting algoritm
        int cnt = 0;
        int el;
        for(int i =0;i<size;i++){
            if(cnt==0){
                cnt =1;
                el = a[i];
            }
            else if(a[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        
        int cnt1 = 0;
        for(int i =0;i<size;i++){
            if(a[i]==el){
                cnt1++;
            }
        }
        
        if(cnt1>size/2){
            return el;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends
