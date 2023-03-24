//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// Kadane's Algorithm    T.C->O(N)  S.C->O(1)
class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxi = LONG_MIN;
        int sum =0;
        for(int i =0;i<n;i++){
            sum +=arr[i];
            if(sum > maxi){
                maxi = sum;
            }
            if(sum<0){
                sum =0;
            }
        }
        
        return maxi;
        
    }
};


// To print subarray with maximum sum
class Solution{
    public:
    vector<long long> maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long maxi = LONG_MIN;
        long long sum =0;
        long long ansStart = -1;
        long long ansEnd = -1;
        int start = -1;
        vector<long long> v;
        
        for(int i =0;i<n;i++){
            
            if(sum ==0){
                start = i;
            }
            sum +=arr[i];
            if(sum > maxi){
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum<0){
                sum =0;
            }
        }
        
        for(int i = ansStart ;i<=ansEnd;i++){
            v.push_back(arr[i]);
        }
        
        return v;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends
