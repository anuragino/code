#include <bits/stdc++.h>

using namespace std;

vector<int> minAnd2ndMin(int a[], int n) {
    int smallest = a[0];
    int secondSmallest = INT_MAX;
    if(n ==0 || n ==1 ){
        smallest =-1;
    }
    
    
    for(int i =0;i<n;i++){
        if(a[i]<smallest){
            secondSmallest = smallest;
            smallest = a[i];
        }
        else if(a[i]!=smallest && a[i]<secondSmallest){
            secondSmallest = a[i];
        }
    }
    if(secondSmallest == INT_MAX){
        smallest =-1;
    }
    
    return {smallest,secondSmallest};
    
}
int main()
{
    int n = 4;
    int a[n]={1,1,1,1};
    
    vector<int> ans = minAnd2ndMin(a,n);
    if(ans[0]==-1){
        cout<<-1<<endl;
    }
    else
        cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;
}