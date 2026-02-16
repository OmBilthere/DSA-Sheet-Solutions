class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      
       int n = grid.size();

       if(grid[0][0]== 1 || grid[n-1][n-1]== 1) return -1;

        queue<pair<int,pair<int,int>>>q;

        q.push( {1 , { 0,0 } } );      

        grid[0][0] = 1;

        while(!q.empty()) {
            
            auto [dis , cell ] = q.front();

            auto [row , col ] = cell;

            q.pop();

            if(row == n-1 && col == n-1 ) return dis;

            for(int i=-1 ; i<2; i++) {

                for(int j =-1; j<2 ; j++) {

                    if(i==0 && j==0) continue;

                    int nrow = row+i;
                    int ncol = col+j;
                   
                   if(  nrow >= 0 && nrow < n && ncol >=0 &&  ncol < n && grid[nrow][ncol] == 0 )  {

                   q.push({ dis+1, {nrow , ncol}}) ;
                   
                   grid[nrow][ncol] = 1;

                   }
                   

                }
            }

        }

        return -1;
       
    }
};


// more clean code

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      
       int n = grid.size();

       if(grid[0][0]== 1 || grid[n-1][n-1]== 1) return -1;

        queue<pair<int,int>>q;

        q.push(  { 0, 0 } );      

        grid[0][0] = 1;

        int dis = 1;

        while(!q.empty()) { 

            
           int size = q.size();   
           
          for(int k = 0 ; k < size ; k++ ) {
            
            auto [row , col ] = q.front();

            q.pop();

            if(row == n-1 && col == n-1 ) return dis;

            for(int i=-1 ; i<2; i++) {

                for(int j =-1; j<2 ; j++) {

                    if(i==0 && j==0) continue;

                    int nrow = row+i;

                    int ncol = col+j;
                   
                   if(  nrow >= 0 && nrow < n && ncol >=0 &&  ncol < n && grid[nrow][ncol] == 0 )  {

                   q.push({nrow , ncol}) ;
                   
                   grid[nrow][ncol] = 1;

                 }      

              }

            }

          }
             dis++;

        }

        return -1;
       
    }
};