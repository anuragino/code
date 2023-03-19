#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    struct node{
        int num;
        int freq;
        node(int a,int b){
            num = a;
            freq = b;
        }
    };
    
    //creating a comparator
    struct compare{
        int operator() (const node& a, const node& b)
        {
            if(a.freq == b.freq){
                return a.num < b.num;
            }
            return a.freq < b.freq;
        }
    };
    
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        vector<int> ans;
        unordered_map<int,int> mpp;  //unordered map stores unique element 
        
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        
        priority_queue<node,vector<node>,compare> m; //maxHeap
        
        for(auto it: mpp){
            m.push(node(it.first,it.second));
        }
        
        while(k--){
            node temp = m.top();
            m.pop();
            ans.push_back(temp.num);
        }
        return ans;
    }
};

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &i: nums)
      cin>>i;
    int k;
    cin>>k;
    Solution obj;
    vector<int> ans = obj.topK(nums,k);
    for(auto i: nums)
      cout<<i<<" ";
    cout<<endl;
  }
  
  return 0;
}
