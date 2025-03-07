//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int node, parent;
     int V;
    bool DetectCycle(int node, int parent, vector<vector<int>>&adj, vector<bool>&visited)
    {
        visited[node] =1;
        for(int j=0; j<adj[node].size(); j++)
        {
            if(parent == adj[node][j])
            continue;
            
            if(visited[adj[node] [j]] ==1)
            return 1;
            
            if (DetectCycle(adj[node][j], node, adj, visited) )
            return 1;
        }
        return 0;
    };
    
    bool isCycle(vector<vector<int>>& adj) {
      int V= adj.size();
     
      vector<bool>visited(V,0);
      
      for(int i=0; i<V; i++)
      {
          if(! visited[i] && DetectCycle(i, -1, adj, visited))
          {
          return true;
          }
      }
      return 0;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends