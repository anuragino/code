//problem link :- https://practice.geeksforgeeks.org/problems/even-swap/1 

// read question first;

#include <bits/stdc++.h>
using namespace std;

bool comp(int a , int b){
    return (a>b);
}

class Solution
{
    public:
    
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            vector<int> ans = a;
            int i =0;
            while(i<n){
                int j=i+1;
                while(j<n && ans[j]%2 == ans[j-1]%2){  //Sum is even if odd + odd or even+even
                    j++;
                }
                
                //descending order 
                sort(ans.begin()+i,ans.begin()+j,comp);
                i = j;
            }
            
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
