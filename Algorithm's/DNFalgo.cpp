//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



//DNF-> Dutch National Flag Algo    T.C->O(N)  S.C->O(1)
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