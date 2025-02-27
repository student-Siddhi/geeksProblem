//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int V=adj.size();
        queue<int>q;
        vector<bool>visited (V,false);
        q.push(0);
        visited [0]=true;
        int node;
        vector<int> anss;
        
        while(!q.empty())
        {
            node= q.front();
            q.pop();
            anss.push_back(node);
            
            for(int j=0; j< adj[node].size(); j++)
            {
                if (!visited[adj[node][j]])
                {
                    visited [adj[node][j] ]  = 1;
                    q.push(adj[node][j]);
                }
            }
        }
        return anss;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends