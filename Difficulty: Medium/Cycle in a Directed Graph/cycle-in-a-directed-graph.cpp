//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int V =adj.size();
        vector<int>InDeg(V,0);
        
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<adj[i].size(); j++)
            InDeg[adj[i][j]]++;
        }
        
        queue<int>q;
        for(int i=0; i<V; i++)
        if(! InDeg[i])
        q.push(i);
        
        int count =0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            
            for(int j=0; j<adj[node].size(); j++)
            {
                InDeg[adj[node] [j]] --;
                if(! InDeg[adj[node] [j]] )
                q.push (adj[node] [j]);
            }
        }
        return count!=V;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends