//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/*  BRute force     T.C->O(nlogn)   S.C->O(n)
    sort(arr,arr+n);
    */  


//BETTER Solution     T.C->O(2n)    S.C->O(1)
class Better
{
    public:
    void sort012(int a[], int n)
    {
        int cnt =0,cnt1=0  , cnt2==0;
        for(int i=0;i<n;i++){
            if(a[i]==0) cnt++;
            else if(a[i]==1) cnt1++;
            else cnt2++;
        }
        
        for(int i =0;i<cnt;i++) a[i]=0;
        for(int i =cnt;i<cnt1;i++) a[i]=1;
        for(int i =cnt+cnt1;i<n;i++) a[i]=2;
    }
    
};


// Optimal Solution  DNF -> Dutch National Flag Algorithm    T.C.->O(N)    S.C->O(1)
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int start =0;
        int mid = 0;
        int end = n-1;
        
        while(mid<=end){
            if(a[mid]==0){
                swap(a[mid],a[start]);
                mid++;
                start++;
            }
            else if(a[mid]==1){
                mid++;
            }
            else{
                swap(a[mid],a[end]);
                end--;
                
            }
                
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends
