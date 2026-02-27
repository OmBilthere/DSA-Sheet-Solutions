class Solution {
public:
    int numIslands(vector<vector<char>>& grid) { 
        
     
        int n  = grid.size();

        int m = grid[0].size();

        vector<vector<int>>vis(n , vector<int>(m , 0));

        vector<int>dx = { 1 , -1 , 0 , 0 };

        vector<int>dy = { 0 , 0 , 1 , -1 };

        int cnt = 0;

        for(int i= 0 ; i< n ; i++ ) {

            for(int j=0 ; j< m ; j++ ) {   
                   
                if(!vis[i][j] && grid[i][j] == '1') { 

                    queue<pair<int,int>>q;

                    q.push({i , j}); 

                    vis[i][j] = 1;

                    while(!q.empty()) {

                        auto [x , y ] = q.front();

                        q.pop();

                        for(int i = 0 ; i< 4 ; i++ ) {

                            int row = x + dx[i];
                            int col = y + dy[i];

                            if(row >= 0 && col >= 0 && row < n && col < m &&  grid[row][col] == '1' && vis[row][col] == 0 ) {

                                q.push({row , col });

                                vis[row][col] = 1;
                            }
                        }
    
                        
                    }

                    cnt++;

                }
            }
        }
        
        return cnt;
        
    }
};