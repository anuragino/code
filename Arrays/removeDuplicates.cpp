#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        int i = 0;
        for(int j =1;j<n;j++){
            if(a[i]!=a[j]){
                i++;
                a[i]=a[j];
            }
        }
        
        return i+1;
    }
};


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++) cin>>a[i];
    Solution obj;
    int N = obj.remove_duplicate(a,n);
    for(int i=0;i<N;i++)  cout<<a[i]<<" ";
    cout<<"\n";
  }
  
  return 0;
}
