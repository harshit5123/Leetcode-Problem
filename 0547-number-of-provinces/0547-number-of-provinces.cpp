class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int cnt = 0;
        int v = isConnected.size();

        vector<vector<int>> adj(v);

        // Create adjacency list
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {

                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(v, 0);

        // Count connected components
        for(int i = 0; i < v; i++) {

            if(!vis[i]) {
                cnt++;
                dfs(i, vis, adj);
            }
        }

        return cnt;
    }
};