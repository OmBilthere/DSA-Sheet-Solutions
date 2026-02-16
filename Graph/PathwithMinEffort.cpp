class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();

        int m = heights[0].size();

        priority_queue<pair<int ,pair<int , int>>, vector<pair<int , pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>dist(n , vector<int>(m , 1e9));

        dist[0][0] = 0;

        pq.push({ 0, { 0 , 0}});

        vector<int>dx = { 0 , 0 , 1 , -1};

        vector<int>dy= { 1 , -1 , 0 , 0};

        while(!pq.empty()) {

           auto[effort, it ] = pq.top();

           auto [row , col ] = it;  
        
           pq.pop();
           
           if (effort > dist[row][col]) continue;

           if(row == n-1 && col == m-1)  return effort;  

           for(int i = 0 ; i<4 ; i++ ) {

             int x = row+dx[i];

             int y = col+dy[i];
             
             if(x>=0 && y>=0 && x<n && y<m) {

               int diff =  abs( heights[row][col] - heights[x][y]);
               
               int nextEffort = max(effort , diff);

               if(nextEffort < dist[x][y])  {

                dist[x][y] = nextEffort;
              
               pq.push({ nextEffort, {x , y}});
               
        
            }

            
         }
             
               
       } 

 
     }

    

      return 0;

    }
};