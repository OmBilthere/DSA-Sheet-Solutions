class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,long long>>>adj(n);
        
        const int mod = 1e9+7;

        for(int i=0 ; i< roads.size() ; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];

            adj[u].push_back({v , time});
            adj[v].push_back({u , time});

        } 

        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<>>q;

        vector<long long>dist( n , 1e18);

        vector<int>ways(n , 0);

        ways[0]=1;

        dist[0]=0;

        q.push({0 , 0});

        while(!q.empty()) {
             
            auto [dis , node ] = q.top();

            q.pop();

            if(dist[node] < dis ) continue;

            for(auto it : adj[node]) {

             int next = it.first;

             long long totalTime = it.second + dis;
              
             if( totalTime < dist[next] ) {
            
              q.push({totalTime ,next });
              
              ways[next] = ways[node];

              dist[next] = totalTime;

    
             }

             else if (totalTime == dist[next] ) ways[next] = (ways[node]+ways[next])%mod;
          
            }

        }

      return ways[n-1];
        
    }
};