class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
    if(n==0) return 0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            
        }
        const long long INF=LLONG_MAX;
        vector<vector<long long>> dist(n,vector<long long>(k+1,INF));
        priority_queue<tuple<long long,int,int>,vector<tuple<long           long,int,int>>,greater<>>pq;
     dist[0][1]=0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto[d,u,run]=pq.top();
            pq.pop();
            if(d>dist[u][run]) continue;
            for(auto&[v,w]:adj[u]){
                int newRun=(labels[v]==labels[u]) ? run+1:1;
                if(newRun>k) continue;
                long long nd=d+w;
                if(nd<dist[v][newRun]){
                    dist[v][newRun]=nd;
                    pq.push({nd,v,newRun});
                }
            }
        }
        long long best=INF;
        for(int r=1;r<=k;r++){
            best=min(best,dist[n-1][r]);
            
        }
        return best==INF?-1:(int)best;
    }
};