class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>adj(n);

        for(auto &it : flights) {

            int u = it[0];
            int v = it[1];
            int price = it[2];
           
           adj[u].push_back({v , price});

        }

        vector<vector<int>>cheapestPath(n , vector<int>(k+2 , 1e9));

        cheapestPath[src][0]=0;

        priority_queue<tuple<int , int , int> , vector<tuple<int , int , int>> , greater<>>pq;

        pq.push({0, src , 0});



        while(!pq.empty()) {       
        
         auto[ cost , node , stops] = pq.top();

         pq.pop();

         if(node == dst) return cost;

         if(stops > k ) continue;

         if (cost > cheapestPath[node][stops]) continue;

           for (auto [next , price] : adj[node]) {

               int totalCost = cost + price;  
                
               if( totalCost < cheapestPath[next][stops+1]) {

                 cheapestPath[next][stops+1] = totalCost;
                
                  pq.push({totalCost , next , stops+1});

               }

             
            }


          }
         

  
    return -1;

    }


};