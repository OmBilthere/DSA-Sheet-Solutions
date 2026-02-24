class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            
        vector<vector<pair<int,int>>>adj(n);

        for( int i=0; i<edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            int dis = edges[i][2];

            adj[u].push_back({v , dis});
            adj[v].push_back({u , dis});

        }
       
         int mini = 1e9;  
         
         int ansNode;
     
        for(int i=0 ; i< n ; i++ ) {
             
         vector<int>dist(n , 1e9);

         dist[i] = 0 ;

         priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>>pq;

         pq.push({0 ,i});

         while(!pq.empty()) {

            auto [dis , node ] = pq.top();

            pq.pop();

            if(dis > dist[node]) continue;

            for(auto it: adj[node])  {

                int next = it.first;

                int nextdis = it.second;

                int totaldis = dis+nextdis;
                
                if(totaldis < dist[next]) {

                    dist[next]= totaldis;

                    pq.push({totaldis , next});
                }

            }

          }

       int cnt = 0;

       for(int j=0 ; j< n ; j++ ) {
          
        if(j!=i && dist[j] <= distanceThreshold ) 

        cnt++;     

       }

     
     if( cnt <= mini) {

        mini = cnt;
        ansNode = i;

 
       }

     }


     return ansNode;

    }

};