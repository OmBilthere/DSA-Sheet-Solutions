class Solution {

public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int , int>>>adj(n+1);

        for(int i = 0 ; i < times.size() ; i++ ) {

            int u = times[i][0];

            int v = times[i][1];

            int time = times[i][2];

            adj[u].push_back({v ,time});

        }

        vector<int>dist(n+1 , 1e9);

        dist[k] = 0;

        priority_queue<pair<int , int> , vector<pair<int ,int>> , greater<>>pq;

        pq.push({k , 0});

        while(!pq.empty()) {     

            auto [node , time] = pq.top();

            pq.pop();

            for(auto it : adj[node]) {

                int next = it.first;

                int totalTime = it.second + time;

                if( totalTime < dist[next]) {

                pq.push({next , totalTime});

                dist[next] = totalTime;

                }

            }


        }

       int maxi = -1e9; 

       for(int i=1 ; i<=n ; i++ ) {

        if(dist[i] == 1e9)

        return -1;

        else maxi = max(maxi , dist[i]); 

       }

        return maxi;


    }
};