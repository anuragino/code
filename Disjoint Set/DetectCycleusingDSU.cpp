link of the question -> https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1   

Given an undirected graph with no self loops with V (from 0 to V-1) nodes and E edges, the task is to check if there is any cycle in the undirected graph.
Note: Solve the problem using disjoint set union (DSU).
Input: 
     1->3->0->2->4->0
Output: 1
Explanation: There is a cycle between 0->2->4->0


#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    int find(int x,int parent[]){
        if(parent[x]==x)
        {
            return x;
        }
        else
        {
            return find(parent[x],parent);
        }
    }
    
    int unionf(int x,int y,int parent[]){
        int x_rep=find(x,parent);
        int y_rep=find(y,parent);
        if(x_rep==y_rep)
        {
            return 0;
        }
        parent[y_rep]=x_rep;
        return 1;
    }
    
    int detectCycle(int V, vector<int>adj[])
    {
        set<pair<int,int>>s;
        
        int parent[V];
        for(int i=0;i<V;i++)
        {
            parent[i]=i;
        }
        
        for(int i=0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                int x=find(i,parent);
                int y=find(j,parent);
                if(s.find({i,j})==s.end())
                {
                    if(x==y)    return 1;
                    else{
                        s.insert({i,j});
                        s.insert({j,i});
                        unionf(x,y,parent);
                    }
                }
                else{
                    continue;
                }
            }
        }
        return 0;
    }
};

int main(){
  int tc;
  cin>>tc;
  while(tc--){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i =0;i<E;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    int ans = obj.detectCylce(V,adj);
    cout<<ans<<endl;
  }

  return 0;
}
